#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_CURI()
{
	Identifier = "DEFAULT_PT_CURI";
	Name = "CURI";
	Colour = 0x828C94_rgb;
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

	HeatConduct = 55;
	Description = "Curium (Z=96). High-decay-heat transuranic actinide that glows red-purple and emits neutrons, melts at 1340C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1613.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 90))
	{
		parts[i].temp += 45.0f;
		if (!sim->photons[y][x] && sim->rng.chance(1, 3))
			sim->create_part(-3, x, y, PT_NEUT);
	}
	return 0;
}
