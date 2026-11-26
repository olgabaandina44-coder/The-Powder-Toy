#include "simulation/ElementCommon.h"

void Element::Element_ARGL()
{
	Identifier = "DEFAULT_PT_ARGL";
	Name = "ARGL";
	Colour = 0x89CFF0_rgb;
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
	Hardness = 5;
	PhotonReflectWavelengths = 0x000003FF;

	Weight = 100;

	HeatConduct = 0;
	Description = "Aerogel. Ultra-light nanoporous solid with near-zero thermal conductivity; shatters under high pressure.";

	Properties = TYPE_SOLID | PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = 18.0f;
	HighPressureTransition = PT_DUST;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1473.15f;
	HighTemperatureTransition = PT_GLAS;
}
