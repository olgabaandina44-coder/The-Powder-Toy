#include "simulation/ElementCommon.h"

void Element::Element_SULF()
{
	Identifier = "DEFAULT_PT_SULF";
	Name = "SULF";
	Colour = 0xE6D245_rgb;
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

	Flammable = 60;
	Explosive = 0;
	Meltable = 1;
	Hardness = 8;

	Weight = 94;

	HeatConduct = 30;
	Description = "Sulfur (Z=16). Yellow multivalent nonmetal, melts at 115.2C and burns with a blue flame.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 388.36f;
	HighTemperatureTransition = PT_LAVA;
}
