#include "figures.h"

struct Figure** figures = NULL;
int figure_counter = 0;
void AddFigure(struct Figure* figure)
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

/* Right-L Figure */
struct Figure* SpawnRL_1Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = RL_Type1;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){1.f, 8.f, -18.f};
    return figure;
}
struct Figure* SpawnRL_2Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = RL_Type3;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){-1.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}
struct Figure* SpawnRL_3Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = RL_Type4;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){1.f, 9.f, -18.f};
    figure->block3 = (Vector3){1.f, 8.f, -18.f};
    figure->block4 = (Vector3){0.f, 10.f, -18.f};
    return figure;
}
struct Figure* SpawnRL_4Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = RL_Type2;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){-1.f, 10.f, -18.f};
    figure->block4 = (Vector3){-1.f, 9.f, -18.f};
    return figure;
}


/* Left-L Figure */
struct Figure* SpawnLL_1Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = LL_Type1;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){1.f, 9.f, -18.f};
    figure->block3 = (Vector3){1.f, 8.f, -18.f};
    figure->block4 = (Vector3){0.f, 8.f, -18.f};
    return figure;
}
struct Figure* SpawnLL_2Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = LL_Type2;
    figure->block1 = (Vector3){2.f, 9.f, -18.f};
    figure->block2 = (Vector3){1.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 9.f, -18.f};
    figure->block4 = (Vector3){0.f, 10.f, -18.f};
    return figure;
}
struct Figure* SpawnLL_3Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = LL_Type3;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){1.f, 10.f, -18.f};
    return figure;
}
struct Figure* SpawnLL_4Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = LL_Type4;
    figure->block1 = (Vector3){2.f, 8.f, -18.f};
    figure->block2 = (Vector3){2.f, 9.f, -18.f};
    figure->block3 = (Vector3){1.f, 9.f, -18.f};
    figure->block4 = (Vector3){0.f, 9.f, -18.f};
    return figure;
}


/* I Figure */
struct Figure* SpawnI_1Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = I_Type1;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){0.f, 7.f, -18.f};
    return figure;
}
struct Figure* SpawnI_2Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = I_Type2;
    figure->block1 = (Vector3){-1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){1.f, 10.f, -18.f};
    figure->block4 = (Vector3){2.f, 10.f, -18.f};
    return figure;
}


/* Square Figure */
struct Figure* SpawnSquare()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = Square_Type;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){1.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}


/* Right-Z Figure */
struct Figure* SpawnRZ_1Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = RZ_Type1;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){1.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 8.f, -18.f};
    return figure;
}
struct Figure* SpawnRZ_2Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = RZ_Type2;
    figure->block1 = (Vector3){2.f, 10.f, -18.f};
    figure->block2 = (Vector3){1.f, 10.f, -18.f};
    figure->block3 = (Vector3){1.f, 9.f, -18.f};
    figure->block4 = (Vector3){0.f, 9.f, -18.f};
    return figure;
}


/* Left-Z Figure */
struct Figure* SpawnLZ_1Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = LZ_Type1;
    figure->block1 = (Vector3){1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){1.f, 9.f, -18.f};
    figure->block4 = (Vector3){0.f, 8.f, -18.f};
    return figure;
}
struct Figure* SpawnLZ_2Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = LZ_Type2;
    figure->block1 = (Vector3){-1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}


/* T Figure */
struct Figure* SpawnT_1Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = T_Type1;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
    return figure;
}
struct Figure* SpawnT_2Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = T_Type2;
    figure->block1 = (Vector3){-1.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 10.f, -18.f};
    figure->block3 = (Vector3){0.f, 9.f, -18.f};
    figure->block4 = (Vector3){1.f, 10.f, -18.f};
    return figure;
}
struct Figure* SpawnT_3Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = T_Type3;
    figure->block1 = (Vector3){0.f, 10.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){-1.f, 9.f, -18.f};
    return figure;
}
struct Figure* SpawnT_4Pos()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->figure_type = T_Type4;
    figure->block1 = (Vector3){-1.f, 9.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){0.f, 10.f, -18.f};
    figure->block4 = (Vector3){1.f, 9.f, -18.f};
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
            return SpawnI_1Pos();
        case 1:
            return SpawnRL_1Pos();
        case 2:
            return SpawnLL_1Pos();
        case 3:
            return SpawnT_1Pos();
        case 4:
            return SpawnSquare();
        default:
            return SpawnRZ_1Pos();
    }
}

bool CompleteLineHandler()
{
    int y;
        for (y = -9; y < 10; ++y)
        {
            int count_in_row = 0;
            int other_blocks_count = 0;
            Vector3 *y_blocks[10] = {};
            Vector3 *other_blocks[200] = {};

            for (int i = 0; i < figure_counter; ++i)
            {
                if ((int) figures[i]->block1.y == y)
                    y_blocks[count_in_row++] = &figures[i]->block1;
                else if ((int)figures[i]->block1.y > y)
                    other_blocks[other_blocks_count++] = &figures[i]->block1;

                if ((int) figures[i]->block2.y == y)
                    y_blocks[count_in_row++] = &figures[i]->block2;
                else if ((int)figures[i]->block2.y > y)
                    other_blocks[other_blocks_count++] = &figures[i]->block2;

                if ((int) figures[i]->block3.y == y)
                    y_blocks[count_in_row++] = &figures[i]->block3;
                else if ((int)figures[i]->block3.y > y)
                    other_blocks[other_blocks_count++] = &figures[i]->block3;

                if ((int) figures[i]->block4.y == y)
                    y_blocks[count_in_row++] = &figures[i]->block4;
                else if ((int)figures[i]->block4.y > y)
                    other_blocks[other_blocks_count++] = &figures[i]->block4;
            }
            if (count_in_row == 10)
            {
                for (int i = 0; i < count_in_row; ++i)
                {
                    /* Hiding blocks from the camera view */
                    y_blocks[i]->y = 100;
                    y_blocks[i]->x = 100;
                    y_blocks[i]->z = 100;
                }
                for (int i = 0; i < other_blocks_count; ++i)
                    --other_blocks[i]->y;
                return true;
            }
        }
    return false;
}
Vector3 GetFigureCenter(struct Figure* figure)
{
//    switch (figure->figure_type)
//    {
//        case RL_Type:
//        case LL_Type:
//        case T_Type:
//        case I_Type:
//            return figure->block2;
//        case Z_Type:
//            return figure->block2;
//    }
}
void RotateFigure(struct Figure** figure)
{
    /* Square can't be rotated */
    if ((*figure)->figure_type != Square_Type)
    {
        Color color = (*figure)->color;
        float y_offset = (*figure)->block1.y;
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
                *figure = SpawnRZ_2Pos();
                break;
            case LZ_Type2:
                *figure = SpawnRZ_1Pos();
                break;
        }

        (*figure)->color = color;
        for (int i = 10; i > y_offset; --i)
            OffsetFigureY(*figure, -1.f);
    }
}
