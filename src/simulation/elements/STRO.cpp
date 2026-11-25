#include "simulation/ElementCommon.h"

void Element::Element_STRO()
{
	Identifier = "DEFAULT_PT_STRO";
	Name = "STRO";
	Colour = 0xC9C2B2_rgb;
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

	Flammable = 20;
	Explosive = 0;
	Meltable = 1;
	Hardness = 6;

	Weight = 96;

	HeatConduct = 100;
	Description = "Strontium (Z=38). Soft alkaline earth metal, burns with crimson flame and melts at 777C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1050.0f;
	HighTemperatureTransition = PT_LAVA;
}
