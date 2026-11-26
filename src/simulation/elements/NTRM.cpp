#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_QGP()
{
	Identifier = "DEFAULT_PT_QGP";
	Name = "QGP";
	Colour = 0xFF55FF_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.2f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.0f;
	Diffusion = 1.50f;
	HotAir = 0.010f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 1;
	DefaultProperties.temp = 9500.0f;

	HeatConduct = 255;
	Description = "Quark-Gluon Plasma. Extreme high-energy state of matter; hadronizes into protons, neutrons, and electrons as it cools.";

	Properties = TYPE_GAS | PROP_HOT_GLOW;

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
	sim->pv[y / CELL][x / CELL] += 1.5f;
	if (parts[i].temp < 7500.0f || sim->rng.chance(1, 35))
	{
		int r = sim->rng.between(0, 2);
		int target = (r == 0) ? PT_PROT : ((r == 1) ? PT_NEUT : PT_ELEC);
		sim->part_change_type(i, x, y, target);
		return 1;
	}
	return 0;
}
