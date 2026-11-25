#include "simulation/ElementCommon.h"

void Element::Element_CHRM()
{
	Identifier = "DEFAULT_PT_CHRM";
	Name = "CHRM";
	Colour = 0xC4CED4_rgb;
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
	Hardness = 1;

	Weight = 98;

	HeatConduct = 140;
	Description = "Chromium (Z=24). Lustrous, hard transition metal used in stainless steel, melts at 1907C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2180.0f;
	HighTemperatureTransition = PT_LAVA;
}
