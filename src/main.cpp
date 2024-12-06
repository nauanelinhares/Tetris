#include "raylib.h"
#include "board.h"
#include "block.h"
#include "Blocks/square.cpp"
#include <iostream>
#include <random>

using namespace std;

int main()
{

    InitWindow(300, 600, "Hello World");

    SetTargetFPS(60);

    Board board = Board();

    SquareBlock square = SquareBlock();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        board.Draw();

        square.Draw(0);

        EndDrawing();
    }

    CloseWindow();
}