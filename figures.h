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

typedef struct Figure Figure;
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

void DrawFigure(Figure* figure, Color color);
Figure* SpawnRL_1Pos();
Figure* SpawnRL_2Pos();
Figure* SpawnRL_3Pos();
Figure* SpawnRL_4Pos();
Figure* SpawnLL_1Pos();
Figure* SpawnLL_2Pos();
Figure* SpawnLL_3Pos();
Figure* SpawnLL_4Pos();
Figure* SpawnI_1Pos();
Figure* SpawnI_2Pos();
Figure* SpawnSquare();
Figure* SpawnRZ_1Pos();
Figure* SpawnRZ_2Pos();
Figure* SpawnLZ_1Pos();
Figure* SpawnLZ_2Pos();
Figure* SpawnT_1Pos();
Figure* SpawnT_2Pos();
Figure* SpawnT_3Pos();
Figure* SpawnT_4Pos();
void AddFigure(Figure* figure);
void RotateFigure(Figure** figure);
void RemoveFigures();


Figure* OffsetFigureX(Figure* figure, float offsetX);
Figure* OffsetFigureY(Figure* figure, float offsetY);

Color RandomColor();
Figure* RandomFigure();

#endif //TETRIS_FIGURES_H