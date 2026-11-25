#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_SODM()
{
	Identifier = "DEFAULT_PT_SODM";
	Name = "SODM";
	Colour = 0xC8CDD4_rgb;
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

	Flammable = 40;
	Explosive = 0;
	Meltable = 1;
	Hardness = 15;

	Weight = 92;

	HeatConduct = 180;
	Description = "Sodium (Z=11). Soft alkali metal. Reacts violently with water releasing hydrogen gas.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 370.95f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
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
				parts[ID(r)].temp += 350.0f;
				parts[i].temp += 450.0f;
				sim->pv[y / CELL][x / CELL] += 2.5f;
				sim->part_change_type(i, x, y, PT_FIRE);
				return 1;
			}
			else if (rt == PT_FLUO || rt == PT_CHLR)
			{
				sim->part_change_type(ID(r), x + rx, y + ry, PT_SALT);
				sim->part_change_type(i, x, y, PT_SALT);
				parts[i].temp += 300.0f;
				return 1;
			}
		}
	}
	return 0;
}
