#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_NIHO()
{
	Identifier = "DEFAULT_PT_NIHO";
	Name = "NIHO";
	Colour = 0x604D5D_rgb;
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

	Flammable = 0;
	Explosive = 0;
	Meltable = 1;
	Hardness = 3;

	Weight = 100;

	HeatConduct = 60;
	Description = "Nihonium (Z=113). Superheavy post-transition element; undergoes rapid alpha decay chain with extreme energy release.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 700.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 10))
	{
		parts[i].temp += 740.0f;
		sim->pv[y / CELL][x / CELL] += 3.5f;
		if (!sim->photons[y][x])
			sim->create_part(-3, x, y, PT_NEUT);
		if (sim->rng.chance(1, 3))
		{
			sim->part_change_type(i, x, y, PT_LEAD);
			return 1;
		}
	}
	return 0;
}
