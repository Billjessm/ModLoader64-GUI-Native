#include "headers/include.h"

#define VIEW_COUNT 1

int last_view = -1;
int view = -1;
UIView views[VIEW_COUNT];

void main() {
    // init config
    SetExitKey(-255); // Disable close app with ESC 

    load_config();

    InitWindow(config_screen_width, config_screen_height, "ModLoader 64");
    SetTargetFPS(config_fps);

    NewUiView(views[0], 0, "Select Game", &view_games_init, &view_games_activate, &view_games_draw, &view_games_deactive, &view_games_destroy);


    for (int i = 0; i < VIEW_COUNT; i++)
    {
        views[i].init();
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if(view != last_view){
            views[last_view].deactive();
            views[view].active();
        }

        views[view].draw();

        EndDrawing();
    }
    
    for (int i = 0; i < VIEW_COUNT; i++)
    {
        views[i].destroy();
    }
    
    CloseWindow();

    return 0;    
}