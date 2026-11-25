#include "simulation/ElementCommon.h"

void Element::Element_TELL()
{
	Identifier = "DEFAULT_PT_TELL";
	Name = "TELL";
	Colour = 0x8A8D8F_rgb;
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

	HeatConduct = 40;
	Description = "Tellurium (Z=52). Rare semiconductor metalloid used in solar panels and thermoelectric generators, melts at 449.5C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 722.66f;
	HighTemperatureTransition = PT_LAVA;
}
