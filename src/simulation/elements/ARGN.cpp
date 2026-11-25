#include "simulation/ElementCommon.h"

void Element::Element_ARGN()
{
	Identifier = "DEFAULT_PT_ARGN";
	Name = "ARGN";
	Colour = 0xA688FA_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.05f;
	Diffusion = 0.70f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 5;

	HeatConduct = 25;
	Description = "Argon (Z=18). Heavy inert noble gas used as shielding atmosphere in metallurgy. Boils at 87.3 K.";

	Properties = TYPE_GAS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 87.30f;
	LowTemperatureTransition = PT_LAVA;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;
}
