#include "figures.h"
#include <math.h>

Figure** figures = NULL;
int figure_counter = 0;
void AddFigure(Figure* figure)
{
    figures = (Figure**)realloc(figures, ++figure_counter * sizeof(Figure*));
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
bool CheckCollisionFigureCube(Figure *figure, Vector3 cube)
{
    if (CheckCollisionCubes(figure->block1, cube) ||
        CheckCollisionCubes(figure->block2, cube) ||
        CheckCollisionCubes(figure->block3, cube) ||
        CheckCollisionCubes(figure->block4, cube))
        return true;
    else
        return false;
}
bool CheckCollisionFigures(Figure *figure1, Figure *figure2)
{
    if (CheckCollisionFigureCube(figure1, figure2->block1) ||
        CheckCollisionFigureCube(figure1, figure2->block2) ||
        CheckCollisionFigureCube(figure1, figure2->block3) ||
        CheckCollisionFigureCube(figure1, figure2->block4))
        return true;
    else
        return false;
}
bool CheckCollisionAllFigures(Figure figure, float offsetX, float offsetY)
{
    OffsetFigureX(&figure, offsetX);
    OffsetFigureY(&figure, offsetY);
    for (int i = 0; i < figure_counter; ++i)
        if (CheckCollisionFigures(&figure, figures[i]))
            return true;
    return false;
}
bool CheckCollisionFigureX(Figure *figure, float x)
{
    if (figure->block1.x == x ||
        figure->block2.x == x ||
        figure->block3.x == x ||
        figure->block4.x == x)
        return true;
    else
        return false;
}
bool CheckCollisionFigureY(Figure *figure, float y)
{
    if (figure->block1.y == y ||
        figure->block2.y == y ||
        figure->block3.y == y ||
        figure->block4.y == y)
        return true;
    else
        return false;
}

/* Right-L Figure */
Figure* SpawnRL_1Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = RL_Type1;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){1.f, 8.f, -18.f};
    return figure;
}
Figure* SpawnRL_2Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = RL_Type2;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){-1.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}
Figure* SpawnRL_3Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = RL_Type3;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){1.f, 9.f, -18.f};
    figure->block3 = (Vector3){1.f, 8.f, -18.f};
    figure->block4 = (Vector3){0.f, 10.f, -18.f};
    return figure;
}
Figure* SpawnRL_4Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = RL_Type4;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){-1.f, 10.f, -18.f};
    figure->block4 = (Vector3){-1.f, 9.f, -18.f};
    return figure;
}


/* Left-L Figure */
Figure* SpawnLL_1Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = LL_Type1;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){1.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 8.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    return figure;
}
Figure* SpawnLL_2Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = LL_Type2;
    figure->block1 = (Vector3){-1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){-1.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}
Figure* SpawnLL_3Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = LL_Type3;
    figure->block1 = (Vector3){-1.f, 11.f, -18.f};
    figure->block2 = (Vector3){-1.f, 10.f, -18.f};
    figure->block3 = (Vector3){-1.f, 9.f, -18.f};
    figure->block4 = (Vector3){0.f, 11.f, -18.f};
    return figure;
}
Figure* SpawnLL_4Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = LL_Type4;
    figure->block1 = (Vector3){-1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){1.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 10.f, -18.f};
    return figure;
}


/* I Figure */
Figure* SpawnI_1Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = I_Type1;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){0.f, 7.f, -18.f};
    return figure;
}
Figure* SpawnI_2Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = I_Type2;
    figure->block1 = (Vector3){-1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){1.f, 10.f, -18.f};
    figure->block4 = (Vector3){2.f, 10.f, -18.f};
    return figure;
}


/* Square Figure */
Figure* SpawnSquare()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = Square_Type;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){1.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}


/* Right-Z Figure */
Figure* SpawnRZ_1Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = RZ_Type1;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){1.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 8.f, -18.f};
    return figure;
}
Figure* SpawnRZ_2Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = RZ_Type2;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 9.f, -18.f};
    figure->block4 = (Vector3){-1.f, 9.f, -18.f};
    return figure;
}


/* Left-Z Figure */
Figure* SpawnLZ_1Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = LZ_Type1;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){1.f, 9.f, -18.f};
    figure->block4 = (Vector3){0.f, 8.f, -18.f};
    return figure;
}
Figure* SpawnLZ_2Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = LZ_Type2;
    figure->block1 = (Vector3){-1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}


/* T Figure */
Figure* SpawnT_1Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = T_Type1;
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}
Figure* SpawnT_2Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = T_Type2;
    figure->block1 = (Vector3){-1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 10.f, -18.f};
    return figure;
}
Figure* SpawnT_3Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = T_Type3;
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){-1.f, 9.f, -18.f};
    return figure;
}
Figure* SpawnT_4Pos()
{
    Figure *figure = (Figure*)malloc(sizeof(Figure));
    figure->figure_type = T_Type4;
    figure->block1 = (Vector3){-1.f, 9.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 10.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}


void DrawFigure(Figure* figure, Color color)
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
Figure* OffsetFigureX(Figure* figure, float offsetX)
{
    /* X offset */
    figure->block1.x += offsetX;
    figure->block2.x += offsetX;
    figure->block3.x += offsetX;
    figure->block4.x += offsetX;
}
Figure* OffsetFigureY(Figure* figure, float offsetY)
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
Figure* RandomFigure()
{
    int figure_index = rand() % 8;
    switch (figure_index)
    {
        case 0:
            return SpawnI_1Pos();
        case 1:
            return SpawnRL_1Pos();
        case 2:
            return SpawnLL_1Pos();
        case 3:
            return SpawnT_1Pos();
        case 4:
            return SpawnSquare();
        case 5:
            return SpawnLZ_1Pos();
        default:
            return SpawnRZ_1Pos();
    }
}

bool CompleteLineHandler()
{
    Vector3 **other_blocks = (Vector3**)malloc(figure_counter * 4 * sizeof(Vector3*));
    for (int y = -9; y < 10; ++y)
    {
        Vector3 *y_blocks[10] = {};
        int count_in_row = 0;
        int other_blocks_count = 0;

        for (int i = 0; i < figure_counter; ++i)
        {
            if (figures[i] != NULL)
            {
                if ((int) figures[i]->block1.y == y)
                    y_blocks[count_in_row++] = &figures[i]->block1;
                else if ((int) figures[i]->block1.y > y)
                    other_blocks[other_blocks_count++] = &figures[i]->block1;

                if ((int) figures[i]->block2.y == y)
                    y_blocks[count_in_row++] = &figures[i]->block2;
                else if ((int) figures[i]->block2.y > y)
                    other_blocks[other_blocks_count++] = &figures[i]->block2;

                if ((int) figures[i]->block3.y == y)
                    y_blocks[count_in_row++] = &figures[i]->block3;
                else if ((int) figures[i]->block3.y > y)
                    other_blocks[other_blocks_count++] = &figures[i]->block3;

                if ((int) figures[i]->block4.y == y)
                    y_blocks[count_in_row++] = &figures[i]->block4;
                else if ((int) figures[i]->block4.y > y)
                    other_blocks[other_blocks_count++] = &figures[i]->block4;
            }
        }
        if (count_in_row == 10)
        {
            for (int i = 0; i < count_in_row; ++i)
            {
                /* Hiding blocks from the camera view */
                y_blocks[i]->x = HIDDEN;
                y_blocks[i]->y = HIDDEN;
                y_blocks[i]->z = HIDDEN;
            }
            for (int i = 0; i < other_blocks_count; ++i)
                --other_blocks[i]->y;
            free(other_blocks);
            return true;
        }
    }
    free(other_blocks);
    return false;
}
void RotateFigure(Figure** figure)
{
    /* Square can't be rotated */
    if ((*figure)->figure_type != Square_Type)
    {
        Color color = (*figure)->color;
        Figure *prev_pos = *figure;
        switch ((*figure)->figure_type)
        {
            case RL_Type1:
                *figure = SpawnRL_2Pos();
                break;
            case RL_Type2:
                *figure = SpawnRL_3Pos();
                break;
            case RL_Type3:
                *figure = SpawnRL_4Pos();
                break;
            case RL_Type4:
                *figure = SpawnRL_1Pos();
                break;
            case LL_Type1:
                *figure = SpawnLL_2Pos();
                break;
            case LL_Type2:
                *figure = SpawnLL_3Pos();
                break;
            case LL_Type3:
                *figure = SpawnLL_4Pos();
                break;
            case LL_Type4:
                *figure = SpawnLL_1Pos();
                break;
            case T_Type1:
                *figure = SpawnT_2Pos();
                break;
            case T_Type2:
                *figure = SpawnT_3Pos();
                break;
            case T_Type3:
                *figure = SpawnT_4Pos();
                break;
            case T_Type4:
                *figure = SpawnT_1Pos();
                break;
            case I_Type1:
                *figure = SpawnI_2Pos();
                break;
            case I_Type2:
                *figure = SpawnI_1Pos();
                break;
            case RZ_Type1:
                *figure = SpawnRZ_2Pos();
                break;
            case RZ_Type2:
                *figure = SpawnRZ_1Pos();
                break;
            case LZ_Type1:
                *figure = SpawnLZ_2Pos();
                break;
            case LZ_Type2:
                *figure = SpawnLZ_1Pos();
                break;
        }

        (*figure)->color = color;

        OffsetFigureX(*figure, prev_pos->block2.x);
        OffsetFigureY(*figure, -abs((*figure)->block2.y - prev_pos->block2.y));

        while (true)
        {
            bool is_left_border = CheckCollisionFigureX(*figure, -5.f);
            bool is_right_border = CheckCollisionFigureX(*figure, 6.f);
            
            if (is_left_border || is_right_border)
            {
                if (is_left_border)     /* Push right if figure is on the left border */
                    OffsetFigureX(*figure, 1.f);
                if (is_right_border)    /* Push left if figure is on the right border */
                    OffsetFigureX(*figure, -1.f);
            }
            else break;
        }

        if (CheckCollisionFigureY(*figure, -10.f)       || /* If figure is on the bottom border */
        CheckCollisionAllFigures(**figure, 0.f, 0.f))      /* If figure is on the other figure */
        *figure = prev_pos;
    }
}
