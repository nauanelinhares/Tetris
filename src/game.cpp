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

    if (time - savedTime >= 0.75)
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

    if (CanMove(changes[0], changes[1]))
    {
        currentBlock.Move(changes[0], changes[1]);
    }

    if (lostPositionTrigger() && CanMove(changes[0], 1))
        currentBlock.Move(changes[0], 1);

    currentBlock.Rotate(keyPressed, board.cols, board.rows);

    currentBlock.Draw();
}

bool Game::CanMove(int columnChange, int rowChange)
{
    for (Position cell : currentBlock.UpdatedPositions())
    {
        int newColumn = cell.column + columnChange;
        int newRow = cell.row + rowChange;

        if (columnChange != 0 && (newColumn < 0 || newColumn >= board.cols))
        {
            return false;
        }

        if (rowChange != 0 && (newRow < 0 || newRow >= board.rows))
        {
            return false;
        }
    }

    return true;
}

void Game::StoreBlock()
{
    vector<Position> positions = currentBlock.UpdatedPositions();
    for (Position position : positions)
    {
        board.grid[position.row][position.column] = currentBlock.id;
    }
    currentBlock = GetRandomBlock();
}
