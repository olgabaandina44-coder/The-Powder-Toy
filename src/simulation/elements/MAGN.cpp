#include "simulation/ElementCommon.h"

void Element::Element_MAGN()
{
	Identifier = "DEFAULT_PT_MAGN";
	Name = "MAGN";
	Colour = 0xD8DDE6_rgb;
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

	Flammable = 15;
	Explosive = 0;
	Meltable = 1;
	Hardness = 3;

	Weight = 94;

	HeatConduct = 175;
	Description = "Magnesium (Z=12). Light structural metal, burns with intense white flame at high temperatures.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 923.0f;
	HighTemperatureTransition = PT_LAVA;
}
