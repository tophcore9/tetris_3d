#include "game.h"

void run()
{
    startup();
    update();
    unloading();
}

void startup()
{
    srand(time(NULL));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    randomized = RandomColor();

#ifdef DEBUG
    cube = (Vector3){-4.f, 10.f, -18.f};
#endif

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
        event_handler();
    }
}
void render()
{
    BeginDrawing();
        DrawBackground();

        BeginMode3D(camera);
#ifdef DEBUG
            DrawFigure(SpawnI(), 2, -5, randomized);
            DrawFigure(SpawnZ(), 5, -2, randomized);
            DrawFigure(SpawnSquare(), 2, 0, randomized);
            DrawFigure(SpawnT(), -1, -5, randomized);
            DrawCubeWires(cube, 1.f, 1.f, 1.f, LIME);
#endif

            DrawWalls();
        EndMode3D();

#ifdef DEBUG
        snprintf(x_pos, 12, "X: %f", cube.x);
        snprintf(y_pos, 12, "Y: %f", cube.y);
        snprintf(z_pos, 12, "Z: %f", cube.z);
        DrawText(x_pos, 0, 0, 20, WHITE);
        DrawText(y_pos, 0, 20, 20, WHITE);
        DrawText(z_pos, 0, 40, 20, WHITE);
#endif
    EndDrawing();
}
void event_handler()
{
#ifdef DEBUG
    if (IsKeyPressed(KEY_UP))
        cube.y += 1.f;
    else if (IsKeyPressed(KEY_DOWN))
        cube.y -= 1.f;
    else if (IsKeyPressed(KEY_LEFT))
        cube.x -= 1.f;
    else if (IsKeyPressed(KEY_RIGHT))
        cube.x += 1.f;
#endif
}
void unloading()
{ CloseWindow(); }