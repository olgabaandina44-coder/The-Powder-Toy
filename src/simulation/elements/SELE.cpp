#include "simulation/ElementCommon.h"

void Element::Element_SELE()
{
	Identifier = "DEFAULT_PT_SELE";
	Name = "SELE";
	Colour = 0x8C4A4A_rgb;
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

	Weight = 97;

	HeatConduct = 45;
	Description = "Selenium (Z=34). Photoconductive nonmetal used in solar cells and glassmaking, melts at 221C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 494.0f;
	HighTemperatureTransition = PT_LAVA;
}
