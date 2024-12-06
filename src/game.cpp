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
    board.Draw();
    currentBlock = GetRandomBlock();
}

void Game::Update()
{
    board.Draw();

    keyPressed = GetKeyPressed();

    if (keyPressed == KEY_ENTER)
        currentBlock = GetRandomBlock();

    currentBlock.Move(keyPressed);
    currentBlock.Rotate(keyPressed);
    currentBlock.Draw();
}
