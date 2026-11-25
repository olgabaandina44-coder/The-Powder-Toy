#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_FLER()
{
	Identifier = "DEFAULT_PT_FLER";
	Name = "FLER";
	Colour = 0x5D4A5A_rgb;
	MenuVisible = 1;
	MenuSection = SC_RADIOACTIVE;
	Enabled = 1;

	Advection = 0.3f;
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

	Weight = 92;

	HeatConduct = 60;
	Description = "Flerovium (Z=114). Superheavy island-of-stability element synthesized in Dubna; volatile liquid decaying with neutron bursts.";

	Properties = TYPE_LIQUID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 380.0f;
	HighTemperatureTransition = PT_GAS;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 12))
	{
		parts[i].temp += 780.0f;
		sim->pv[y / CELL][x / CELL] += 3.8f;
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
