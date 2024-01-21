#ifndef GAME_H
#define GAME_H

#include "init.h"


struct Walls
{
    Vector3 up;
    Vector3 down;
    Vector3 left;
    Vector3 right;
    Color color;
    Color wires_color;
};

static int SCREEN_WIDTH;
static int SCREEN_HEIGHT;
static Camera3D camera;
static struct Walls walls;

void run();
void startup();
void update();
void event_handler();
void render2D();
void render3D();
void unloading();

#endif //GAME_H
