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

    void Rotate(int key, int columns, int rows);
    bool CanMove(int columns, int rows, int row, int column);
    void ChangeOffSetByRotate(int column, int row);
    void Move(int columnChange, int rowChange, int columns, int rows);
    vector<int> GetChanges(int key);
    vector<Position> UpdatedPositions();

    int id;
    Color color;
    std::vector<Color> colors;
    map<int, vector<Position>> cells;
};
