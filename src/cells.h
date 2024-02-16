#pragma once

#include <stdint.h>
#include "grid.h"

void cell_sand_step(cell* grid, int x, int y);
void cell_water_step(cell* grid, int x, int y);