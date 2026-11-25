#include "simulation/ElementCommon.h"

void Element::Element_GERM()
{
	Identifier = "DEFAULT_PT_GERM";
	Name = "GERM";
	Colour = 0x7D848A_rgb;
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

	Weight = 97;

	HeatConduct = 115;
	Description = "Germanium (Z=32). Lustrous semiconductor metalloid used in fiber optics and infrared lenses, melts at 938.2C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1211.4f;
	HighTemperatureTransition = PT_LAVA;
}
