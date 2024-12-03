
#include <vector>
#include <string>
#include <raylib.h>

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
    int cellSize;

    std::vector<Color> colors;
};
