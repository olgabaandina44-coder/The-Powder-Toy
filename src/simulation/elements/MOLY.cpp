#include "simulation/ElementCommon.h"

void Element::Element_MOLY()
{
	Identifier = "DEFAULT_PT_MOLY";
	Name = "MOLY";
	Colour = 0x6E7B8B_rgb;
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

	Weight = 99;

	HeatConduct = 170;
	Description = "Molybdenum (Z=42). Ultra-refractory silvery metal with very low thermal expansion, melts at 2623C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2896.0f;
	HighTemperatureTransition = PT_LAVA;
}
