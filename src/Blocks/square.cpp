#include <vector>
#include "block.h"

class SquareBlock : public Block
{
public:
    SquareBlock()
    {
        id = 10;
        cellsState[0] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 0),
            Position(1, 1)};

        cellsState[1] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 0),
            Position(1, 1)};

        cellsState[2] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 0),
            Position(1, 1)};

        cellsState[3] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 0),
            Position(1, 1)};
    };
};