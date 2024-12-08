#include "board.h"
#include <vector>
#include "block.h"

class Game
{
public:
    Game();
    // void StartGame();

    Block GetRandomBlock();
    Board board;

private:
    std::vector<Block> blocks;
};