#include "game.h"

Camera3D camera = {};
//Color current_color = {};
struct Figure *current_figure = {};
float game_speed_active = 0.4f;
float game_speed_default = 0.4f;

void run()
{
    startup();
    update();
    unloading();
}

void startup()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    srand(time(NULL));

    figures = (struct Figure*)malloc(sizeof(struct Figure*));

//    current_color = RandomColor();
    current_figure = RandomFigure();
    current_figure->color = RandomColor();

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
    clock_t startTime = clock();
    float elapsedTime;

    /* Main cycle */
    while (!WindowShouldClose())
    {
        elapsedTime = (float)(clock() - startTime) / CLOCKS_PER_SEC;
        if (elapsedTime >= game_speed_active) /* Every 400 ms */
        {
            if (CheckCollisionFigureY(current_figure, -9.f) || CheckCollisionAllFigures(*current_figure, 0, -1.f))
            {
                /* Adding new figure into 'figures' array */
                add_figure(current_figure);
                current_figure = RandomFigure();
                current_figure->color = RandomColor();

                /* Checking solid rows and shifting if they are found */
                CheckRows();
//                for (int i = 0; i < figure_counter; ++i)
//                {
//                    for (int y = CheckRows(); y < 10; ++y)
//                        OffsetFigureY(figures[i], -1.f);
//                }
            }
            OffsetFigureY(current_figure, -1.f);
            startTime = clock();
        }
        render();
        event_handler();
    }
}
void render()
{
    BeginDrawing();
        DrawBackground();

        BeginMode3D(camera);
            DrawFigure(current_figure, current_figure->color);
            for (int i = 0; i < figure_counter; ++i)
                DrawFigure(figures[i], figures[i]->color);
            DrawWalls();
#ifdef DEBUG_MODE
            DrawFigure(current_figure, current_figure->color);
            DrawCubeWires(cube, 1.f, 1.f, 1.f, LIME);
#endif
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
    if (IsKeyDown(KEY_DOWN))
        game_speed_active = game_speed_default / 5;
    else
        game_speed_active = game_speed_default;

    if (IsKeyPressed(KEY_LEFT))
        if (!CheckCollisionFigureX(current_figure, -4.f) && !CheckCollisionAllFigures(*current_figure, -1.f, 0))
            OffsetFigureX(current_figure, -1.f);
    if (IsKeyPressed(KEY_RIGHT))
        if (!CheckCollisionFigureX(current_figure, 5.f) && !CheckCollisionAllFigures(*current_figure, 1.f, 0))
            OffsetFigureX(current_figure, 1.f);
}
void unloading()
{ CloseWindow(); }