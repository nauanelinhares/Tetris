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
    blocks = {
        SquareBlock(),
        IBlock(),
        LBlock(),
        LInverseBlock(),
        TBlock(),
        ZBlock(),
        ZInverseBlock()};
};

Block Game::GetRandomBlock()
{
    int index = rand() % blocks.size();
    Block block = blocks[index];
    return {block};
}