#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_IODN()
{
	Identifier = "DEFAULT_PT_IODN";
	Name = "IODN";
	Colour = 0x4B2E5E_rgb;
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
	Meltable = 0;
	Hardness = 8;

	Weight = 97;

	HeatConduct = 25;
	Description = "Iodine (Z=53). Dark-violet halogen crystal that sublimates directly into purple vapor when heated above 113.7C.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 386.85f;
	HighTemperatureTransition = PT_GAS;

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
			if (rt == PT_SODM || rt == PT_POTA || rt == PT_CESM)
			{
				sim->part_change_type(ID(r), x + rx, y + ry, PT_SALT);
				sim->part_change_type(i, x, y, PT_SALT);
				return 1;
			}
		}
	}
	return 0;
}
