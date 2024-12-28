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
    changes = GetChanges(key);

    if (CanMove(changes[0], changes[1]))
    {
        currentBlock.Move(changes[0], changes[1]);
    }

    if (lostPositionTrigger() && CanMove(0, 1))
        currentBlock.Move(0, 1);

    if (keyPressed == KEY_SPACE)
    {
        currentBlock.Rotate();
        ChangeOffSetByRotate();
    }

    StoreBlock();
    CheckRows();

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
        if (!board.grid[newRow][newColumn] == 0)
        {
            return false;
        }
    }

    return true;
}

void Game::ChangeOffSetByRotate()
{
    int changeColumn = 0;
    int changeRow = 0;

    for (Position cell : currentBlock.UpdatedPositions())
    {
        int newColumn = cell.column;

        int newRow = cell.row;

        if (newColumn - changeColumn < 0)
        {
            changeColumn = newColumn;
        }
        else if (newColumn - changeColumn >= board.cols)
        {
            changeColumn = newColumn - board.cols + 1;
        }

        if (newRow - changeRow < 0)
        {
            changeRow = newRow;
        }
        else if (newRow - changeRow >= board.rows)
        {
            changeRow = newRow - board.rows + 1;
        }
    }

    if (CanMove(-changeColumn, -changeRow))
    {
        currentBlock.Move(-changeColumn, -changeRow);
    }
    else
    {
        currentBlock.UndoRotate();
    }
}

void Game::StoreBlock()
{

    bool canStore = false;
    for (Position pos : currentBlock.UpdatedPositions())
    {
        if (!board.IsCellEmpty(pos.column, pos.row + 1) || !CanMove(0, 1))
        {
            canStore = true;
            break;
        }
    }
    if (canStore)
    {
        vector<Position> positions = currentBlock.UpdatedPositions();
        for (Position position : positions)
        {
            board.grid[position.row][position.column] = currentBlock.id;
        }
        currentBlock = GetRandomBlock();
    }
}

vector<int> Game::GetChanges(int key)
{

    int columnChange = 0;
    int rowChange = 0;

    switch (key)
    {
    case KEY_UP:
        rowChange--;
        break;
    case KEY_DOWN:
        rowChange++;
        break;
    case KEY_LEFT:
        columnChange--;
        break;
    case KEY_RIGHT:
        columnChange++;
        break;
    default:
        break;
    }

    return {columnChange, rowChange};
}

void Game::CheckRows()
{
    for (int i = board.rows; i > 0; i--)
    {
        if (board.isRowFull(i))
        {
            CleanRow(i);
        }
    }
}

void Game::CleanRow(int row)
{

    for (int j = 0; j < board.cols; j++)
    {
        board.grid[row][j] = 0;
    }

    for (int i = row; i > 0; i--)
    {
        for (int j = 0; j < board.cols; j++)
        {
            board.grid[i][j] = board.grid[i - 1][j];
        }
    }
}