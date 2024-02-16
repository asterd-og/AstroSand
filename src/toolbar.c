#include "toolbar.h"
#include "raylib.h"
#include "info.h"
#include "string.h"

typedef struct {
    int width;
    int height;
    int x;
    int y;
    Color color;
    char name[16];
    int name_len;
    int item;
} toolbar_item;

toolbar_item toolbar_items[16];
int toolbar_item_count;

void toolbar_draw() {
    DrawRectangle(WIN_WIDTH - (TB_ITEM_WIDTH * 2), 0, TB_ITEM_WIDTH * 2, WIN_HEIGHT, ColorAlpha(BLACK, 0.50));

    for (int i = 0; i < toolbar_item_count; i++) {
        DrawRectangle(toolbar_items[i].x - 1, toolbar_items[i].y - 1, toolbar_items[i].width + 2, toolbar_items[i].height + 2, WHITE);
        DrawRectangle(toolbar_items[i].x, toolbar_items[i].y, toolbar_items[i].width, toolbar_items[i].height, toolbar_items[i].color);

        if (check_collision(GetMouseX(), GetMouseY(), toolbar_items[i].x, toolbar_items[i].y, toolbar_items[i].width, toolbar_items[i].height)) {
            DrawRectangle(GetMouseX() - (toolbar_items[i].name_len + 10), GetMouseY(), toolbar_items[i].name_len + 10, 20, ColorAlpha(BLACK, 0.40));
            DrawText(toolbar_items[i].name, GetMouseX() - (toolbar_items[i].name_len + 5), GetMouseY(), 16, MAGENTA);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                game_current_item = toolbar_items[i].item;
            }
        }
    }
}

void toolbar_add_item(Color color, char* name, int item) {
    toolbar_items[toolbar_item_count].height = TB_ITEM_HEIGHT;
    toolbar_items[toolbar_item_count].width = TB_ITEM_WIDTH;
    toolbar_items[toolbar_item_count].x = (WIN_WIDTH - (TB_ITEM_WIDTH * 2)) + (TB_ITEM_WIDTH / 2);
    toolbar_items[toolbar_item_count].y = TB_ITEM_SPACING + toolbar_item_count * (TB_ITEM_HEIGHT + TB_ITEM_SPACING);
    toolbar_items[toolbar_item_count].color = color;
    toolbar_items[toolbar_item_count].name_len = MeasureText(name, 16);
    toolbar_items[toolbar_item_count].item = item;
    memcpy(toolbar_items[toolbar_item_count].name, name, 16);
    toolbar_item_count++;
}

void toolbar_init() {
    toolbar_add_item(YELLOW, "sand", 1);
    toolbar_add_item(BLUE, "water", 2);
}