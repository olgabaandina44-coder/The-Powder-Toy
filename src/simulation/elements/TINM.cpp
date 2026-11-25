#include "simulation/ElementCommon.h"

void Element::Element_TINM()
{
	Identifier = "DEFAULT_PT_TINM";
	Name = "TINM";
	Colour = 0xB0B6BC_rgb;
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
	Hardness = 6;

	Weight = 98;

	HeatConduct = 120;
	Description = "Tin (Z=50). Malleable post-transition metal used in solders and bronze alloys, melts at 231.9C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 505.08f;
	HighTemperatureTransition = PT_LAVA;
}
