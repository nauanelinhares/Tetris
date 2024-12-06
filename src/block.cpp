#include "block.h"

Block::Block() {}

int Block::Rotate()
{
    return RotationState;
};

void Block::Draw(int state)
{

    for (int i = 0; i < cellsState[state].size(); i++)
    {

        DrawRectangle(cellSize * cellsState[state][i].row, cellSize * cellsState[state][i].column, cellSize - 1, cellSize - 1, RED_GAME_COLOR);
    }
};