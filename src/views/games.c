#include "../headers/include.h"

typedef enum State { SELECT_GAME, SELECT_ROM } State;

static UIList games;
static UIListItem items[3];
static State state;

int selected_game;

void game_selected() {
	view = 4;
	selected_game = games.cursor;
}


void view_games_init(){
    games.active = true;
	games.item_count = 3;
	games.func_item = &game_selected;
	games.items = items;
	games.items[0].name = "Ocarina of Time";
	games.items[1].name = "Mario";
	games.items[2].name = "Was anderes";
}

void view_games_activate(){
    games.active = true;
	state = SELECT_GAME;
}

void view_games_draw(){
    ui_draw_list(&games);
}

void view_games_deactive(){

}

void view_games_destroy(){
    
}