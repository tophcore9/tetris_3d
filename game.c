#include "game.h"

Camera3D camera = {};
Figure *current_figure = {};
float game_speed_active = 0.4f;
float game_speed_default = 0.4f;
bool is_game_over = false;

Music music;
Sound complete_line_sfx;
Sound place_figure_sfx;

int score = 0;
float streak_k = 1;
int complete_lines = 0;

void run()
{
    startup();
    update();
    unloading();
}
void startup()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Tetris");
    InitAudioDevice();
    InitWalls();

    figures = (Figure**)malloc(sizeof(Figure*));

    srand(time(NULL));
    current_figure = RandomFigure();
    current_figure->color = RandomColor();

#ifdef DEBUG_MODE
    cube = (Vector3){-4.f, 10.f, -18.f};
#endif

    SetWindowIcon(LoadImage("../res/icon.png"));
    music = LoadMusicStream("../res/song.mp3");
    complete_line_sfx = LoadSound("../res/complete line.wav");
    place_figure_sfx = LoadSound("../res/place figure.mp3");
    PlayMusicStream(music);

    camera.target = (Vector3){2.75f, 1.0f, 0.0f};
    camera.position = (Vector3){2.75f, 1.25f, 10.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};

#ifndef DEBUG_MODE
    DisableCursor();
#endif
    SetTargetFPS(60);
}
void update()
{
    clock_t startTime = clock();
    float elapsedTime;

    /* Main cycle */
    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        if (!is_game_over)
        {
            elapsedTime = (float) (clock() - startTime) / CLOCKS_PER_SEC;
            if (elapsedTime >= game_speed_active) /* Every 400 ms */
            {
                if (CheckCollisionFigureY(current_figure, -9.f) || CheckCollisionAllFigures(*current_figure, 0, -1.f))
                {
                    /* Adding new figure into 'figures' array */
                    AddFigure(current_figure);
                    current_figure = RandomFigure();
                    current_figure->color = RandomColor();

                    /* Checking complete lines and shifting them down if they are found */
                    for (int i = 0; i < figure_counter; ++i)
                    {
                        PlaySound(place_figure_sfx);
                        while (CompleteLineHandler())
                        {
                            PlaySound(complete_line_sfx);
                            score += (int)(100 * streak_k);
                            ++complete_lines;
                            streak_k += 0.5f;
                        }
                        streak_k = 1;
                    }
                }

                for (int i = 0; i < figure_counter; ++i)
                {
                    if (CheckCollisionFigureY(figures[i], 9.f))
                        is_game_over = true;
                }

#ifndef DEBUG_MODE
                OffsetFigureY(current_figure, -1.f);
                startTime = clock();
#endif
            }
            event_handler();
            render();
        }
        else
        {
            StopMusicStream(music);
            RemoveFigures();
            if (figures == NULL)
                figures = (Figure**)malloc(sizeof(Figure*));

            BeginDrawing();
            DrawBackground();
            DrawText("Game Over", 0, 0, 50, RED);
            EndDrawing();
        }
    }
}
void render()
{
    BeginDrawing();
        DrawBackground();
        BeginMode3D(camera);
            DrawFieldGrid(current_figure);
            DrawWalls();
            DrawFigure(current_figure, current_figure->color);

            for (int i = 0; i < figure_counter; ++i)
                DrawFigure(figures[i], figures[i]->color);

#ifdef DEBUG_MODE
            DrawFigure(current_figure, current_figure->color);
            DrawCubeWires(cube, 1.f, 1.f, 1.f, LIME);
#endif
        EndMode3D();

        char score_str[20];
        snprintf(score_str, 20, "Score: %d", score);
        DrawText(score_str, SCREEN_WIDTH - 10 * strlen(score_str) - 20, 10, 20, WHITE);

        char complete_lines_str[20];
        snprintf(complete_lines_str, 20, "Lines: %d", complete_lines);
        DrawText(complete_lines_str, SCREEN_WIDTH - 10 * strlen(complete_lines_str) - 10, 30, 20, WHITE);

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
    else if (IsKeyPressed(KEY_SPACE))
        RotateFigure(&current_figure);
#elifndef DEBUG_MODE
    if (IsKeyPressed(KEY_UP))
        RotateFigure(&current_figure);

    if (IsKeyDown(KEY_DOWN))
        game_speed_active = game_speed_default / 10;
    else
        game_speed_active = game_speed_default;

    if (IsKeyPressed(KEY_LEFT))
        if (!CheckCollisionFigureX(current_figure, -4.f) && !CheckCollisionAllFigures(*current_figure, -1.f, 0.f))
            OffsetFigureX(current_figure, -1.f);
    if (IsKeyPressed(KEY_RIGHT))
        if (!CheckCollisionFigureX(current_figure, 5.f) && !CheckCollisionAllFigures(*current_figure, 1.f, 0.f))
            OffsetFigureX(current_figure, 1.f);
#endif
}
void unloading()
{
    RemoveFigures();
    UnloadMusicStream(music);
    CloseWindow();
}