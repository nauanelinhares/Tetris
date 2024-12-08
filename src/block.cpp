#include "block.h"
#include "raylib.h" // Include the raylib header for drawing functions
#include <iostream>

Block::Block()
{
    colors = GetCellColours();
}

void Block::Draw()
{
    std::vector<Position> cells = UpdatedPositions();

    for (int i = 0; i < cells.size(); i++)
    {

        DrawRectangle(cellSize * cells[i].column, cellSize * cells[i].row, cellSize - 1, cellSize - 1, color);
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

bool Block::CanMove(int columns, int rows, int columnChange, int rowChange)
{
    for (Position cell : cells[RotationState])
    {
        int newColumn = cell.column + offSetColumn + columnChange;
        int newRow = cell.row + offSetRow + rowChange;

        if (columnChange != 0 && (newColumn < 0 || newColumn >= columns))
        {
            return false;
        }

        if (rowChange != 0 && (newRow < 0 || newRow >= rows))
        {
            return false;
        }
    }

    return true;
}

vector<int> Block::GetChanges(int key)
{

    int columnChange = 0;
    int rowChange = 0;

    switch (key)
    {
    case KEY_UP:
        rowChange--;
        break;
    case KEY_DOWN:
        rowChange++;
        break;
    case KEY_LEFT:
        columnChange--;
        break;
    case KEY_RIGHT:
        columnChange++;
        break;
    default:
        break;
    }

    return {columnChange, rowChange};
}

void Block::Move(int columnChange, int rowChange, int columns, int rows)
{

    bool canMove = CanMove(columns, rows, columnChange, rowChange);

    if (!canMove)
    {
        return;
    }

    offSetRow = offSetRow + rowChange;
    offSetColumn = offSetColumn + columnChange;
}

bool Block::CanRotate(int column, int row)
{
    return true;
}

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

vector<Position> Block::UpdatedPositions()
{
    vector<Position> blockPosition;

    for (Position cell : cells[RotationState])
    {
        blockPosition.push_back(Position{cell.column + offSetColumn, cell.row + offSetRow});
    }

    return blockPosition;
}
