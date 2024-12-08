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

    int keyPressed;

    Block L = game.GetRandomBlock();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        game.board.Draw();

        keyPressed = GetKeyPressed();

        if (keyPressed == KEY_ENTER)
            L = game.GetRandomBlock();

        L.Move(keyPressed);

        L.Rotate(keyPressed);

        L.Draw();

        EndDrawing();
    }

    CloseWindow();
}