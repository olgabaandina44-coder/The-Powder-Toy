#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_BROM()
{
	Identifier = "DEFAULT_PT_BROM";
	Name = "BROM";
	Colour = 0x8B2500_rgb;
	MenuVisible = 1;
	MenuSection = SC_LIQUID;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.02f * CFDS;
	AirLoss = 0.98f;
	Loss = 0.80f;
	Collision = 0.0f;
	Gravity = 0.35f;
	Diffusion = 0.00f;
	HotAir = 0.000f * CFDS;
	Falldown = 2;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 75;

	HeatConduct = 30;
	Description = "Bromine (Z=35). Fuming red-brown liquid halogen at room temperature. Boils at 58.8C.";

	Properties = TYPE_LIQUID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 265.8f;
	LowTemperatureTransition = PT_ICEI;
	HighTemperature = 332.0f;
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
			if (rt == PT_SODM || rt == PT_POTA)
			{
				sim->part_change_type(ID(r), x + rx, y + ry, PT_SALT);
				sim->part_change_type(i, x, y, PT_SALT);
				parts[i].temp += 280.0f;
				return 1;
			}
			else if (rt == PT_H2 && parts[i].temp > 420.0f)
			{
				sim->part_change_type(ID(r), x + rx, y + ry, PT_ACID);
				sim->part_change_type(i, x, y, PT_ACID);
				return 1;
			}
		}
	}
	return 0;
}
