#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_OGAN()
{
	Identifier = "DEFAULT_PT_OGAN";
	Name = "OGAN";
	Colour = 0x513E4E_rgb;
	MenuVisible = 1;
	MenuSection = SC_RADIOACTIVE;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.25f;
	Diffusion = 0.50f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 12;

	HeatConduct = 30;
	Description = "Oganesson (Z=118). Heaviest known element on the periodic table; undergoes sub-millisecond alpha decay burst.";

	Properties = TYPE_GAS | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 325.0f;
	LowTemperatureTransition = PT_LAVA;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 6))
	{
		parts[i].temp += 950.0f;
		sim->pv[y / CELL][x / CELL] += 5.0f;
		if (!sim->photons[y][x])
			sim->create_part(-3, x, y, PT_NEUT);
		sim->part_change_type(i, x, y, PT_LEAD);
		return 1;
	}
	return 0;
}
