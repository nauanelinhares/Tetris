#include <vector>
#include "block.h"

class LInverseBlock : public Block
{
public:
    LInverseBlock()
    {
        id = 5;

        color = colors[id];
        offSetColumn = 4;
        /*

        x * x
        x * x
        * * x

        * x x
        * * *
        x x x

        x * *
        x * x
        x * x

        x x x
        * * *
        x x *


        */

        cells[0] = {
            Position(0, 2),
            Position(1, 0),
            Position(1, 1),
            Position(1, 2)};

        cells[1] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 1),
            Position(2, 1)};

        cells[2] = {
            Position(1, 0),
            Position(2, 0),
            Position(1, 1),
            Position(1, 2)};

        cells[3] = {
            Position(0, 1),
            Position(1, 1),
            Position(2, 1),
            Position(2, 2)};
    };
};
