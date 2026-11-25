#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_HAFN()
{
	Identifier = "DEFAULT_PT_HAFN";
	Name = "HAFN";
	Colour = 0x737B82_rgb;
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
	Meltable = 1;
	Hardness = 0;

	Weight = 100;

	HeatConduct = 75;
	Description = "Hafnium (Z=72). Corrosion-proof refractory metal with extreme neutron capture cross-section for naval reactor rods, melts at 2233C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2506.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	for (int ry = -2; ry <= 2; ry++)
	{
		int ny = y + ry;
		if (ny < CELL || ny >= YRES - CELL)
			continue;
		for (int rx = -2; rx <= 2; rx++)
		{
			int nx = x + rx;
			if (nx < CELL || nx >= XRES - CELL)
				continue;
			unsigned int ph = sim->photons[ny][nx];
			if (ph && TYP(ph) == PT_NEUT)
			{
				sim->kill_part(ID(ph));
				parts[i].temp += 30.0f;
			}
		}
	}
	return 0;
}
