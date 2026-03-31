#include <iostream>
#include <vector>
#include <random>

#include "Player.h"
#include "Card.h"
#include "game_title.h"
#include "Cannon.h"
#include "Chest.h"
#include "Hook.h"
#include "Key.h"
#include "Kraken.h"
#include "Map.h"
#include "Mermaid.h"
#include "Oracle.h"
#include "Sword.h"

#pragma once
class Game
{
public:

    Game();
    ~Game();

    CardCollection& getDiscard();
    CardCollection& getDeck();
    Player& getOpponent(Player&);
    void setKrakenDraws(int);

    void startGame();
    void endGame();
    void initialiseDeck();
    void shuffle();
    void createPlayer();
    void turn();
    bool drawToPlayArea(Player&, Card*);
    Card* draw();
    void gameTracker();
    void moveToDiscard(CardCollection&);
    void endTurn();
    bool isTurnOver() const;

protected:

    CardCollection deck, discard;
    Player* players[2];

private:

    int turnNum, round, currentPlayer, krakenDraws, roundTracker;
    bool turnOver;
    void executeCardTurn();

};

