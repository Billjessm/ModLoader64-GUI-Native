#include <stddef.h>
#include <stdio.h>
#include "raylib.h"

#include "../extern_libs/cJSON/cJSON.h"
#include "../extern_libs/cJSON/cJSON_Utils.h"

#include "headers/structs.h"

ControllerInput config_input_mapping[16];
int config_screen_width;
int config_screen_height;
int config_screen_width_mid;
bool config_fullscreen;
int config_fps;

void config_save(){
    char *json_config_str = NULL;
	cJSON *root = cJSON_CreateObject();

    cJSON *graphic = cJSON_AddObjectToObject(root, "graphic");
    cJSON_AddNumberToObject(graphic, "screen_width", config_screen_width);
    cJSON_AddNumberToObject(graphic, "screen_height", config_screen_height);
    cJSON_AddNumberToObject(graphic, "fps", config_fps);
    cJSON_AddBoolToObject(graphic, "fullscreen", config_fullscreen);

	cJSON *mapping = cJSON_AddObjectToObject(root, "mapping");
	for (size_t i = 0; i < 16; i++) {
		cJSON *input = cJSON_AddObjectToObject(mapping, config_input_mapping[i].id);
		cJSON_AddBoolToObject(input, "is_axis", config_input_mapping[i].is_axis);
		cJSON_AddBoolToObject(input, "flipped", config_input_mapping[i].is_flipped);
		cJSON_AddNumberToObject(input, "index", config_input_mapping[i].index);
	}
	json_config_str = cJSON_Print(root);

	// TODO: LINUX FIX:

	// FILE* fp;
	// int err = fopen("config.json", "w");
	// if (err < 0) {
	// 	//throw_error(ERROR_CONFIG_EXAMPLE_NOT_FOUND);
	// 	//view_state = VIEW_EXIT;
	// 	return;
	// }
	// fprintf(fp, json_config_str);
	// fclose(fp);
}

void config_init_base(){
	int test = GetMonitorCount();
    config_screen_width = GetMonitorWidth(GetMonitorCount()-1);
    config_screen_height = GetMonitorHeight(GetMonitorCount() - 1);
    config_screen_width_mid = (int)(config_screen_width/2);
    config_fullscreen = false;
    config_fps = 30;

    NewControllerInput(config_input_mapping[0], "A", false, false, -1, "A Button");
	NewControllerInput(config_input_mapping[1], "B", false, false, -1, "B Button");
	NewControllerInput(config_input_mapping[2], "C-U", false, false, -1, "C-UP Button");
	NewControllerInput(config_input_mapping[3], "C-R", false, false, -1, "C-RIGHT Button");
	NewControllerInput(config_input_mapping[4], "C-D", false, false, -1, "C-DOWN Button");
	NewControllerInput(config_input_mapping[5], "C-L", false, false, -1, "C-LEFT Button");
	NewControllerInput(config_input_mapping[6], "AN-LR", false, false, -1, "Analog Left-Right");
	NewControllerInput(config_input_mapping[7], "AN-DU", false, false, -1, "Analog Down-Up");
	NewControllerInput(config_input_mapping[8], "Z", false, false, -1, "Z Trigger");
	NewControllerInput(config_input_mapping[9], "D-U", false, false, -1, "Digital Up");
	NewControllerInput(config_input_mapping[10], "D-R", false, false, -1, "Digital Right");
	NewControllerInput(config_input_mapping[11], "D-D", false, false, -1, "Digital Down");
	NewControllerInput(config_input_mapping[12], "D-L", false, false, -1, "Digital Left");
	NewControllerInput(config_input_mapping[13], "L", false, false, -1, "L Button");
	NewControllerInput(config_input_mapping[14], "R", false, false, -1, "R Button");
	NewControllerInput(config_input_mapping[15], "S", false, false, -1, "Start");
}

void config_init(){

    config_init_base();

    char *json_config_str;
	
	if (!FileExists("config.json")) {		
		config_save();
	} else {
		//json_config_str = LoadText("config.json");
        //load_json(json_config_str);
	}	
}