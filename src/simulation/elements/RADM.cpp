#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_RADM()
{
	Identifier = "DEFAULT_PT_RADM";
	Name = "RADM";
	Colour = 0x7CE89E_rgb;
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
	Hardness = 5;

	Weight = 98;

	HeatConduct = 70;
	Description = "Radium (Z=88). Radioluminescent alkaline earth metal discovered by Marie Curie; glows green and decays into radon gas.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 973.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
	Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 140))
	{
		parts[i].temp += 22.0f;
		if (!sim->photons[y][x] && sim->rng.chance(1, 3))
			sim->create_part(-3, x, y, PT_PROT);
		if (sim->rng.chance(1, 25))
		{
			sim->part_change_type(i, x, y, PT_RADN);
			return 1;
		}
	}
	return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
	*colr = 124;
	*colg = 232;
	*colb = 158;
	*firea = 35;
	*firer = 90;
	*fireg = 240;
	*fireb = 140;
	*pixel_mode |= PMODE_GLOW;
	return 0;
}
