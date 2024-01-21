#include "game.h"

void run()
{
    startup();
    update();
    unloading();
}

void startup()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");

    /* FOR DEBUG BEGIN */
    cube = (Vector3){1.f, 11.f, -18.f};
    /* FOR DEBUG END */

    camera.target = (Vector3){0.5f, 1.0f, 0.0f};
    camera.position = (Vector3){0.5f, 1.25f, 10.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};

    InitWalls();

    DisableCursor();
    SetTargetFPS(60);
}
void update()
{
    while (!WindowShouldClose())
    {
        render();
    }
}
void render()
{
    BeginDrawing();
        DrawBackground();
        event_handler();

        BeginMode3D(camera);
            /* FOR DEBUG BEGIN */
            DrawFigure(SpawnI(), 2, -5);
            DrawFigure(SpawnZ(), 5, -2);
            DrawFigure(SpawnSquare(), 2, 0);
            DrawFigure(SpawnT(), -1, -5);
            DrawCubeWires(cube, 1.f, 1.f, 1.f, LIME);
            /* FOR DEBUG END */

            DrawWalls();
        EndMode3D();

        /* FOR DEBUG BEGIN */
        snprintf(x_pos, 12, "X: %f", cube.x);
        snprintf(y_pos, 12, "Y: %f", cube.y);
        snprintf(z_pos, 12, "Z: %f", cube.z);
        DrawText(x_pos, 0, 0, 20, WHITE);
        DrawText(y_pos, 0, 20, 20, WHITE);
        DrawText(z_pos, 0, 40, 20, WHITE);
        /* FOR DEBUG END */
    EndDrawing();
}
void event_handler()
{
    if (IsKeyPressed(KEY_UP))
        cube.y += 1.f;
    else if (IsKeyPressed(KEY_DOWN))
        cube.y -= 1.f;
    else if (IsKeyPressed(KEY_LEFT))
        cube.x -= 1.f;
    else if (IsKeyPressed(KEY_RIGHT))
        cube.x += 1.f;
}
void unloading()
{ CloseWindow(); }