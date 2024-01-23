#ifndef TETRIS_ENV_H
#define TETRIS_ENV_H

#include <raylib.h>
#include <stdio.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

typedef struct Walls Walls;
static struct Walls
{
    Vector3 up;
    Vector3 down;
    Vector3 left;
    Vector3 right;
    Color color;
    Color wires_color;
} walls;

void InitWalls();
void DrawWalls();
void DrawBackground();
Walls* GetWalls();

#endif //TETRIS_ENV_H
