#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_ZIRC()
{
	Identifier = "DEFAULT_PT_ZIRC";
	Name = "ZIRC";
	Colour = 0x8E9B9E_rgb;
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

	Weight = 98;

	HeatConduct = 95;
	Description = "Zirconium (Z=40). Neutron-transparent nuclear cladding metal. Reacts with steam above 1200C to release hydrogen.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2128.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (parts[i].temp > 1473.15f)
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
				if (rt == PT_WATR || rt == PT_WTRV || rt == PT_DSTW)
				{
					if (sim->rng.chance(1, 10))
					{
						sim->part_change_type(ID(r), x + rx, y + ry, PT_H2);
						parts[i].temp += 220.0f;
						sim->part_change_type(i, x, y, PT_STNE);
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
