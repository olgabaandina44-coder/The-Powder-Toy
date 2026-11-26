#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_NTRM()
{
	Identifier = "DEFAULT_PT_NTRM";
	Name = "NTRM";
	Colour = 0xD0E4FF_rgb;
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

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 100;

	HeatConduct = 255;
	Description = "Neutronium. Ultra-dense degenerate nuclear matter from neutron stars; generates intense local gravity.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	sim->gravIn.mass[y / CELL][x / CELL] += 12.0f;
	if (sim->rng.chance(1, 250) && !sim->photons[y][x])
	{
		sim->create_part(-3, x, y, PT_NEUT);
	}
	return 0;
}
