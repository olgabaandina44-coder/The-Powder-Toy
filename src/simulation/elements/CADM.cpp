#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_CADM()
{
	Identifier = "DEFAULT_PT_CADM";
	Name = "CADM";
	Colour = 0x8A959E_rgb;
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
	Hardness = 5;

	Weight = 99;

	HeatConduct = 140;
	Description = "Cadmium (Z=48). Soft bluish-white metal with extreme thermal neutron capture cross-section for reactor control rods.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 594.22f;
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
				parts[i].temp += 28.0f;
			}
		}
	}
	return 0;
}
