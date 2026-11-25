#include "simulation/ElementCommon.h"

void Element::Element_NICK()
{
	Identifier = "DEFAULT_PT_NICK";
	Name = "NICK";
	Colour = 0xA6A89E_rgb;
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

	HeatConduct = 140;
	Description = "Nickel (Z=28). Corrosion-resistant ferromagnetic metal, melts at 1455C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1728.0f;
	HighTemperatureTransition = PT_LAVA;
}
