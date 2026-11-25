#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_CESM()
{
	Identifier = "DEFAULT_PT_CESM";
	Name = "CESM";
	Colour = 0xD4AF37_rgb;
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

	Flammable = 75;
	Explosive = 0;
	Meltable = 1;
	Hardness = 20;

	Weight = 95;

	HeatConduct = 95;
	Description = "Cesium (Z=55). Soft golden alkali metal melting at 28.5C. Explodes violently on contact with water.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 301.7f;
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
				parts[i].temp += 750.0f;
				sim->pv[y / CELL][x / CELL] += 6.0f;
				sim->part_change_type(i, x, y, PT_PLSM);
				return 1;
			}
			else if (rt == PT_CHLR || rt == PT_FLUO)
			{
				sim->part_change_type(ID(r), x + rx, y + ry, PT_SALT);
				sim->part_change_type(i, x, y, PT_SALT);
				return 1;
			}
		}
	}
	return 0;
}
