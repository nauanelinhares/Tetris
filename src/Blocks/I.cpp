#include <vector>
#include "block.h"

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 7;
        color = colors[id];
        offSetRow = -2;
        offSetColumn = 3;

        /*

        x x x x x
        x x x x x
        * * * * x
        x x x x x
        x x x x x

        x x * x x
        x x * x x
        x x * x x
        x x * x x
        x x x x x

        x x x x x
        x x x x x
        x * * * *
        x x x x x
        x x x x x

        x x x x x
        x x * x x
        x x * x x
        x x * x x
        x x * x x


        */

        cells[0] = {
            Position(0, 2),
            Position(1, 2),
            Position(2, 2),
            Position(3, 2)};

        cells[1] = {
            Position(2, 0),
            Position(2, 1),
            Position(2, 2),
            Position(2, 3)};

        cells[2] = {
            Position(1, 2),
            Position(2, 2),
            Position(3, 2),
            Position(4, 2)};

        cells[3] = {
            Position(2, 1),
            Position(2, 2),
            Position(2, 3),
            Position(2, 4)};
    };
};
