#include "block.h"
#include "raylib.h" // Include the raylib header for drawing functions

Block::Block() {}

int Block::Rotate()
{
    RotationState++;

    if (RotationState > 3)
    {
        RotationState = 0;
    }

    return RotationState;
};

void Block::Draw(int state)
{

    for (int i = 0; i < cells[state].size(); i++)
    {

        DrawRectangle(cellSize * cells[state][i].column, cellSize * cells[state][i].row, cellSize - 1, cellSize - 1, RED_GAME_COLOR);
    }
};

std::vector<Color> Block::GetCellColours()
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

void Block::Move(int key)
{
    if (key == KEY_UP)
    {
        for (Position &cell : cells[RotationState])
        {
            cell.row--;
        }
    }
    else if (key == KEY_DOWN)
    {
        for (Position &cell : cells[RotationState])
        {
            cell.row++;
        }
    }
    else if (key == KEY_LEFT)
    {
        for (Position &cell : cells[RotationState])
        {
            cell.column--;
        }
    }
    else if (key == KEY_RIGHT)
    {
        for (Position &cell : cells[RotationState])
        {
            cell.column++;
        }
    }
}
