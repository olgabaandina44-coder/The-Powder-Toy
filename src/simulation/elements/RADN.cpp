#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_RADN()
{
	Identifier = "DEFAULT_PT_RADN";
	Name = "RADN";
	Colour = 0x78C896_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.18f;
	Diffusion = 0.55f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 9;

	HeatConduct = 15;
	Description = "Radon (Z=86). Heavy radioactive noble gas produced by radium decay; decays into solid polonium.";

	Properties = TYPE_GAS | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 211.3f;
	LowTemperatureTransition = PT_LAVA;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 180))
	{
		parts[i].temp += 25.0f;
		if (!sim->photons[y][x])
			sim->create_part(-3, x, y, PT_PROT);
		if (sim->rng.chance(1, 12))
		{
			sim->part_change_type(i, x, y, PT_POLO);
			return 1;
		}
	}
	return 0;
}
