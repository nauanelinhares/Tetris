#include <vector>
#include "block.h"

class SquareBlock : public Block
{
public:
    SquareBlock()
    {
        id = 4;
        color = colors[id];

        cells[0] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 0),
            Position(1, 1)};

        cells[1] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 0),
            Position(1, 1)};

        cells[2] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 0),
            Position(1, 1)};

        cells[3] = {
            Position(0, 0),
            Position(0, 1),
            Position(1, 0),
            Position(1, 1)};
    };
};
