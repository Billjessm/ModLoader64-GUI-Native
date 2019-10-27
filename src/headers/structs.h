//#include "include.h"

typedef struct ControllerInput{
    int index;
    char *id;
    char *name;
    bool is_axis;
    bool is_flipped;
} ControllerInput;

#define NewControllerInput(_controller_input, _id, _axis, _flip, _index, _name) \
do { \
	_controller_input.id = _id; \
	_controller_input.is_axis = _axis; \
	_controller_input.is_flipped = _flip; \
	_controller_input.index = _index; \
	_controller_input.name = _name; \
} while(0)

typedef struct ControllerInputGui{
    ControllerInput input;

    Texture2D texture;
    Vector2 text_pos;
} ControllerInputGui;

typedef struct UIConfig{
    int screen_width;
    int screen_height;
} UIConfig;

typedef struct Config{
    UIConfig ui;
    ControllerInput mapping;
} Config;

typedef struct UIListItem{
    int pointer;
    char *name;
} UIListItem;

typedef struct UIList{
    char *name;
    bool active;
    UIListItem *items;
    int item_count;
    int cursor;
    void (*func_item)();
    Vector2 size;
    Vector2 pos;
} UIList;

typedef struct UIView{
    int id;
    char *name;
    void (*init)();
    void (*active)();
    void (*draw)();
    void (*deactive)();
    void (*destroy)();
} UIView;

#define NewUiView(_ui_view, _id, _name, _init, _active, _draw, _deactive, _destroy) \
do { \
	_ui_view.id = _id; \
	_ui_view.name = _name; \
	_ui_view.init = _init; \
	_ui_view.active = _active; \
	_ui_view.draw = _draw; \
    _ui_view.deactive = _deactive; \
    _ui_view.destroy = _destroy; \
} while(0)