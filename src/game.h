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
    void ChangeOffSetByRotate();
    vector<int> GetChanges(int key);
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();

    Board board;
    void CheckRows();
    void CleanRow(int row);

private:
    void Reset();
    bool gameOver;
    int keyPressed;
    Block currentBlock;
    std::vector<Block> blocks;
};