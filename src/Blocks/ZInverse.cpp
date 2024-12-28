#include <vector>
#include "block.h"

class ZInverseBlock : public Block
{
public:
    ZInverseBlock()
    {
        id = 1;
        color = colors[id];
        offSetRow = -1;
        offSetColumn = 3;
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

        cells[0] = {
            Position(0, 2),
            Position(1, 2),
            Position(1, 1),
            Position(2, 1)};

        cells[1] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 1),
            Position(1, 2)};

        cells[2] = {
            Position(1, 0),
            Position(2, 0),
            Position(0, 1),
            Position(1, 1)};

        cells[3] = {
            Position(1, 0),
            Position(1, 1),
            Position(2, 1),
            Position(2, 2)};
    }
};
