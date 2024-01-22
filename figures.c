#include "figures.h"

struct Figure** figures = NULL;
int figure_counter = 0;
void add_figure(struct Figure* figure)
{
    figures = (struct Figure**)realloc(figures, ++figure_counter * sizeof(struct Figure**));
    figures[figure_counter - 1] = figure;
}

bool CheckCollisionCubes(Vector3 cube1, Vector3 cube2)
{
    if (cube1.x == cube2.x &&
        cube1.y == cube2.y &&
        cube1.z == cube2.z)
        return true;
    else
        return false;
}
bool CheckCollisionFigureCube(struct Figure *figure, Vector3 cube)
{
    if (CheckCollisionCubes(figure->block1, cube) ||
        CheckCollisionCubes(figure->block2, cube) ||
        CheckCollisionCubes(figure->block3, cube) ||
        CheckCollisionCubes(figure->block4, cube))
        return true;
    else
        return false;
}
bool CheckCollisionFigures(struct Figure *figure1, struct Figure *figure2)
{
    if (CheckCollisionCubes(figure1->block1, figure2->block1) ||
        CheckCollisionCubes(figure1->block1, figure2->block2) ||
        CheckCollisionCubes(figure1->block1, figure2->block3) ||
        CheckCollisionCubes(figure1->block1, figure2->block4) ||
        CheckCollisionCubes(figure1->block2, figure2->block1) ||
        CheckCollisionCubes(figure1->block2, figure2->block2) ||
        CheckCollisionCubes(figure1->block2, figure2->block3) ||
        CheckCollisionCubes(figure1->block2, figure2->block4) ||
        CheckCollisionCubes(figure1->block3, figure2->block1) ||
        CheckCollisionCubes(figure1->block3, figure2->block2) ||
        CheckCollisionCubes(figure1->block3, figure2->block3) ||
        CheckCollisionCubes(figure1->block3, figure2->block4) ||
        CheckCollisionCubes(figure1->block4, figure2->block1) ||
        CheckCollisionCubes(figure1->block4, figure2->block2) ||
        CheckCollisionCubes(figure1->block4, figure2->block3) ||
        CheckCollisionCubes(figure1->block4, figure2->block4))
        return true;
    else
        return false;
}
bool CheckCollisionAllFigures(struct Figure figure, float offsetX, float offsetY)
{
    OffsetFigureX(&figure, offsetX);
    OffsetFigureY(&figure, offsetY);
    for (int i = 0; i < figure_counter; ++i)
        if (CheckCollisionFigures(&figure, figures[i]))
            return true;
    return false;
}
bool CheckCollisionFigureX(struct Figure *figure, float x)
{
    if (figure->block1.x == x ||
        figure->block2.x == x ||
        figure->block3.x == x ||
        figure->block4.x == x)
        return true;
    else
        return false;
}
bool CheckCollisionFigureY(struct Figure *figure, float y)
{
    if (figure->block1.y == y ||
        figure->block2.y == y ||
        figure->block3.y == y ||
        figure->block4.y == y)
        return true;
    else
        return false;
}

struct Figure* SpawnL()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-4.f, 10.f, -18.f};
    figure->block2 = (Vector3){-4.f, 9.f, -18.f};
    figure->block3 = (Vector3){-4.f, 8.f, -18.f};
    figure->block4 = (Vector3){-3.f, 8.f, -18.f};
    return figure;
}
struct Figure* SpawnI()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-4.f, 10.f, -18.f};
    figure->block2 = (Vector3){-4.f, 9.f, -18.f};
    figure->block3 = (Vector3){-4.f, 8.f, -18.f};
    figure->block4 = (Vector3){-4.f, 7.f, -18.f};
    return figure;
}
struct Figure* SpawnSquare()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-4.f, 10.f, -18.f};
    figure->block2 = (Vector3){-3.f, 10.f, -18.f};
    figure->block3 = (Vector3){-4.f, 9.f, -18.f};
    figure->block4 = (Vector3){-3.f, 9.f, -18.f};
    return figure;
}
struct Figure* SpawnZ()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-4.f, 10.f, -18.f};
    figure->block2 = (Vector3){-4.f, 9.f, -18.f};
    figure->block3 = (Vector3){-3.f, 9.f, -18.f};
    figure->block4 = (Vector3){-3.f, 8.f, -18.f};
    return figure;
}
struct Figure* SpawnT()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-4.f, 10.f, -18.f};
    figure->block2 = (Vector3){-4.f, 9.f, -18.f};
    figure->block3 = (Vector3){-4.f, 8.f, -18.f};
    figure->block4 = (Vector3){-3.f, 9.f, -18.f};
    return figure;
}
void DrawFigure(struct Figure* figure, Color color)
{
    DrawCube(figure->block1, 1.f, 1.f, 1.f, color);
    DrawCubeWires(figure->block1, 1.f, 1.f, 1.f, BLACK);
    DrawCube(figure->block2, 1.f, 1.f, 1.f, color);
    DrawCubeWires(figure->block2, 1.f, 1.f, 1.f, BLACK);
    DrawCube(figure->block3, 1.f, 1.f, 1.f, color);
    DrawCubeWires(figure->block3, 1.f, 1.f, 1.f, BLACK);
    DrawCube(figure->block4, 1.f, 1.f, 1.f, color);
    DrawCubeWires(figure->block4, 1.f, 1.f, 1.f, BLACK);
}
struct Figure* OffsetFigureX(struct Figure* figure, float offsetX)
{
    /* X offset */
    figure->block1.x += offsetX;
    figure->block2.x += offsetX;
    figure->block3.x += offsetX;
    figure->block4.x += offsetX;
}
struct Figure* OffsetFigureY(struct Figure* figure, float offsetY)
{
    /* Y offset */
    figure->block1.y += offsetY;
    figure->block2.y += offsetY;
    figure->block3.y += offsetY;
    figure->block4.y += offsetY;
}

Color RandomColor()
{
    int color_index = rand() % 6;
    switch (color_index)
    {
        case 0:
            return RED;
        case 1:
            return GREEN;
        case 2:
            return YELLOW;
        case 3:
            return BLUE;
        case 4:
            return ORANGE;
        default:
            return PURPLE;
    }
}
struct Figure* RandomFigure()
{
    int figure_index = rand() % 6;
    switch (figure_index)
    {
        case 0:
            return SpawnI();
        case 1:
            return SpawnL();
        case 2:
            return SpawnSquare();
        case 3:
            return SpawnT();
        default:
            return SpawnZ();
    }
}
