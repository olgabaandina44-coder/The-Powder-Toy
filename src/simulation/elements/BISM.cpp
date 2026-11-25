#include "simulation/ElementCommon.h"

void Element::Element_BISM()
{
	Identifier = "DEFAULT_PT_BISM";
	Name = "BISM";
	Colour = 0x9E8FA6_rgb;
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

	HeatConduct = 25;
	Description = "Bismuth (Z=83). Diamagnetic heavy metal with iridescent oxide crystals and very low thermal conductivity, melts at 271.5C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 544.7f;
	HighTemperatureTransition = PT_LAVA;
}
