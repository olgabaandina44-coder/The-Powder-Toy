#include "simulation/ElementCommon.h"

void Element::Element_ZINC()
{
	Identifier = "DEFAULT_PT_ZINC";
	Name = "ZINC";
	Colour = 0x9BA6B0_rgb;
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
	Hardness = 6;

	Weight = 98;

	HeatConduct = 155;
	Description = "Zinc (Z=30). Bluish-white corrosion-protective metal used in galvanizing, melts at 419.5C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 692.68f;
	HighTemperatureTransition = PT_LAVA;
}
