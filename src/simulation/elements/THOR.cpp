#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_THOR()
{
	Identifier = "DEFAULT_PT_THOR";
	Name = "THOR";
	Colour = 0x565C54_rgb;
	MenuVisible = 1;
	MenuSection = SC_RADIOACTIVE;
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
	Hardness = 2;

	Weight = 100;

	HeatConduct = 110;
	Description = "Thorium (Z=90). Fertile nuclear fuel metal; absorbs neutrons to breed fissile Uranium fuel, melts at 1750C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2023.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	// Ториевый топливный цикл: 232Th + n -> 233U (URAN)
	for (int ry = -1; ry <= 1; ry++)
	{
		for (int rx = -1; rx <= 1; rx++)
		{
			unsigned int ph = sim->photons[y + ry][x + rx];
			if (ph && TYP(ph) == PT_NEUT)
			{
				sim->kill_part(ID(ph));
				parts[i].temp += 40.0f;
				if (sim->rng.chance(1, 3))
				{
					sim->part_change_type(i, x, y, PT_URAN);
					return 1;
				}
			}
		}
	}
	return 0;
}
