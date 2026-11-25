#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_BORN()
{
	Identifier = "DEFAULT_PT_BORN";
	Name = "BORN";
	Colour = 0x4A444F_rgb;
	MenuVisible = 1;
	MenuSection = SC_SOLIDS;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 1;
	Hardness = 0;

	Weight = 100;

	HeatConduct = 140;
	Description = "Boron. High-melting metalloid that absorbs neutrons (control rods) and alloys with molten iron into superalloy.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2349.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	// Захват нейтронов по реакции 10B(n, alpha)7Li
	for (int ry = -2; ry <= 2; ry++)
	{
		int ny = y + ry;
		if (ny < CELL || ny >= YRES - CELL)
			continue;
		for (int rx = -2; rx <= 2; rx++)
		{
			int nx = x + rx;
			if (nx < CELL || nx >= XRES - CELL)
				continue;

			unsigned int ph = sim->photons[ny][nx];
			if (ph && TYP(ph) == PT_NEUT)
			{
				sim->kill_part(ID(ph));
				parts[i].temp += 35.0f;
				if (!pmap[ny][nx] && sim->rng.chance(1, 8))
				{
					sim->create_part(-1, nx, ny, PT_NBLE);
				}
			}

			// Легирование: бор + расплавленное железо/металл -> суперсплав (ALOY)
			if (abs(rx) <= 1 && abs(ry) <= 1 && (rx || ry))
			{
				unsigned int r = pmap[ny][nx];
				if (r && TYP(r) == PT_LAVA)
				{
					int meltType = parts[ID(r)].ctype;
					if (meltType == PT_IRON || meltType == PT_METL || meltType == PT_BMTL)
					{
						if (sim->rng.chance(1, 12))
						{
							parts[ID(r)].ctype = PT_ALOY;
							if (sim->rng.chance(1, 3))
							{
								sim->part_change_type(i, x, y, PT_LAVA);
								parts[i].ctype = PT_ALOY;
								return 1;
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
