#include "cells.h"
#include "info.h"
#include <stdio.h>

void cell_sand_step(cell* grid, int x, int y) {
    if (y == GRID_HEIGHT - 1) return;
    if (grid_get(x, y + 1) == 1) {
        if ((x - 1) >= 0)
            if (grid_get(x - 1, y + 1) == 0) {
                grid_plot(x, y, 0, 0);
                grid_plot(x - 1, y + 1, 1, 1);
                return;
            }
            else
                if (grid_get(x + 1, y + 1) == 0) {
                    grid_plot(x, y, 0, 0);
                    grid_plot(x + 1, y + 1, 1, 1);
                    return;
                }
        else
            if (grid_get(x + 1, y + 1) == 0) {
                grid_plot(x, y, 0, 0);
                grid_plot(x + 1, y + 1, 1, 1);
                return;
            }
        return;
    } else
        if (grid_get(x, y + 1) != 0) return;
    grid_plot(x, y, 0, 0);
    grid_plot(x, y + 1, 1, 1);
}

void cell_water_step(cell* grind, int x, int y) {
}