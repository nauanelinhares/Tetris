#include "board.h"
#include <iostream>

using namespace std;

Board::Board()
{
    rows = 20;
    cols = 10;
    cellSize = 30;

    Start();

    colors = GetCellColours();
}

void Board::Start()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = 0; // Initialize the grid cell to 0
        }
    }
}

void Board::Draw()
{

    int cellValue = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cellValue = grid[i][j];

            // cout << 30 * j << " " << 30 * i << " " << cellValue << endl;

            DrawRectangle(cellSize * j, cellSize * i, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

std::vector<Color> Board::GetCellColours()
{
    Color darkGray = {26, 31, 40, 255};
    Color lightGray = {189, 195, 199, 255};
    Color red = {231, 76, 60, 255};
    Color green = {46, 204, 113, 255};
    Color blue = {52, 152, 219, 255};
    Color yellow = {241, 196, 15, 255};
    Color orange = {230, 126, 34, 255};
    Color purple = {155, 89, 182, 255};
    Color cyan = {26, 188, 156, 255};
    Color magenta = {142, 68, 173, 255};

    return {darkGray, lightGray, red, green, blue, yellow, orange, purple, cyan, magenta};
}
