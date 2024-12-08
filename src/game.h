#include "board.h"
#include <vector>
#include "block.h"

class Game
{
public:
    Game();
    void StartGame();
    void Draw();
    void Update();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    Board board;

private:
    int keyPressed;
    Block currentBlock;
    std::vector<Block> blocks;
};