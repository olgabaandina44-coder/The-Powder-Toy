#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_FLUO()
{
	Identifier = "DEFAULT_PT_FLUO";
	Name = "FLUO";
	Colour = 0xD4E868_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.08f;
	Diffusion = 0.70f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 5;

	HeatConduct = 35;
	Description = "Fluorine (Z=9). Most chemically reactive halogen gas. Forms hydrofluoric acid with hydrogen or water.";

	Properties = TYPE_GAS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 85.03f;
	LowTemperatureTransition = PT_ACID;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;

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
			if (rt == PT_H2 || rt == PT_WATR || rt == PT_DSTW)
			{
				sim->part_change_type(ID(r), x + rx, y + ry, PT_ACID);
				sim->part_change_type(i, x, y, PT_ACID);
				parts[i].temp += 250.0f;
				return 1;
			}
		}
	}
	return 0;
}
