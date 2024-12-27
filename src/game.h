#include "board.h"
#include <vector>
#include "block.h"

class Game
{
public:
    Game();
    void StartGame();
    void Draw(int key);
    void Update();
    void StoreBlock();
    bool CanMove(int columnChange, int rowChange);
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    Board board;

private:
    int keyPressed;
    Block currentBlock;
    std::vector<Block> blocks;
};