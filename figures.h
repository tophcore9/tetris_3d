#ifndef TETRIS_FIGURES_H
#define TETRIS_FIGURES_H

#include "env.h"
#include <stdlib.h>

struct Figure
{
    Vector3 block1;
    Vector3 block2;
    Vector3 block3;
    Vector3 block4;
};

bool CheckCollisionCubes(Vector3 cube1, Vector3 cube2);
void DrawFigure(struct Figure* figure, float offsetX, float offsetY);
struct Figure* SpawnL();
struct Figure* SpawnI();
struct Figure* SpawnSquare();
struct Figure* SpawnZ();
struct Figure* SpawnT();

#endif //TETRIS_FIGURES_H