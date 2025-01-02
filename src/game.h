#include "board.h"
#include <vector>
#include "block.h"

class Game
{
public:
    Game();
    ~Game();
    void StartGame();
    void Update();
    Music music;

private:
    void Draw(int key);
    bool CanMove(int columnChange, int rowChange);
    void ChangeOffSetByRotate();
    vector<int> GetChanges(int key);
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();

    Board board;
    void CheckRows();
    void CleanRow(int row);
    void UpdateInterface();
    void StoreBlock();

    void Reset();

    void IncreaseScore();

    int score;
    Font font;
    bool gameOver;
    int keyPressed;
    Block currentBlock;
    Block nextBlock;
    std::vector<Block> blocks;
};