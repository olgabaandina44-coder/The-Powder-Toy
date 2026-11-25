#include "simulation/ElementCommon.h"

void Element::Element_BERY()
{
	Identifier = "DEFAULT_PT_BERY";
	Name = "BERY";
	Colour = 0x8C9E9E_rgb;
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

	Weight = 95;

	HeatConduct = 200;
	Description = "Beryllium (Z=4). Lightweight alkaline earth metal, neutron reflector, melts at 1287C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1560.0f;
	HighTemperatureTransition = PT_LAVA;
}
