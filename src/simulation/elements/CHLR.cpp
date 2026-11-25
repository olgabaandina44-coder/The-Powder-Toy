#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_CHLR()
{
	Identifier = "DEFAULT_PT_CHLR";
	Name = "CHLR";
	Colour = 0xA8C850_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.12f;
	Diffusion = 0.65f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 6;

	HeatConduct = 25;
	Description = "Chlorine (Z=17). Dense yellow-green halogen gas. Reacts with hydrogen under light to form acid (HCl).";

	Properties = TYPE_GAS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 239.11f;
	LowTemperatureTransition = PT_ACID;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	bool hasLight = (sim->photons[y][x] != 0);
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
			if (rt == PT_H2 && (hasLight || parts[i].temp > 450.0f))
			{
				sim->part_change_type(ID(r), x + rx, y + ry, PT_ACID);
				sim->part_change_type(i, x, y, PT_ACID);
				parts[i].temp += 180.0f;
				return 1;
			}
			else if (rt == PT_WATR && sim->rng.chance(1, 25))
			{
				sim->part_change_type(i, x, y, PT_ACID);
				return 1;
			}
		}
	}
	return 0;
}
