#include "headers/include.h"

static Texture2D pannel;
static Font LAUNCHER_FONT;    // Global variable, initialize at beginning.

void ui_init(){
    pannel = LoadTexture("resources/images/panel.png");
	LAUNCHER_FONT = LoadFont("resources/misc/Anonymous_Pro_B.ttf");
}


void DrawTextB(char *text, int posX, int posY, int fontSize, Color color)
{
	//DrawTextEx(FONT_DEFAULT, text, (Vector2) { (float)posX, (float)posY }, fontSize + 2, 1, color);
  DrawText(text, posX, posY, fontSize, color);
}

void ui_draw_list(UIList *ui_list){
    if(ui_list->active){
        if(control_pressed(CONTROL_DOWN)){
            ui_list->cursor++;
            if(ui_list->cursor >= ui_list->item_count)
                ui_list->cursor = 0;
        } else if(control_pressed(CONTROL_UP)){
            ui_list->cursor--;
            if(ui_list->cursor < 0)
				ui_list->cursor  = ui_list->item_count-1;
        } else if(control_pressed(CONTROL_ENTER)){
            ui_list->func_item();
        }

    }
    // calc size ...
    // ui_list->size
    //DrawTextureEx(pannel, , 0, 1.0f, WHITE);
	for (int i = 0; i < ui_list->item_count; i++)
	{
		if (ui_list->cursor == i) {
			DrawText(ui_list->items[i].name, 100, 100 + i * 40, 30, GREEN);
		}
		else {
			DrawText(ui_list->items[i].name, 100, 100 + i * 40, 30 , WHITE);
		}
	}
}