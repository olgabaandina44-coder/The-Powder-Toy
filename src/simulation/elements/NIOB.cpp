#include "simulation/ElementCommon.h"

void Element::Element_NIOB()
{
	Identifier = "DEFAULT_PT_NIOB";
	Name = "NIOB";
	Colour = 0x7A8999_rgb;
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
	Hardness = 0;

	Weight = 99;

	HeatConduct = 115;
	Description = "Niobium (Z=41). Refractory superconducting metal used in MRI magnets and rocket nozzles, melts at 2477C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2750.0f;
	HighTemperatureTransition = PT_LAVA;
}
