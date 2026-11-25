#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_PALL()
{
	Identifier = "DEFAULT_PT_PALL";
	Name = "PALL";
	Colour = 0xB8BDC2_rgb;
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

	Weight = 100;

	HeatConduct = 130;
	Description = "Palladium (Z=46). Hydrogen-absorbing noble catalyst that combines H2 and O2 into water.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1828.05f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	int h2X = 0, h2Y = 0, o2X = 0, o2Y = 0;
	unsigned int h2R = 0, o2R = 0;

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
			if (rt == PT_H2)
			{
				h2R = r;
				h2X = x + rx;
				h2Y = y + ry;
			}
			else if (rt == PT_O2)
			{
				o2R = r;
				o2X = x + rx;
				o2Y = y + ry;
			}
		}
	}

	if (h2R && o2R)
	{
		sim->part_change_type(ID(h2R), h2X, h2Y, PT_WATR);
		sim->kill_part(ID(o2R));
		parts[i].temp += 65.0f;
	}
	return 0;
}
