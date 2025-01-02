#include "raylib.h"
#include "board.h"
#include "block.h"
#include "game.h"
#include <iostream>
#include <random>
#include "constants.h"

using namespace std;

int main()
{

    InitWindow(500, 620, "Tetris");

    const char *message = "Score";

    SetTargetFPS(60);

    Game game = Game();

    game.StartGame();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);

        BeginDrawing();

        ClearBackground(DARK_BLUE);

        game.Update();

        EndDrawing();
    }

    CloseWindow();
}