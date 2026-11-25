#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_ROEN()
{
	Identifier = "DEFAULT_PT_ROEN";
	Name = "ROEN";
	Colour = 0x665363_rgb;
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
	Hardness = 2;

	Weight = 100;

	HeatConduct = 60;
	Description = "Roentgenium (Z=111). Superheavy gold homologue; undergoes ultrafast alpha and fission decay.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2600.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 12))
	{
		parts[i].temp += 660.0f;
		sim->pv[y / CELL][x / CELL] += 3.0f;
		if (!sim->photons[y][x])
			sim->create_part(-3, x, y, PT_NEUT);
		if (sim->rng.chance(1, 4))
		{
			sim->part_change_type(i, x, y, PT_LEAD);
			return 1;
		}
	}
	return 0;
}
