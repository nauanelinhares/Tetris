#include <vector>
#include "block.h"

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 3;
        /*

        x * x
        * * *
        x x x

        x * x
        x * *
        x * x

        x x x
        * * *
        x * x

        x * x
        * * x
        x * x


        */
        cells[0] = {
            Position(1, 0),
            Position(0, 1),
            Position(1, 1),
            Position(2, 1)};

        cells[1] = {
            Position(1, 0),
            Position(1, 1),
            Position(1, 2),
            Position(2, 1)};

        cells[2] = {
            Position(0, 1),
            Position(1, 1),
            Position(2, 1),
            Position(1, 2)};

        cells[3] = {
            Position(0, 1),
            Position(1, 0),
            Position(1, 1),
            Position(1, 2)};
    };
};
