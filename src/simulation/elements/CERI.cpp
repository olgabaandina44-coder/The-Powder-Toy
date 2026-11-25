#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_CERI()
{
	Identifier = "DEFAULT_PT_CERI";
	Name = "CERI";
	Colour = 0x9BA1A6_rgb;
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

	Flammable = 30;
	Explosive = 0;
	Meltable = 1;
	Hardness = 5;

	Weight = 98;

	HeatConduct = 60;
	Description = "Cerium (Z=58). Pyrophoric lanthanide metal used in lighter flints; emits sparks under sudden pressure shock.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1068.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	// Пирофорное искрение при резком скачке давления
	if (sim->pv[y / CELL][x / CELL] > 18.0f && sim->rng.chance(1, 6))
	{
		parts[i].temp += 350.0f;
		sim->part_change_type(i, x, y, PT_EMBR);
		return 1;
	}
	return 0;
}
