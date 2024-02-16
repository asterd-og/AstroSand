#include "cells.h"
#include "info.h"
#include <stdio.h>

void cell_sand_step(cell* grid, int x, int y) {
    if (y == GRID_HEIGHT - 1) return;

    if (grid_get(x, y + 1) == 0) {
        grid_plot(x, y, 0, 0);
        grid_plot(x, y + 1, 1, 1);
        return;
    }

    if (grid_get(x - 1, y + 1) == 0 && (x - 1) >= 0) {
        grid_plot(x, y, 0, 0);
        grid_plot(x - 1, y + 1, 1, 1);
        return;
    }

    if (grid_get(x + 1, y + 1) == 0 && (x + 1) <= GRID_WIDTH - 1) {
        grid_plot(x, y, 0, 0);
        grid_plot(x + 1, y + 1, 1, 1);
        return;
    }
}

void cell_water_step(cell* grind, int x, int y) {
    if (grid_get(x, y + 1) == 0 && y < GRID_HEIGHT - 1) {
        grid_plot(x, y, 0, 0);
        grid_plot(x, y + 1, 2, 1);
        return;
    }

    if (grid_get(x - 1, y + 1) == 0 && (x - 1) >= 0 && y < GRID_HEIGHT - 1) {
        if (grid_get(x - 1, y) == 0 || grid_get(x, y + 1) == 0) {
            grid_plot(x, y, 0, 0);
            grid_plot(x - 1, y + 1, 2, 1);
        }
        return;
    }

    if (grid_get(x + 1, y + 1) == 0 && (x + 1) <= GRID_WIDTH - 1 && y < GRID_HEIGHT - 1) {
        if (grid_get(x + 1, y) == 0 || grid_get(x, y + 1) == 0) {
            grid_plot(x, y, 0, 0);
            grid_plot(x + 1, y + 1, 2, 1);
        }
        return;
    }

    if (grid_get(x - 1, y) == 0 && (x - 1) >= 0) {
        grid_plot(x, y, 0, 0);
        grid_plot(x - 1, y, 2, 1);
        return;
    }

    if (grid_get(x + 1, y) == 0 && (x + 1) <= GRID_WIDTH - 1) {
        grid_plot(x, y, 0, 0);
        grid_plot(x + 1, y, 2, 1);
        return;
    }
}

void cell_wall_step(cell* grid, int x, int y){
    return;
}