#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);
static int graphics(GRAPHICS_FUNC_ARGS);

void Element::Element_QFLX()
{
	Identifier = "DEFAULT_PT_QFLX";
	Name = "QFLX";
	Colour = 0x7A28CB_rgb;
	MenuVisible = 1;
	MenuSection = SC_LIQUID;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.90f;
	Collision = 0.0f;
	Gravity = 0.20f;
	Diffusion = 0.00f;
	HotAir = 0.000f * CFDS;
	Falldown = 2;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 45;

	DefaultProperties.temp = R_TEMP - 10.0f + 273.15f;
	HeatConduct = 80;
	Description = "Quantum Flux. Reverses gravity under pressure or spark; synthesizes rare matter from radiation.";

	Properties = TYPE_LIQUID | PROP_CONDUCTS | PROP_LIFE_DEC | PROP_PHOTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &update;
	Graphics = &graphics;
}

static int update(UPDATE_FUNC_ARGS)
{
	// Активация квантовой фазы от высокого давления (> 2.0)
	if (sim->pv[y / CELL][x / CELL] > 2.0f && parts[i].tmp < 40)
	{
		parts[i].tmp = 60;
	}

	// Поведение в активной квантовой фазе (антигравитация + вакуумный вихрь)
	if (parts[i].tmp > 0)
	{
		parts[i].tmp--;
		parts[i].vy -= 0.45f; // Преодолеваем гравитацию и взлетаем вверх
		sim->pv[y / CELL][x / CELL] -= 0.25f; // Затягиваем соседние частицы
	}

	for (auto rx = -1; rx <= 1; rx++)
	{
		for (auto ry = -1; ry <= 1; ry++)
		{
			if (rx || ry)
			{
				auto r = pmap[y + ry][x + rx];
				if (!r)
				{
					// Проверяем слой излучения (нейтроны и фотоны лежат в photmap)
					r = sim->photons[y + ry][x + rx];
					if (!r)
						continue;
				}

				int rt = TYP(r);

				// Удар электрической искры переводит в квантовую фазу
				if (rt == PT_SPRK)
				{
					parts[i].tmp = 80;
				}
				// Поглощение нейтронов или фотонов: крио-охлаждение + синтез материи
				else if (rt == PT_NEUT || rt == PT_PHOT)
				{
					sim->kill_part(ID(r));
					parts[i].temp = 73.15f; // Охлаждение до -200°C
					parts[i].tmp = 100;

					if (sim->rng.chance(1, 7))
					{
						int roll = sim->rng.between(1, 3);
						int newType = (roll == 1) ? PT_DMND : ((roll == 2) ? PT_URAN : PT_AMTR);
						sim->part_change_type(i, x, y, newType);
						return 1;
					}
				}
				// Передача квантовой фазы соседним частицам QFLX
				else if (rt == PT_QFLX && parts[i].tmp > 20 && parts[ID(r)].tmp < 10)
				{
					parts[ID(r)].tmp = parts[i].tmp - 10;
				}
			}
		}
	}
	return 0;
}

static int graphics(GRAPHICS_FUNC_ARGS)
{
	int q = cpart->tmp;
	if (q > 0)
	{
		// Яркое бирюзово-фиолетовое свечение в активной фазе
		*colr = int(restrict_flt(110.0f + q * 1.4f, 0, 255));
		*colg = int(restrict_flt(180.0f + q * 0.7f, 0, 255));
		*colb = 255;

		*firer = *colr;
		*fireg = *colg;
		*fireb = 255;
		*firea = 90;
		*pixel_mode |= FIRE_ADD | PMODE_GLOW | PMODE_ADD;
		*pixel_mode &= ~PMODE_FLAT;
	}
	else
	{
		// Глубокий переливающийся фиолетовый в спокойной фазе
		int shimmer = gfctx.rng.between(-18, 18);
		*colr = int(restrict_flt(122 + shimmer, 0, 255));
		*colg = int(restrict_flt(40 + shimmer / 2, 0, 255));
		*colb = int(restrict_flt(203 + shimmer, 0, 255));
		*pixel_mode |= PMODE_BLUR;
	}
	return 0;
}
