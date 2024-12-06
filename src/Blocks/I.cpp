#include <vector>
#include "block.h"

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 10;

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

        cellsState[0] = {
            Position(0, 2),
            Position(1, 2),
            Position(2, 2),
            Position(3, 2)};

        cellsState[1] = {
            Position(2, 0),
            Position(2, 1),
            Position(2, 2),
            Position(2, 3)};

        cellsState[2] = {
            Position(1, 2),
            Position(2, 2),
            Position(3, 2),
            Position(4, 2)};

        cellsState[3] = {
            Position(2, 1),
            Position(2, 2),
            Position(2, 3),
            Position(2, 4)};
    };
};
