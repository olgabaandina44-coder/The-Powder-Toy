#include "simulation/ElementCommon.h"

void Element::Element_YTTR()
{
	Identifier = "DEFAULT_PT_YTTR";
	Name = "YTTR";
	Colour = 0x99A3A4_rgb;
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
	Hardness = 3;

	Weight = 97;

	HeatConduct = 85;
	Description = "Yttrium (Z=39). Transition metal used in YBCO high-temperature superconductors and lasers, melts at 1526C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1799.0f;
	HighTemperatureTransition = PT_LAVA;
}
