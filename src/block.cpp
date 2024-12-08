#include "block.h"
#include "raylib.h" // Include the raylib header for drawing functions
#include <iostream>

Block::Block() {}

int Block::Rotate(int key)
{
    if (key != KEY_SPACE)
    {
        return RotationState;
    }

    RotationState++;

    if (RotationState > 3)
    {
        RotationState = 0;
    }

    return RotationState;
};

void Block::Draw()
{
    std::vector<Position> cells = UpdatedPositions();

    for (int i = 0; i < cells.size(); i++)
    {

        DrawRectangle(cellSize * cells[i].column, cellSize * cells[i].row, cellSize - 1, cellSize - 1, RED_GAME_COLOR);
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
        offSetRow--;
    }
    else if (key == KEY_DOWN)
    {
        offSetRow++;
    }
    else if (key == KEY_LEFT)
    {
        offSetColumn--;
    }
    else if (key == KEY_RIGHT)
    {
        offSetColumn++;
    }
}

vector<Position> Block::UpdatedPositions()
{
    vector<Position> blockPosition;

    for (Position cell : cells[RotationState])
    {
        blockPosition.push_back(Position{cell.column + offSetColumn, cell.row + offSetRow});
    }

    return blockPosition;
}
