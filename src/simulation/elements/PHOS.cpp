#include "simulation/ElementCommon.h"

void Element::Element_PHOS()
{
	Identifier = "DEFAULT_PT_PHOS";
	Name = "PHOS";
	Colour = 0xC84B31_rgb;
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

	Flammable = 85;
	Explosive = 0;
	Meltable = 1;
	Hardness = 10;

	Weight = 93;

	HeatConduct = 40;
	Description = "Phosphorus (Z=15). Reactive nonmetal, ignites easily in air and melts at 44.1C.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 317.3f;
	HighTemperatureTransition = PT_LAVA;
}
