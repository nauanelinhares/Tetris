#include "raylib.h"
#include "game.h"
#include <random>
#include <block.h>
#include "Blocks/square.cpp"
#include "Blocks/I.cpp"
#include "Blocks/L.cpp"
#include "Blocks/LInverse.cpp"
#include "Blocks/T.cpp"
#include "Blocks/ZInverse.cpp"
#include "Blocks/Z.cpp"
#include <iostream>

double savedTime = GetTime();

bool lostPositionTrigger()
{

    double time;
    time = GetTime();

    if (time - savedTime >= 0.5)
    {
        savedTime = GetTime();
        return true;
    }

    return false;
}

Game::Game()
{
    board = Board();
    blocks = GetAllBlocks();
};

Block Game::GetRandomBlock()
{
    int index = rand() % blocks.size();
    Block block = blocks[index];
    return {block};
}

std::vector<Block> Game::GetAllBlocks()
{
    return {
        SquareBlock(),
        IBlock(),
        LBlock(),
        LInverseBlock(),
        TBlock(),
        ZBlock(),
        ZInverseBlock()};
}

void Game::StartGame()
{
    currentBlock = GetRandomBlock();
}

void Game::Update()
{

    keyPressed = GetKeyPressed();

    if (keyPressed == KEY_ENTER)
        currentBlock = GetRandomBlock();

    Draw(keyPressed);
}

void Game::Draw(int key)
{
    board.Draw();

    vector<int> changes;
    changes = currentBlock.GetChanges(key);

    currentBlock.Move(changes[0], changes[1], board.cols, board.rows);

    if (lostPositionTrigger())
        currentBlock.Move(changes[0], 1, board.cols, board.rows);

    currentBlock.Rotate(keyPressed);
    currentBlock.Draw();
}
