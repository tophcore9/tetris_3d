#include "game.h"

Camera3D camera = {};
Color current_color = {};
struct Figure *current_figure = {};

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
    current_color = RandomColor();
    current_figure = RandomFigure();

#ifdef DEBUG_MODE
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
#ifdef DEBUG_MODE
            DrawFigure(current_figure, 0, 0, current_color);
            DrawCubeWires(cube, 1.f, 1.f, 1.f, LIME);
#endif
            DrawFigure(current_figure, current_color);
            DrawWalls();
        EndMode3D();

#ifdef DEBUG_MODE
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
#ifdef DEBUG_MODE
    if (IsKeyPressed(KEY_UP))
        cube.y += 1.f;
    else if (IsKeyPressed(KEY_DOWN))
        cube.y -= 1.f;
    else if (IsKeyPressed(KEY_LEFT))
        cube.x -= 1.f;
    else if (IsKeyPressed(KEY_RIGHT))
        cube.x += 1.f;
#endif
    if (IsKeyPressed(KEY_UP))
        OffsetFigureY(current_figure, 1.f);
    else if (IsKeyPressed(KEY_DOWN))
        OffsetFigureY(current_figure, -1.f);
    else if (IsKeyPressed(KEY_LEFT))
        OffsetFigureX(current_figure, -1.f);
    else if (IsKeyPressed(KEY_RIGHT))
        OffsetFigureX(current_figure, 1.f);
}
void unloading()
{ CloseWindow(); }