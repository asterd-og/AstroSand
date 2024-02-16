#pragma once

#define WIN_WIDTH 768
#define WIN_HEIGHT 512 // Both divisible by 24.

#define CELL_WIDTH 24
#define CELL_HEIGHT 24

#define GRID_WIDTH (WIN_WIDTH / CELL_WIDTH)
#define GRID_HEIGHT (WIN_HEIGHT / CELL_HEIGHT)

inline int check_collision(int x1, int y1, int x2, int y2, int w2, int h2) {
    return (x1 >= x2 && x1 <= x2 + w2 && y1 >= y2 && y1 <= y2 + h2);
}

extern unsigned char game_current_item;