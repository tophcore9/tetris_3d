#include "figures.h"

bool CheckCollisionCubes(Vector3 cube1, Vector3 cube2)
{
    if (cube1.x == cube2.x &&
        cube1.y == cube2.y &&
        cube1.z == cube2.z)
        return true;
    else
        return false;
}
struct Figure* SpawnL()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-1.f, 9.f, -18.f};
    figure->block2 = (Vector3){-1.f, 8.f, -18.f};
    figure->block3 = (Vector3){-1.f, 7.f, -18.f};
    figure->block4 = (Vector3){0.f, 7.f, -18.f};
    return figure;
}
struct Figure* SpawnI()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-1.f, 9.f, -18.f};
    figure->block2 = (Vector3){-1.f, 8.f, -18.f};
    figure->block3 = (Vector3){-1.f, 7.f, -18.f};
    figure->block4 = (Vector3){-1.f, 6.f, -18.f};
    return figure;
}
struct Figure* SpawnSquare()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-1.f, 9.f, -18.f};
    figure->block2 = (Vector3){0.f, 9.f, -18.f};
    figure->block3 = (Vector3){-1.f, 8.f, -18.f};
    figure->block4 = (Vector3){0.f, 8.f, -18.f};
    return figure;
}
struct Figure* SpawnZ()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-1.f, 9.f, -18.f};
    figure->block2 = (Vector3){-1.f, 8.f, -18.f};
    figure->block3 = (Vector3){0.f, 8.f, -18.f};
    figure->block4 = (Vector3){0.f, 7.f, -18.f};
    return figure;
}
struct Figure* SpawnT()
{
    struct Figure *figure = (struct Figure*)malloc(sizeof(struct Figure));
    figure->block1 = (Vector3){-1.f, 9.f, -18.f};
    figure->block2 = (Vector3){-1.f, 8.f, -18.f};
    figure->block3 = (Vector3){-1.f, 7.f, -18.f};
    figure->block4 = (Vector3){0.f, 8.f, -18.f};
    return figure;
}
void DrawFigure(struct Figure* figure, float offsetX, float offsetY)
{
    /* X offset */
    figure->block1.x += offsetX;
    figure->block2.x += offsetX;
    figure->block3.x += offsetX;
    figure->block4.x += offsetX;

    /* Y offset */
    figure->block1.y += offsetY;
    figure->block2.y += offsetY;
    figure->block3.y += offsetY;
    figure->block4.y += offsetY;

    DrawCube(figure->block1, 1.f, 1.f, 1.f, RED);
    DrawCubeWires(figure->block1, 1.f, 1.f, 1.f, BLACK);
    DrawCube(figure->block2, 1.f, 1.f, 1.f, RED);
    DrawCubeWires(figure->block2, 1.f, 1.f, 1.f, BLACK);
    DrawCube(figure->block3, 1.f, 1.f, 1.f, RED);
    DrawCubeWires(figure->block3, 1.f, 1.f, 1.f, BLACK);
    DrawCube(figure->block4, 1.f, 1.f, 1.f, RED);
    DrawCubeWires(figure->block4, 1.f, 1.f, 1.f, BLACK);
}
