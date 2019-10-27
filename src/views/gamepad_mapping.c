#include "../headers/include.h"

Texture2D controller_base;

static int current_state = 0;
static int a_button = -1;
static int current_press = -1;
static int last_press = -1;
static int detected_axis = -1;
static int mid2 = (1920 / 2) - 250;
static bool first_connect = true;
static float *axis_defaults;

void view_mapping_init() {
	controller_base = LoadTexture("resources/images/controller/base.png");
	for (int i = 0; i < 16; i++)
	{
		if (config_input_mapping[i].index == -1) {
			current_state = i;
			break;
		}
		else if (i == 15) {
			current_state = 15;
		}
	}
}



//void view_mapping_reset() {
//	first_connect = true;
//	current_state = 0;
//	init_mapping();
//	a_button = -1;
//	current_press = -1;
//	last_press = -1;
//	detected_axis = -1;
//}

void view_mapping_update() {
	if (IsGamepadAvailable(GAMEPAD_PLAYER1))
	{	
		if (first_connect) {
			axis_defaults = (float *)malloc(GetGamepadAxisCount(GAMEPAD_PLAYER1) + 2 * sizeof(float));
			for (int i = 0; i < GetGamepadAxisCount(GAMEPAD_PLAYER1) + 2; i++) {
				axis_defaults[i] = GetGamepadAxisMovement(GAMEPAD_PLAYER1, i);
			}
			first_connect = false;
		}
		DrawTextB(FormatText("Gamepad: %s", GetGamepadName(GAMEPAD_PLAYER1)), mid2, 10, 18, WHITE);

		DrawTextB(FormatText("Press: %s", config_input_mapping[current_state].name), mid2, 50, 26, WHITE);

		DrawTexture(controller_base, mid2-225, 80, WHITE);
		//DrawTexture(config_input_mapping[current_state].image, mid2-225, 80, WHITE);

		DrawTextB(FormatText("DETECTED AXIS [%i]:", GetGamepadAxisCount(GAMEPAD_PLAYER1)), 10, 50, 10, MAROON);

		if (detected_axis != -1) {
			if (GetGamepadAxisMovement(GAMEPAD_PLAYER1, detected_axis) < 0.1f && GetGamepadAxisMovement(GAMEPAD_PLAYER1, detected_axis) > -0.1f) {
				// axis released!

			}
		}

		for (int i = 0; i < GetGamepadAxisCount(GAMEPAD_PLAYER1) + 2; i++)
		{
			DrawTextB(FormatText("AXIS %i: %.02f", i, GetGamepadAxisMovement(GAMEPAD_PLAYER1, i)), mid2+700, 500 + 20 * i, 24, DARKGRAY);
			if (last_press != i && (GetGamepadAxisMovement(GAMEPAD_PLAYER1, i) > axis_defaults[i]+0.7 || GetGamepadAxisMovement(GAMEPAD_PLAYER1, i) < axis_defaults[i]-0.7f)) {
				detected_axis = i;
				config_input_mapping[current_state].index = i;
				config_input_mapping[current_state].is_axis = true;
				current_state += 1;
				last_press = i;
				break;
			}
		}

		

		if ((GetGamepadButtonPressed() != -1 && GetGamepadButtonPressed() != last_press)) {
			last_press = GetGamepadButtonPressed();
			config_input_mapping[current_state].index = last_press;			
			current_state += 1;
		}
		
		//if ((GetKeyPressed() != -1 && GetKeyPressed() != last_press)) {
		//	last_press = GetKeyPressed();
		//	input_mapping[current_state].index = last_press;
		//	current_state += 1;
		//}
		

		for (int i = 0; i < current_state + 1; i++)
		{
			//if (config_input_mapping[i].index != -1 && config_input_mapping[i].text_pos.x != -1 && input_mapping[i].text_pos.y != -1) {
			//	char *type;
			//	if (input_mapping[i].is_axis) type = "Axis"; else type = "Button";
			//	DrawTextB(FormatText("%s %i", type, input_mapping[i].index), mid2 - 220 + (int)input_mapping[i].text_pos.x, 85 + (int)input_mapping[i].text_pos.y, 24, WHITE);
			//}
		}
		
		if (a_button != -1) {
			DrawTextB(FormatText("DETECTED BUTTON: %i", a_button), 500, 10, 10, RED);
		}


		if (GetGamepadButtonPressed() != -1) {
			DrawTextB(FormatText("DETECTED BUTTON: %i", GetGamepadButtonPressed()), mid2, 10, 24, RED);
		} else if (GetKeyPressed() != -1) {
			DrawTextB(FormatText("DETECTED BUTTON: %i", GetKeyPressed()), mid2, 900, 24, RED);
		} else {
			DrawTextB("DETECTED BUTTON: NONE", mid2, 900, 24, RED);
		}
		if (current_state >= 16) {
			config_save();
			view = 0;//VIEW_ID_GAMES;
			return;
		}
	}
	else
	{
		DrawTextB("NO GAMEPAD DETECTED!\nPlease connect a gamepad.", mid2-150, 300, 30, WHITE);
	}
}

void view_mapping_destroy() {
	UnloadTexture(controller_base);
	for (int i = 0; i < 16; i++)
	{
		// UnloadTexture(config_input_mapping[i].image);
	}
}