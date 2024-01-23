#ifndef TETRIS_FIGURES_H
#define TETRIS_FIGURES_H

#include "env.h"
#include <stdlib.h>
#include <time.h>

#define HIDDEN 100

enum FigureType
{
    Square_Type,
    RL_Type1,
    RL_Type2,
    RL_Type3,
    RL_Type4,
    LL_Type1,
    LL_Type2,
    LL_Type3,
    LL_Type4,
    T_Type1,
    T_Type2,
    T_Type3,
    T_Type4,
    I_Type1,
    I_Type2,
    RZ_Type1,
    RZ_Type2,
    LZ_Type1,
    LZ_Type2
};

struct Figure
{
    Vector3 block1;
    Vector3 block2;
    Vector3 block3;
    Vector3 block4;
    Color color;
    enum FigureType figure_type;
};

extern struct Figure** figures;
extern int figure_counter;

bool CheckCollisionCubes(Vector3 cube1, Vector3 cube2);
bool CheckCollisionFigureCube(struct Figure *figure, Vector3 cube);
bool CheckCollisionFigures(struct Figure *figure1, struct Figure *figure2);
bool CheckCollisionAllFigures(struct Figure figure, float offsetX, float offsetY);
bool CheckCollisionFigureX(struct Figure *figure, float x);
bool CheckCollisionFigureY(struct Figure *figure, float y);
bool CompleteLineHandler();

void DrawFigure(struct Figure* figure, Color color);
struct Figure* SpawnRL_1Pos();
struct Figure* SpawnRL_2Pos();
struct Figure* SpawnRL_3Pos();
struct Figure* SpawnRL_4Pos();
struct Figure* SpawnLL_1Pos();
struct Figure* SpawnLL_2Pos();
struct Figure* SpawnLL_3Pos();
struct Figure* SpawnLL_4Pos();
struct Figure* SpawnI_1Pos();
struct Figure* SpawnI_2Pos();
struct Figure* SpawnSquare();
struct Figure* SpawnRZ_1Pos();
struct Figure* SpawnRZ_2Pos();
struct Figure* SpawnLZ_1Pos();
struct Figure* SpawnLZ_2Pos();
struct Figure* SpawnT_1Pos();
struct Figure* SpawnT_2Pos();
struct Figure* SpawnT_3Pos();
struct Figure* SpawnT_4Pos();
void AddFigure(struct Figure* figure);
void RotateFigure(struct Figure** figure);


struct Figure* OffsetFigureX(struct Figure* figure, float offsetX);
struct Figure* OffsetFigureY(struct Figure* figure, float offsetY);

Color RandomColor();
struct Figure* RandomFigure();

#endif //TETRIS_FIGURES_H