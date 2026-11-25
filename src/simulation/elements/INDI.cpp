#include "simulation/ElementCommon.h"

void Element::Element_INDI()
{
	Identifier = "DEFAULT_PT_INDI";
	Name = "INDI";
	Colour = 0x9BA4B0_rgb;
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
	Hardness = 8;

	Weight = 98;

	HeatConduct = 130;
	Description = "Indium (Z=49). Ultra-soft silvery metal used in cryogenic vacuum seals and touchscreens, melts at 156.6C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 429.75f;
	HighTemperatureTransition = PT_LAVA;
}
