#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_NEPT()
{
	Identifier = "DEFAULT_PT_NEPT";
	Name = "NEPT";
	Colour = 0x5E6E78_rgb;
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
	Hardness = 3;

	Weight = 100;

	HeatConduct = 50;
	Description = "Neptunium (Z=93). First synthetic transuranic actinide; captures neutrons to breed Plutonium fuel, melts at 639C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_RADIOACTIVE;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 912.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	// Захват нейтрона превращает 237Np в Плутоний (PLUT)
	for (int ry = -1; ry <= 1; ry++)
	{
		for (int rx = -1; rx <= 1; rx++)
		{
			unsigned int ph = sim->photons[y + ry][x + rx];
			if (ph && TYP(ph) == PT_NEUT)
			{
				sim->kill_part(ID(ph));
				parts[i].temp += 55.0f;
				if (sim->rng.chance(1, 3))
				{
					sim->part_change_type(i, x, y, PT_PLUT);
					return 1;
				}
			}
		}
	}
	return 0;
}
