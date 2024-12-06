#pragma once
#include <vector>
#include <map>
#include <position.h>
#include "constants.h"

using namespace std;

class Block
{
private:
    int RotationState = 0;
    int cellSize = CELLSIZE;
    int offSetRow = 0;
    int offSetColumn = 0;

public:
    Block();
    void Draw(int state);
    int Rotate();
    std::vector<Color> GetCellColours();

    void Move(int key);
    vector<Position> UpdatedPositions();

    int id;
    std::vector<Color> colors;
    map<int, vector<Position>> cells;
};
