#include <iostream>
#include <vector>
#include <random>
#include <memory>

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
    const CardCollection& getDeck() const;
    Player& getOpponent(const Player&) const;
    void setKrakenDraws(int);

    void startGame();
    bool drawToPlayArea(Player&, std::unique_ptr<Card>);
    void moveToDiscard(CardCollection&);

protected:

    CardCollection deck, discard;
    std::unique_ptr<Player> players[2];

private:

    int _turnNum, _round, _currentPlayer, _krakenDraws, _roundTracker;
    bool _turnOver;

    void executeCardTurn();
    void endTurn();
    bool isTurnOver() const;
    std::unique_ptr<Card> draw();
    void gameTracker();
    void endGame();
    void initialiseDeck();
    void shuffle();
    void createPlayer();
    void turn();
};

