#include "headers/include.h"

Texture2D pannel;

void ui_init(){
    pannel = LoadTexture("resources/images/panel.png");
}

void gui_list(char *name, UIListItem *items){

}

void ui_draw_list(UIList *ui_list){
    if(ui_list->active){
        if(control_pressed(CONTROL_DOWN)){
            ui_list->cursor++;
            if(ui_list->cursor > ui_list->item_count)
                ui_list->cursor = 0;
        } else if(control_pressed(CONTROL_UP)){
            ui_list->cursor--;
            if(ui_list->cursor < 0)
                ui_list->cursor = ui_list->item_count-1;
        } else if(control_pressed(CONTROL_ENTER)){
            ui_list->func_item(&ui_list);
        }

    }
    // calc size ...
    // ui_list->size
    DrawTextureEx(pannel, ui_list->pos, 0, 1.0f, WHITE);
}