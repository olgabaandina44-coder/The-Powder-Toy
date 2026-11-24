#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_GRPH()
{
	Identifier = "DEFAULT_PT_GRPH";
	Name = "GRPH";
	Colour = 0x2E343B_rgb;
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
	Meltable = 0;
	Hardness = 0;

	Weight = 100;

	HeatConduct = 255;
	Description = "Graphene. 2D hexagonal carbon allotrope with extreme thermal/electrical conductivity and optical transparency.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_PHOTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 3900.0f;
	HighTemperatureTransition = PT_PLSM;

	Update = &update;
	Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS)
{
	// HPHT-синтез: переход в алмаз при экстремальном давлении и высокой температуре
	if (sim->pv[y / CELL][x / CELL] > 75.0f && parts[i].temp > 2000.0f)
	{
		if (sim->rng.chance(1, 20))
		{
			sim->part_change_type(i, x, y, PT_DMND);
			return 1;
		}
	}

	// Окисление углерода в кислороде при температуре выше 700 °C (973.15 K)
	if (parts[i].temp > 973.15f)
	{
		for (int ry = -1; ry <= 1; ry++)
		{
			for (int rx = -1; rx <= 1; rx++)
			{
				if (!rx && !ry)
					continue;
				int r = pmap[y + ry][x + rx];
				if (!r)
					continue;
				int rt = TYP(r);
				if (rt == PT_O2 || rt == PT_LO2)
				{
					if (sim->rng.chance(1, 15))
					{
						sim->kill_part(ID(r));
						sim->part_change_type(i, x, y, PT_CO2);
						parts[i].temp += 150.0f;
						return 1;
					}
				}
			}
		}
	}

	return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
	*colr = 46;
	*colg = 52;
	*colb = 59;

	// Тепловое свечение при нагреве выше 800 K
	if (cpart->temp > 800.0f)
	{
		float heat = (cpart->temp - 800.0f) / 2500.0f;
		if (heat > 1.0f)
			heat = 1.0f;
		*colr += int(heat * 209.0f);
		*colg += int(heat * 110.0f);
		*colb += int(heat * 20.0f);
		*firea = int(heat * 40.0f);
		*firer = *colr;
		*fireg = *colg;
		*fireb = *colb;
		*pixel_mode |= PMODE_GLOW;
	}

	return 0;
}
