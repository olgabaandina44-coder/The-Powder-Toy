#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_ASTT()
{
	Identifier = "DEFAULT_PT_ASTT";
	Name = "ASTT";
	Colour = 0x4A444E_rgb;
	MenuVisible = 1;
	MenuSection = SC_RADIOACTIVE;
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

	Weight = 99;

	HeatConduct = 30;
	Description = "Astatine (Z=85). Rarest naturally occurring halogen; intensely radioactive, decays rapidly into lead with heat.";

	Properties = TYPE_SOLID | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 575.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	if (sim->rng.chance(1, 60))
	{
		parts[i].temp += 85.0f;
		if (!sim->photons[y][x])
			sim->create_part(-3, x, y, PT_ELEC);
		if (sim->rng.chance(1, 10))
		{
			sim->part_change_type(i, x, y, PT_LEAD);
			return 1;
		}
	}
	return 0;
}
