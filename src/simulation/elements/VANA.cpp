#include "simulation/ElementCommon.h"

void Element::Element_VANA()
{
	Identifier = "DEFAULT_PT_VANA";
	Name = "VANA";
	Colour = 0x7F8C8D_rgb;
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

	Weight = 98;

	HeatConduct = 110;
	Description = "Vanadium (Z=23). Hard, ductile transition metal with high corrosion resistance, melts at 1910C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2183.0f;
	HighTemperatureTransition = PT_LAVA;
}
