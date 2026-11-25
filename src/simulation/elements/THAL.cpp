#include "simulation/ElementCommon.h"

void Element::Element_THAL()
{
	Identifier = "DEFAULT_PT_THAL";
	Name = "THAL";
	Colour = 0x7A8085_rgb;
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

	Weight = 100;

	HeatConduct = 95;
	Description = "Thallium (Z=81). Soft heavy post-transition metal used in infrared optics, melts at 304C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 577.0f;
	HighTemperatureTransition = PT_LAVA;
}
