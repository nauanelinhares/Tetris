#include "raylib.h"
#include "board.h"
#include "block.h"
#include "game.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{

    InitWindow(500, 620, "Tetris");

    Font font = LoadFont("Font/monogram.ttf");
    const char *message = "Tetris";

    SetTargetFPS(60);

    Game game = Game();

    game.StartGame();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKBLUE);
        DrawText(message, 300, 10, 20, WHITE);
        game.Update();

        EndDrawing();
    }

    CloseWindow();
}