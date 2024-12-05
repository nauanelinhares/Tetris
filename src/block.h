#pragma once
#include <vector>
#include <map>
#include <position.h>

using namespace std;

class Block
{
private:
    int RotationState;
    map<int, vector<Position>> cellsState;

public:
    Block();
    int id;
    int Rotate();
};
