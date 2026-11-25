#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_LEAD()
{
	Identifier = "DEFAULT_PT_LEAD";
	Name = "LEAD";
	Colour = 0x525866_rgb;
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
	Hardness = 6;

	Weight = 100;

	HeatConduct = 85;
	Description = "Lead (Z=82). High-density heavy metal radiation shield that attenuates ionizing particles, melts at 327.5C.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 600.61f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{
	// Радиационная защита: ослабление бета-, протонного и нейтронного излучения
	for (int ry = -1; ry <= 1; ry++)
	{
		for (int rx = -1; rx <= 1; rx++)
		{
			unsigned int ph = sim->photons[y + ry][x + rx];
			if (!ph)
				continue;
			int pht = TYP(ph);
			if (pht == PT_ELEC || pht == PT_PROT || (pht == PT_NEUT && sim->rng.chance(1, 2)))
			{
				sim->kill_part(ID(ph));
				parts[i].temp += 12.0f;
			}
		}
	}
	return 0;
}
