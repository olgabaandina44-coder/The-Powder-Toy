#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_MHYD()
{
	Identifier = "DEFAULT_PT_MHYD";
	Name = "MHYD";
	Colour = 0xB8D8E8_rgb;
	MenuVisible = 1;
	MenuSection = SC_LIQUID;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.5f;
	Diffusion = 0.00f;
	HotAir = 0.000f * CFDS;
	Falldown = 2;

	Flammable = 100;
	Explosive = 2;
	Meltable = 0;
	Hardness = 0;

	Weight = 75;

	HeatConduct = 250;
	Description = "Metallic Hydrogen. Superconducting high-pressure state found inside gas giants; violently reverts to H2 when heated.";

	Properties = TYPE_LIQUID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 650.0f;
	HighTemperatureTransition = PT_H2;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (parts[i].temp > 600.0f)
	{
		sim->pv[y / CELL][x / CELL] += 18.0f;
		parts[i].temp += 2500.0f;
		sim->part_change_type(i, x, y, PT_H2);
		return 1;
	}
	return 0;
}
