#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_EURO()
{
	Identifier = "DEFAULT_PT_EURO";
	Name = "EURO";
	Colour = 0xA39E98_rgb;
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

	Flammable = 25;
	Explosive = 0;
	Meltable = 1;
	Hardness = 7;

	Weight = 98;

	HeatConduct = 60;
	Description = "Europium (Z=63). Most chemically reactive lanthanide; reacts with water to release hydrogen, melts at 826C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1099.0f;
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
				if (sim->rng.chance(1, 5))
				{
					sim->part_change_type(ID(r), x + rx, y + ry, PT_H2);
					parts[i].temp += 180.0f;
					sim->part_change_type(i, x, y, PT_STNE);
					return 1;
				}
			}
		}
	}
	return 0;
}
