#include "block.h"
#include "raylib.h" // Include the raylib header for drawing functions
#include <iostream>

Block::Block()
{
    colors = GetCellColours();
}

void Block::Draw(int offSetRow, int offSetColumn)
{
    std::vector<Position> cells = UpdatedPositions();

    for (int i = 0; i < cells.size(); i++)
    {

        DrawRectangle(cellSize * cells[i].column + defaultOffSet + offSetColumn, cellSize * cells[i].row + defaultOffSet + offSetRow, cellSize - 1, cellSize - 1, color);
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

void Block::Move(int columnChange, int rowChange)
{
    offSetRow = offSetRow + rowChange;
    offSetColumn = offSetColumn + columnChange;
}

void Block::Rotate()
{

    RotationState++;

    if (RotationState > 3)
    {
        RotationState = 0;
    }
};
void Block::UndoRotate()
{
    RotationState--;

    if (RotationState < 0)
    {
        RotationState = 3;
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
