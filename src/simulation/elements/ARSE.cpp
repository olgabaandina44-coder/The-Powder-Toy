#include "simulation/ElementCommon.h"

void Element::Element_ARSE()
{
	Identifier = "DEFAULT_PT_ARSE";
	Name = "ARSE";
	Colour = 0x666E68_rgb;
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
	Meltable = 0;
	Hardness = 4;

	Weight = 97;

	HeatConduct = 95;
	Description = "Arsenic (Z=33). Toxic metalloid that sublimates directly into gas at 614C (887 K).";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 887.0f;
	HighTemperatureTransition = PT_GAS;
}
