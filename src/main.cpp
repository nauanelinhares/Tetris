#include "raylib.h"
#include "board.h"
#include "block.h"
#include "Blocks/square.cpp"
#include "Blocks/I.cpp"

#include "Blocks/L.cpp"
#include <iostream>
#include <random>

using namespace std;

int main()
{

    InitWindow(300, 600, "Hello World");

    SetTargetFPS(60);

    Board board = Board();

    // TBlock square = TBlock();

    IBlock I = IBlock();

    LBlock L = LBlock();
    int i = 0;
    int keyPressed;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        board.Draw();

        keyPressed = GetKeyPressed();

        I.Move(keyPressed);

        I.Draw(i / 60);

        if (i > 239)
        {
            i = 0;
        }

        i++;

        EndDrawing();
    }

    CloseWindow();
}