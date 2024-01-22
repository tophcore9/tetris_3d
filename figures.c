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
    if (CheckCollisionFigureCube(figure1, figure2->block1) ||
        CheckCollisionFigureCube(figure1, figure2->block2) ||
        CheckCollisionFigureCube(figure1, figure2->block3) ||
        CheckCollisionFigureCube(figure1, figure2->block4))
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

struct Figure* SpawnRL()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-4.f, 10.f, -18.f};
    figure->block2 = (Vector3){-4.f, 9.f, -18.f};
    figure->block3 = (Vector3){-4.f, 8.f, -18.f};
    figure->block4 = (Vector3){-3.f, 8.f, -18.f};
    return figure;
}
struct Figure* SpawnLL()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-3.f, 10.f, -18.f};
    figure->block2 = (Vector3){-3.f, 9.f, -18.f};
    figure->block3 = (Vector3){-3.f, 8.f, -18.f};
    figure->block4 = (Vector3){-4.f, 8.f, -18.f};
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
    int figure_index = rand() % 7;
    switch (figure_index)
    {
        case 0:
            return SpawnI();
        case 1:
            return SpawnRL();
        case 2:
            return SpawnLL();
        case 3:
            return SpawnT();
        case 4:
            return SpawnSquare();
        default:
            return SpawnZ();
    }
}

int CheckRows()
{
    int y;
        for (y = -9; y < 10; ++y)
        {
            int count_in_row = 0;
            Vector3 *y_blocks[10];
            for (int i = 0; i < figure_counter; ++i)
            {
                if ((int) figures[i]->block1.y == y)
                {
                    y_blocks[count_in_row] = &figures[i]->block1;
                    ++count_in_row;
                }
                if ((int) figures[i]->block2.y == y)
                {
                    y_blocks[count_in_row] = &figures[i]->block2;
                    ++count_in_row;
                }
                if ((int) figures[i]->block3.y == y)
                {
                    y_blocks[count_in_row] = &figures[i]->block3;
                    ++count_in_row;
                }
                if ((int) figures[i]->block4.y == y)
                {
                    y_blocks[count_in_row] = &figures[i]->block4;
                    ++count_in_row;
                }
            }
            if (count_in_row == 10)
            {
                for (int i = 0; i < count_in_row; ++i)
                {
                    y_blocks[i]->y = 100;
                    y_blocks[i]->x = 100;
                    y_blocks[i]->z = 100;
                }
                return y;
            }
        }
    return 100;
}
