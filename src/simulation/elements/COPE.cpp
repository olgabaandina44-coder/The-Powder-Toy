#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_COPE()
{
	Identifier = "DEFAULT_PT_COPE";
	Name = "COPE";
	Colour = 0x635060_rgb;
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

	Weight = 90;

	HeatConduct = 60;
	Description = "Copernicium (Z=112). Volatile superheavy mercury homologue predicted to be liquid/gas at room temperature; decays rapidly.";

	Properties = TYPE_LIQUID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 340.0f;
	HighTemperatureTransition = PT_GAS;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 11))
	{
		parts[i].temp += 700.0f;
		sim->pv[y / CELL][x / CELL] += 3.2f;
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
