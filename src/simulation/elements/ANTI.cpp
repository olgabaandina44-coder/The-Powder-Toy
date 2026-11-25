#include "simulation/ElementCommon.h"

void Element::Element_ANTI()
{
	Identifier = "DEFAULT_PT_ANTI";
	Name = "ANTI";
	Colour = 0x7E858C_rgb;
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
	Hardness = 4;

	Weight = 98;

	HeatConduct = 70;
	Description = "Antimony (Z=51). Brittle lustrous metalloid used in flame retardants and semiconductors, melts at 630.6C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 903.78f;
	HighTemperatureTransition = PT_LAVA;
}
