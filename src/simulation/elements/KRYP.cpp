#include "simulation/ElementCommon.h"

void Element::Element_KRYP()
{
	Identifier = "DEFAULT_PT_KRYP";
	Name = "KRYP";
	Colour = 0xB8D0E8_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.08f;
	Diffusion = 0.65f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 7;

	HeatConduct = 20;
	Description = "Krypton (Z=36). Heavy noble gas used in high-efficiency lighting and excimer lasers. Boils at 119.93 K.";

	Properties = TYPE_GAS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 119.93f;
	LowTemperatureTransition = PT_LAVA;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;
}
