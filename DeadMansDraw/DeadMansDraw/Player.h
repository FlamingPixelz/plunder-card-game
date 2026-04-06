#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>

#include "Card.h"

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

    void displayPlayArea() const;
    bool isBust() const;
    void moveToBank(Game& game);
    void displayBank() const;
    int calculateScore() const;
    bool PlayCard(std::unique_ptr<Card>, Game&);
    std::vector<Card*> getHighestCardsFromBank();
    std::unique_ptr<Card> removeFromBank(Card* card);

protected:

    std::vector<std::unique_ptr<Card>> playArea;
    std::vector<std::unique_ptr<Card>> bank;

private:

    std::string _name;
};

