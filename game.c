#include "game.h"

void run()
{
    startup();
    update();
    unloading();
}

void startup()
{
    SCREEN_WIDTH = 600;
    SCREEN_HEIGHT = 800;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");

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
        render2D();
    }
}
void render2D()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        /* Gradient as a background */
        DrawCircleGradient(SCREEN_WIDTH / 2,
                           SCREEN_HEIGHT / 2,
                           (float)SCREEN_WIDTH,
                           (Color){123, 32, 43, 255},
                           (Color){23, 12, 43, 255});
        event_handler();
        BeginMode3D(camera);
            DrawWalls();
        EndMode3D();
    EndDrawing();
}
void event_handler()
{
    if (IsKeyDown(KEY_SPACE))
        DrawText("Good", 0, 0, 40, GRAY);
    else if (IsKeyPressed(KEY_UP))
        GetWalls()->up.y += 1.f;
    else if (IsKeyPressed(KEY_DOWN))
        GetWalls()->up.y -= 1.f;
    else if (IsKeyPressed(KEY_LEFT))
        GetWalls()->up.x -= 1.f;
    else if (IsKeyPressed(KEY_RIGHT))
        GetWalls()->up.x += 1.f;
}
void unloading()
{
    CloseWindow();
}