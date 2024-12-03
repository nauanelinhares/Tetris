#include "raylib.h"
#include <iostream>

using namespace std;

int main()
{

    InitWindow(800, 450, "Hello World");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKBLUE);

        DrawText("Hello World", 10, 10, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();
}