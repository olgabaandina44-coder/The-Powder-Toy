#include "simulation/ElementCommon.h"

void Element::Element_LANT()
{
	Identifier = "DEFAULT_PT_LANT";
	Name = "LANT";
	Colour = 0xA2AAB0_rgb;
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
	Hardness = 4;

	Weight = 98;

	HeatConduct = 65;
	Description = "Lanthanum (Z=57). First lanthanide rare-earth metal used in optical lenses and NiMH batteries, melts at 920C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1193.0f;
	HighTemperatureTransition = PT_LAVA;
}
