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

public:
    Block();
    void Draw(int state);

    int id;
    int Rotate();
    map<int, vector<Position>> cellsState;
    int cellSize = CELLSIZE;
};
