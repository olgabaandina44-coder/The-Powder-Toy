#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_ALOY()
{
	Identifier = "DEFAULT_PT_ALOY";
	Name = "ALOY";
	Colour = 0x7E8C99_rgb;
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
	Hardness = 0;

	Weight = 100;

	HeatConduct = 210;
	Description = "Superalloy. High-strength corrosion-resistant metal matrix (Fe-W-B / Ti-Au) with 2650C melting point.";

	Properties = TYPE_SOLID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 2923.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
	Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS)
{
	// Вторичное сплавление при контакте горячего сплава с расплавом железа, вольфрама или титана
	if (parts[i].temp > 1200.0f)
	{
		for (int ry = -1; ry <= 1; ry++)
		{
			int ny = y + ry;
			if (ny < CELL || ny >= YRES - CELL)
				continue;
			for (int rx = -1; rx <= 1; rx++)
			{
				if (!rx && !ry)
					continue;
				int nx = x + rx;
				if (nx < CELL || nx >= XRES - CELL)
					continue;
				unsigned int r = pmap[ny][nx];
				if (r && TYP(r) == PT_LAVA)
				{
					int meltType = parts[ID(r)].ctype;
					if (meltType == PT_IRON || meltType == PT_METL || meltType == PT_TUNG || meltType == PT_TTAN)
					{
						if (sim->rng.chance(1, 20))
						{
							parts[ID(r)].ctype = PT_ALOY;
						}
					}
				}
			}
		}
	}

	return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
	*colr = 126;
	*colg = 140;
	*colb = 153;
	return 0;
}
