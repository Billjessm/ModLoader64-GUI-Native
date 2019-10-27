#include "headers/include.h"

#define CONTROL_DELAY 0.3

int control_last_press = -1;
int control_last_time = -1;


void control_pressed_helper(int type){
    switch (type)
    {
    case CONTROL_UP:
        if(IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){
            return true;
    case CONTROL_RIGHT:
        if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
            return true;
    case CONTROL_DOWN:
        if(IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){
            return true;
    case CONTROL_LEFT:
        if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
            return true;
    case CONTROL_ENTER:
        if(IsKeyDown(KEY_ENTER) || IsKeyDown(KEY_SPACE)){
            return true;
    case CONTROL_BACK:
        if(IsKeyDown(KEY_BACKSPACE)){
            return true;
    case CONTROL_MENU:
        if(IsKeyDown(KEY_ESCAPE)){
            return true;
    }
}

bool control_pressed(int type){
    if(control_last_press != type || control_last_time >= GetTime()){
        if(control_pressed_helper(type)){
            control_last_press = type;
            control_last_time = GetTime() + CONTROL_DELAY;
            return true;
        }
    }
    return false;
}