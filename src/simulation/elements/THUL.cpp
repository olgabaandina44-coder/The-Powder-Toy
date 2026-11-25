#include "simulation/ElementCommon.h"

void Element::Element_THUL()
{
	Identifier = "DEFAULT_PT_THUL";
	Name = "THUL";
	Colour = 0x82888D_rgb;
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

	HeatConduct = 65;
	Description = "Thulium (Z=69). Rare ductile lanthanide used in portable X-ray devices and surgical lasers, melts at 1545C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1818.0f;
	HighTemperatureTransition = PT_LAVA;
}
