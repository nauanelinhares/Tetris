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
    void Draw();

    std::vector<Color> GetCellColours();

    void Rotate();
    void UndoRotate();

    void Move(int columnChange, int rowChange);
    vector<Position> UpdatedPositions();

    int id;
    Color color;
    std::vector<Color> colors;
    map<int, vector<Position>> cells;
};
