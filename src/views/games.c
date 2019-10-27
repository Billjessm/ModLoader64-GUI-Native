#include "../headers/include.h"

UIList games;

void view_games_init(){
    games.active = false;

}

void view_games_activate(){
    games.active = true;
}

void view_games_draw(){
    ui_draw_list(&games);
}

void view_games_deactive(){

}

void view_games_destroy(){
    
}