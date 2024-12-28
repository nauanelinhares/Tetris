
#include <vector>
#include <string>
#include <raylib.h>
#include "constants.h"

#pragma once

class Board
{
public:
    Board();
    int grid[20][10];
    void Start();
    void Draw();
    int rows;
    int cols;
    bool IsCellEmpty(int column, int row);
    bool isRowFull(int row);
    std::vector<Color> GetCellColours();

private:
    int cellSize = CELLSIZE;

    std::vector<Color> colors;
};
