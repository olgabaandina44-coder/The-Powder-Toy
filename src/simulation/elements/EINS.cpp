#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_EINS()
{
	Identifier = "DEFAULT_PT_EINS";
	Name = "EINS";
	Colour = 0x6E828A_rgb;
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
	Hardness = 4;

	Weight = 100;

	HeatConduct = 55;
	Description = "Einsteinium (Z=99). Intensely radioactive actinide discovered in thermonuclear test debris; self-heats and glows blue, melts at 860C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1133.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 70))
	{
		parts[i].temp += 65.0f;
		if (!sim->photons[y][x] && sim->rng.chance(1, 2))
			sim->create_part(-3, x, y, PT_PROT);
	}
	return 0;
}
