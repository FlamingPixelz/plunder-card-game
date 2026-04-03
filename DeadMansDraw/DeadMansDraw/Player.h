#include <iostream>
#include "Card.h"
#include <array>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>

#pragma once

class Game;

class Player

{

public:

    Player();
    ~Player();

    CardCollection& getPlayArea();
    CardCollection& getBank();
    const std::string& getName() const;

    void displayPlayArea();
    bool isBust();
    void moveToBank(Game& game);
    void displayBank();
    int calculateScore() const;
    bool PlayCard(Card*, Game&);
    std::vector<Card*> getHighestCardsFromBank();
    Card* removeFromBank(Card* card);

protected:

    CardCollection playArea, bank;

private:

    std::string name;
};

