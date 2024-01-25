#include "env.h"

void DrawBackground()
{
    ClearBackground(RAYWHITE);
    /* Gradient as a background */
    DrawCircleGradient(SCREEN_WIDTH / 2,
                       SCREEN_HEIGHT / 2,
                       (float)SCREEN_WIDTH,
                       (Color){123, 32, 43, 255},
                       (Color){23, 12, 43, 255});
}

void InitWalls()
{
    walls.left = (Vector3){5.75f, 0.5f, -18.f};
    walls.right = (Vector3){-4.75f, 0.5f, -18.f};
    walls.up = (Vector3){0.5f, 11.f, -18.f};
    walls.down = (Vector3){0.5f, -10.f, -18.f};
    walls.color = GRAY;
    walls.wires_color = BLACK;
}

void DrawWalls()
{
    DrawCube(walls.up, 11.5f, 1.f, 1.f, walls.color);
    DrawCubeWires(walls.up, 11.5f, 1.f, 1.f, walls.wires_color);

    DrawCube(walls.down, 11.5f, 1.f, 1.f, walls.color);
    DrawCubeWires(walls.down, 11.5f, 1.f, 1.f, walls.wires_color);

    DrawCube(walls.left, 0.5f, 20.f, 1.f, walls.color);
    DrawCubeWires(walls.left, 0.5f, 20.f, 1.f, walls.wires_color);

    DrawCube(walls.right, 0.5f, 20.f, 1.f, walls.color);
    DrawCubeWires(walls.right, 0.5f, 20.f, 1.f, walls.wires_color);
}

void DrawFieldGrid(Figure *active_figure)
{
    Color color;
    for (int y = -9; y <= 10; ++y)
    {
        for (int x = -4; x <= 5; ++x)
        {
            if (CheckCollisionFigureX(active_figure, (float)x))
                color = MAROON;
            else
                color = ColorAlpha(GRAY, 0.08f);

            DrawCubeWires((Vector3){x, y, -18.5f}, 1.f, 1.f, 0.f, color);
        }
    }
}