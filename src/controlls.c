#include "headers/include.h"

#define CONTROL_DELAY .3f

int control_last_press = -1;
double control_delay_input_until = -1;


bool control_pressed_helper(int type){
    switch (type)
    {
    case CONTROL_UP:
        if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
            return true;
		break;
    case CONTROL_RIGHT:
        if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
            return true;
		break;
    case CONTROL_DOWN:
        if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
            return true;
		break;
    case CONTROL_LEFT:
        if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
            return true;
		break;
    case CONTROL_ENTER:
        if(IsKeyDown(KEY_ENTER) || IsKeyDown(KEY_SPACE))
            return true;
		break;
    case CONTROL_BACK:
        if(IsKeyDown(KEY_BACKSPACE))
            return true;
		break;
    case CONTROL_MENU:
        if(IsKeyDown(KEY_ESCAPE))
            return true;
		break;
	};
	return false;
}

bool control_pressed(int type){	
    if(control_last_press != type || GetTime() >= control_delay_input_until){
        if(control_pressed_helper(type)){			
            control_last_press = type;
			control_delay_input_until = GetTime() + CONTROL_DELAY;
            return true;
        }
    }
    return false;
}