#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include "env.h"


static int SCREEN_WIDTH;
static int SCREEN_HEIGHT;
static Camera3D camera;

void run();
void startup();
void update();
void event_handler();
void render2D();
void unloading();

#endif //TETRIS_GAME_H
