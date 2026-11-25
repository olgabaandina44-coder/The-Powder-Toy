#include "simulation/ElementCommon.h"

void Element::Element_NEON()
{
	Identifier = "DEFAULT_PT_NEON";
	Name = "NEON";
	Colour = 0xFF6E4A_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = -0.05f;
	Diffusion = 0.80f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 3;

	HeatConduct = 50;
	Description = "Neon (Z=10). Noble gas with bright reddish-orange emission spectrum. Boils at 27.07 K.";

	Properties = TYPE_GAS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 27.07f;
	LowTemperatureTransition = PT_LAVA;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;
}
