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

    walls.left = (Vector3){5.75f, 0.5f, -18.f};
    walls.right = (Vector3){-4.75f, 0.5f, -18.f};
    walls.up = (Vector3){0.5f, 11.f, -18.f};
    walls.down = (Vector3){0.5f, -10.f, -18.f};
    walls.color = GRAY;
    walls.wires_color = BLACK;

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
        render3D();
    EndDrawing();
}
void render3D()
{
    BeginMode3D(camera);
        DrawCube(walls.up, 11.5f, 1.f, 1.f, walls.color);
        DrawCubeWires(walls.up, 11.5f, 1.f, 1.f, walls.wires_color);

        DrawCube(walls.down, 11.5f, 1.f, 1.f, walls.color);
        DrawCubeWires(walls.down, 11.5f, 1.f, 1.f, walls.wires_color);

        DrawCube(walls.left, 0.5f, 20.f, 1.f, walls.color);
        DrawCubeWires(walls.left, 0.5f, 20.f, 1.f, walls.wires_color);

        DrawCube(walls.right, 0.5f, 20.f, 1.f, walls.color);
        DrawCubeWires(walls.right, 0.5f, 20.f, 1.f, walls.wires_color);
    EndMode3D();
}
void event_handler()
{
    if (IsKeyDown(KEY_SPACE))
        DrawText("Good", 0, 0, 40, GRAY);
    else if (IsKeyPressed(KEY_UP))
        walls.up.y += 1.f;
    else if (IsKeyPressed(KEY_DOWN))
        walls.up.y -= 1.f;
    else if (IsKeyPressed(KEY_LEFT))
        walls.up.x -= 1.f;
    else if (IsKeyPressed(KEY_RIGHT))
        walls.up.x += 1.f;
}
void unloading()
{
    CloseWindow();
}