#include <iostream>
#include <vector>
#include <random>
#include "Player.h"
#include "Card.h"

#pragma once
class Game
{
public:

    CardCollection deck, discard;
    std::vector<Player*> players;


    Game();
    ~Game();
    void startGame();
    void endGame();
    void initialiseDeck();
    void shuffle();
    void createPlayer();
    void turn();
    void gameTracker();

private:
    int turnNum, round;
};

