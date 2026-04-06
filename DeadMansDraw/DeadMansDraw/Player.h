#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>

#include "Card.h"

#ifndef PLAYER_H
#define PLAYER_H

class Game;

class Player

{

public:

    Player();
    ~Player();

    CardCollection& getPlayArea();
    CardCollection& getBank();
    const std::string& getName() const;

    void displayPlayArea() const;
    bool isBust() const;
    void moveToBank(Game& game);
    void displayBank() const;
    int calculateScore() const;
    bool PlayCard(std::unique_ptr<Card> card, Game& game);
    std::vector<Card*> getHighestCardsFromBank();
    std::unique_ptr<Card> removeFromBank(Card* card);

private:

    std::vector<std::unique_ptr<Card>> _playArea;
    std::vector<std::unique_ptr<Card>> _bank;
    std::string _name;
};

#endif