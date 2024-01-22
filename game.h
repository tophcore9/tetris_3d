#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "env.h"
#include "figures.h"

//#define DEBUG_MODE

extern Camera3D camera;
//extern Color current_color;
extern struct Figure* current_figure;
extern float game_speed_active;
extern float game_speed_default;

#ifdef DEBUG_MODE
static Vector3 cube;
static char x_pos[12];
static char* y_pos[12];
static char* z_pos[12];
#endif

void run();
void startup();
void update();
void event_handler();
void render();
void unloading();

#endif //TETRIS_GAME_H
