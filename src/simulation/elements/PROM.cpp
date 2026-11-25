#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_PROM()
{
	Identifier = "DEFAULT_PT_PROM";
	Name = "PROM";
	Colour = 0x789E8C_rgb;
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

	Weight = 98;

	HeatConduct = 65;
	Description = "Promethium (Z=61). Exclusively radioactive lanthanide metal used in betavoltaic nuclear batteries, melts at 1042C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1315.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 220))
	{
		parts[i].temp += 12.0f;
		if (!sim->photons[y][x] && sim->rng.chance(1, 4))
		{
			sim->create_part(-3, x, y, PT_ELEC);
		}
	}
	return 0;
}
