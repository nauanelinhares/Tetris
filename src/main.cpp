#include "raylib.h"
#include "board.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{

    InitWindow(300, 600, "Hello World");

    SetTargetFPS(60);

    Board board = Board();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        int randomY = rand() % 20;
        int randomX = rand() % 10;
        int randomColor = rand() % 10;
        board.grid[randomY - 1][randomX - 1] = randomColor;

        board.Draw();

        EndDrawing();
    }

    CloseWindow();
}