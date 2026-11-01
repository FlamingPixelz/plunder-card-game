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


#ifndef GAME_H
#define GAME_H


class Game
{
public:

    Game();
    ~Game();

    //Getters and Setters
    CardCollection& getDiscard();
    const CardCollection& getDeck() const;
    Player& getOpponent(const Player& currentPlayer) const;
    void setKrakenDraws(int draws);

    void startGame();
    bool drawToPlayArea(Player& player, std::unique_ptr<Card> card);
    void moveToDiscard(CardCollection& playArea);

private:

    int _turnNum, _round, _currentPlayer, _krakenDraws, _roundTracker;
    bool _turnOver;
    CardCollection _deck, _discard;
    std::unique_ptr<Player> _players[2];

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

#endif