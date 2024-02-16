#include "raylib.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "info.h"
#include "grid.h"
#include "cells.h"

cell* grid;

typedef void(*cell_step)(cell*, int, int);
cell_step step_func[32] = {
    cell_wall_step, // NULL object,
    cell_sand_step,
    cell_water_step,
    cell_wall_step
};

Color cell_colors[32] = {
    DARKGRAY,
    YELLOW,
    BLUE,
    BLACK,
};

void grid_draw() {
    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            switch (grid[y * GRID_WIDTH + x].type) {
                case 0:
                    break;
                default:
                    DrawRectangle(x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT, cell_colors[grid[y * GRID_WIDTH + x].type]);
            }
        }
    }
}

void grid_step_aftermath() {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        grid[i].moved = false;
    }
}

void grid_step() {
    for (int x = 0; x < GRID_WIDTH; x++) {
        for (int y = 0; y < GRID_HEIGHT; y++) {
            switch (grid[y * GRID_WIDTH + x].type) {
                case 0:
                    break;
                default:
                    if (!grid[y * GRID_WIDTH + x].moved) {
                        step_func[grid[y * GRID_WIDTH + x].type](grid, x, y);
                    }
                    break;
            }
        }
    }
    grid_step_aftermath();
}

void grid_plot(int x, int y, uint8_t type, bool moved) {
    grid[y * GRID_WIDTH + x].type = type;
    grid[y * GRID_WIDTH + x].moved = moved;
}

uint8_t grid_get(int x, int y) {
    return grid[y * GRID_WIDTH + x].type;
}

void grid_destroy() {
    free(grid);
}

void grid_init() {
    grid = malloc(GRID_WIDTH * GRID_HEIGHT * sizeof(cell));
    memset(grid, 0, GRID_WIDTH * GRID_HEIGHT * sizeof(cell));
}