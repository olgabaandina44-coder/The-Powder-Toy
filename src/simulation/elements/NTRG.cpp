#include "simulation/ElementCommon.h"

void Element::Element_NTRG()
{
	Identifier = "DEFAULT_PT_NTRG";
	Name = "NTRG";
	Colour = 0x88AADD_rgb;
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = 0.0f;
	Diffusion = 0.75f;
	HotAir = 0.000f * CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 4;

	HeatConduct = 30;
	Description = "Nitrogen (Z=7). Inert diatomic gas making up 78% of Earth atmosphere. Condenses to LN2 at 77.36 K.";

	Properties = TYPE_GAS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 77.36f;
	LowTemperatureTransition = PT_LN2;
	HighTemperature = ITL;
	HighTemperatureTransition = NT;
}
