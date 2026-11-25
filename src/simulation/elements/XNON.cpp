#include "simulation/ElementCommon.h"

void Element::Element_XNON()
{
	Identifier = "DEFAULT_PT_XNON";
	Name = "XNON";
	Colour = 0x7AA8E8_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.14f;
	Diffusion = 0.60f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 8;

	HeatConduct = 15;
	Description = "Xenon (Z=54). Dense noble gas used in spacecraft ion thrusters and flash lamps. Boils at 165.03 K.";

	Properties = TYPE_GAS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 165.03f;
	LowTemperatureTransition = PT_LAVA;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;
}
