#include <vector>
#include "block.h"

class ZInverseBlock : public Block
{
public:
    ZInverseBlock()
    {
        id = 10;

        /*

        x x x
        x * *
        * * x

        * x x
        * * x
        x * x

        x * *
        * * x
        x x x

        x * x
        x * *
        x x *


        */

        cellsState[0] = {
            Position(0, 2),
            Position(1, 2),
            Position(1, 1),
            Position(2, 1)};

        cellsState[1] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 1),
            Position(1, 2)};

        cellsState[2] = {
            Position(1, 0),
            Position(2, 0),
            Position(0, 1),
            Position(1, 1)};

        cellsState[3] = {
            Position(1, 0),
            Position(1, 1),
            Position(2, 1),
            Position(2, 2)};
    };
};
