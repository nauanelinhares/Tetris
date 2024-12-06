
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

    std::vector<Color> GetCellColours();

private:
    int rows;
    int cols;
    int cellSize = CELLSIZE;

    std::vector<Color> colors;
};
