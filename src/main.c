#include "raylib.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "info.h"
#include "grid.h"
#include "toolbar.h"

uint8_t game_current_item = 1;

int main(void) {
    InitWindow(WIN_WIDTH, WIN_HEIGHT, "AstroSand! - Press 'T' for ToolBar.");

    int x, y;
    x = 0;
    y = 0;

    double ticks = 0;

    grid_init();
    toolbar_init();

    bool toolbar_showing = false;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(DARKGRAY);

        if (IsKeyPressed(KEY_T)) {
            toolbar_showing = !toolbar_showing;
        }

        if (round(ticks) >= 10) {
            grid_step();
            ticks = 0;
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            if (toolbar_showing) {
                if (GetMouseX() > WIN_WIDTH - (TB_ITEM_WIDTH * 2)) {}
                else {
                    x = ((int)round(GetMouseX() / CELL_WIDTH)) * CELL_WIDTH;
                    y = ((int)round(GetMouseY() / CELL_HEIGHT)) * CELL_HEIGHT;
                    grid_plot(x / CELL_WIDTH, y / CELL_HEIGHT, game_current_item, 0);
                }
            } else {
                x = ((int)round(GetMouseX() / CELL_WIDTH)) * CELL_WIDTH;
                y = ((int)round(GetMouseY() / CELL_HEIGHT)) * CELL_HEIGHT;
                grid_plot(x / CELL_WIDTH, y / CELL_HEIGHT, game_current_item, 0);
            }
        }

        grid_draw();

        if (toolbar_showing) {
            toolbar_draw();
        }

        ticks += ((GetFrameTime() * 100));
        
        EndDrawing();
    }

    grid_destroy();

    CloseWindow();

    return 0;
}