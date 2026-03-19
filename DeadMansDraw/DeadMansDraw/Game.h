#include <iostream>
#include <vector>
#include <random>
#include "Player.h"
#include "Card.h"
#include "game_title.h"

#pragma once
class Game
{
public:

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

    int turnNum, round, currentPlayer;
    CardCollection deck, discard;
    Player* players[2];

};

