#include "simulation/ElementCommon.h"

void Element::Element_SCAN()
{
	Identifier = "DEFAULT_PT_SCAN";
	Name = "SCAN";
	Colour = 0xAEB6BF_rgb;
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

	HeatConduct = 90;
	Description = "Scandium (Z=21). Silvery-white rare earth transition metal used in aerospace alloys, melts at 1541C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1814.0f;
	HighTemperatureTransition = PT_LAVA;
}
