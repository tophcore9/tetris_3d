#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "env.h"
#include "figures.h"

#define DEBUG

static Camera3D camera;
static Color randomized;

#ifdef DEBUG
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
