#include "board.h"
#include <iostream>
#include "constants.h"

using namespace std;

Board::Board()
{
    rows = 20;
    cols = 10;

    Start();

    colors = GetCellColours();
}

void Board::Start()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid[i][j] = 0;
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

            DrawRectangle(cellSize * j + initialOffsetColumn, cellSize * i + initialOffsetColumn, cellSize - 0.5, cellSize - 0.5, colors[cellValue]);
        }
    }
}

std::vector<Color> Board::GetCellColours()
{
    return {
        DARK_GRAY_GAME_COLOR,
        LIGHT_GRAY_GAME_COLOR,
        RED_GAME_COLOR,
        GREEN_GAME_COLOR,
        BLUE_GAME_COLOR,
        YELLOW_GAME_COLOR,
        ORANGE_GAME_COLOR,
        PURPLE_GAME_COLOR,
        CYAN_GAME_COLOR,
        MAGENTA_GAME_COLOR};
}

bool Board::IsCellEmpty(int column, int row)
{
    return !grid[row][column];
}

bool Board::isRowFull(int row)
{
    for (int j = 0; j < cols; j++)
    {
        if (grid[row][j] == 0)
        {
            return false;
        }
    }

    return true;
}
