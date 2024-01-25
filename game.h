#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <string.h>
#include "env.h"
#include "figures.h"

//#define DEBUG_MODE

extern Camera3D camera;
extern Figure* current_figure;
extern float game_speed_active;
extern float game_speed_default;
extern bool is_game_over;
extern Music music;
extern int score;
extern float streak_k;
extern int complete_lines;

#ifdef DEBUG_MODE
static Vector3 cube;
static char x_pos[12];
static char y_pos[12];
static char z_pos[12];
#endif

void run();
void startup();
void update();
void event_handler();
void render();
void unloading();

#endif //TETRIS_GAME_H
