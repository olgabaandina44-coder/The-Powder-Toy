#include "simulation/ElementCommon.h"

void Element::Element_SILV()
{
	Identifier = "DEFAULT_PT_SILV";
	Name = "SILV";
	Colour = 0xDCE2E8_rgb;
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
	Hardness = 2;

	Weight = 99;

	HeatConduct = 250;
	Description = "Silver (Z=47). Highest electrical and thermal conductivity of any metal, melts at 961.8C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1234.93f;
	HighTemperatureTransition = PT_LAVA;
}
