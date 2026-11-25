#include "simulation/ElementCommon.h"

void Element::Element_CALC()
{
	Identifier = "DEFAULT_PT_CALC";
	Name = "CALC";
	Colour = 0xD2D4CE_rgb;
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

	Flammable = 10;
	Explosive = 0;
	Meltable = 1;
	Hardness = 5;

	Weight = 94;

	HeatConduct = 160;
	Description = "Calcium (Z=20). Reactive alkaline earth metal, melts at 842C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1115.0f;
	HighTemperatureTransition = PT_LAVA;
}
