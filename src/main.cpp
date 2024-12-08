#include "raylib.h"
#include "board.h"
#include "block.h"
#include "game.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{

    InitWindow(300, 600, "Hello World");

    SetTargetFPS(60);

    Game game = Game();

    game.StartGame();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKBLUE);

        game.Update();

        EndDrawing();
    }

    CloseWindow();
}