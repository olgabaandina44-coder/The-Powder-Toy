#include "simulation/ElementCommon.h"

void Element::Element_GALL()
{
	Identifier = "DEFAULT_PT_GALL";
	Name = "GALL";
	Colour = 0xA8B5C2_rgb;
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

	Weight = 98;

	HeatConduct = 100;
	Description = "Gallium (Z=31). Soft silvery metal that melts in the human hand at 29.76C (302.91 K).";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 302.91f;
	HighTemperatureTransition = PT_LAVA;
}
