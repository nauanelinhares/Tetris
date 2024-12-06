#include "block.h"

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

    for (int i = 0; i < cellsState[state].size(); i++)
    {

        DrawRectangle(cellSize * cellsState[state][i].column, cellSize * cellsState[state][i].row, cellSize - 1, cellSize - 1, RED_GAME_COLOR);
    }
};