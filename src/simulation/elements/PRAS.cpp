#include "simulation/ElementCommon.h"

void Element::Element_PRAS()
{
	Identifier = "DEFAULT_PT_PRAS";
	Name = "PRAS";
	Colour = 0x93A398_rgb;
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
	Hardness = 4;

	Weight = 98;

	HeatConduct = 60;
	Description = "Praseodymium (Z=59). Soft silvery lanthanide used in aircraft engine alloys and welder goggles, melts at 935C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1208.0f;
	HighTemperatureTransition = PT_LAVA;
}
