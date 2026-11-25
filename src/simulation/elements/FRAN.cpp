#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_FRAN()
{
	Identifier = "DEFAULT_PT_FRAN";
	Name = "FRAN";
	Colour = 0x8A7A6E_rgb;
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

	Flammable = 90;
	Explosive = 0;
	Meltable = 1;
	Hardness = 25;

	Weight = 97;

	HeatConduct = 60;
	Description = "Francium (Z=87). Extremely radioactive alkali metal melting at 27C; explodes violently with water and decays rapidly.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 300.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 50))
	{
		parts[i].temp += 95.0f;
		if (!sim->photons[y][x])
			sim->create_part(-3, x, y, PT_ELEC);
		if (sim->rng.chance(1, 15))
		{
			sim->part_change_type(i, x, y, PT_RADN);
			return 1;
		}
	}

	for (int ry = -1; ry <= 1; ry++)
	{
		for (int rx = -1; rx <= 1; rx++)
		{
			if (!rx && !ry)
				continue;
			unsigned int r = pmap[y + ry][x + rx];
			if (!r)
				continue;
			int rt = TYP(r);
			if (rt == PT_WATR || rt == PT_DSTW || rt == PT_SLTW)
			{
				sim->part_change_type(ID(r), x + rx, y + ry, PT_H2);
				parts[i].temp += 900.0f;
				sim->pv[y / CELL][x / CELL] += 8.0f;
				sim->part_change_type(i, x, y, PT_PLSM);
				return 1;
			}
		}
	}
	return 0;
}
