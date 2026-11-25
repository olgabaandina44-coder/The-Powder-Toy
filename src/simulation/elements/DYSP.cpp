#include "simulation/ElementCommon.h"

void Element::Element_DYSP()
{
	Identifier = "DEFAULT_PT_DYSP";
	Name = "DYSP";
	Colour = 0x8A9096_rgb;
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

	Weight = 99;

	HeatConduct = 55;
	Description = "Dysprosium (Z=66). High-magnetic-susceptibility lanthanide used in nuclear control rods and EV motors, melts at 1407C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1680.0f;
	HighTemperatureTransition = PT_LAVA;
}
