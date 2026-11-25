#include "simulation/ElementCommon.h"

void Element::Element_NEOD()
{
	Identifier = "DEFAULT_PT_NEOD";
	Name = "NEOD";
	Colour = 0x8D99A6_rgb;
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

	Flammable = 5;
	Explosive = 0;
	Meltable = 1;
	Hardness = 4;

	Weight = 98;

	HeatConduct = 65;
	Description = "Neodymium (Z=60). Rare-earth lanthanide used in the strongest permanent magnets (NdFeB), melts at 1024C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1297.0f;
	HighTemperatureTransition = PT_LAVA;
}
