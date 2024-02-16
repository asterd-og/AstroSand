#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t type;
    bool moved;
} cell;

void grid_init();
void grid_draw();
void grid_step();
void grid_plot(int x, int y, uint8_t type, bool moved);
uint8_t grid_get(int x, int y);
void grid_destroy();