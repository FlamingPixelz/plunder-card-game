#include "Game.h"

Game::Game()
{
    round = 1;
    turnNum = 1;
    currentPlayer = 0;

    initialiseDeck();
    shuffle();
    createPlayer();
}

Game::~Game()
{
}

void Game::startGame()
{
    std::cout << GAME_TITLE << std::endl;
}

void Game::endGame()
{
}

void Game::initialiseDeck()
{
}

void Game::shuffle()
{
    //CardCollection shuffle{ cards.begin(), cards.end() };
    //std::shuffle(shuffle.begin(), shuffle.end(), std::mt19937{ std::random_device{}() });
    //std::copy(shuffle.begin(), shuffle.end(), cards.begin());
}

void Game::createPlayer()
{
    players[0] = new Player();
    players[1] = new Player();
}

void Game::turn()
{
}

void Game::gameTracker()
{


}
