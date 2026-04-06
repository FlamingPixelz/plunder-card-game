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
    bool PlayCard(std::unique_ptr<Card>, Game&);
    std::vector<Card*> getHighestCardsFromBank();
    std::unique_ptr<Card> removeFromBank(Card* card);

protected:

    std::vector<std::unique_ptr<Card>> playArea;
    std::vector<std::unique_ptr<Card>> bank;

private:

    std::string name;
};

