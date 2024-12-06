#pragma once
#include <vector>
#include <map>
#include <position.h>
#include "constants.h"

using namespace std;

class Block
{
private:
    int RotationState;
    int cellSize = CELLSIZE;

public:
    Block();
    void Draw(int state);
    int Rotate();
    std::vector<Color> GetCellColours();

    void Move(int key);

    int id;
    std::vector<Color> colors;
    map<int, vector<Position>> cells;
};
