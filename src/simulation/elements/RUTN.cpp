#include "simulation/ElementCommon.h"

void Element::Element_RUTN()
{
	Identifier = "DEFAULT_PT_RUTN";
	Name = "RUTN";
	Colour = 0x8B9196_rgb;
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

	HeatConduct = 150;
	Description = "Ruthenium (Z=44). Rare platinum-group noble metal, immune to acids and melts at 2334C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2607.0f;
	HighTemperatureTransition = PT_LAVA;
}
