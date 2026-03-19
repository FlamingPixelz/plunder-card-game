#include <iostream>
#include "Card.h"

#pragma once

class Game;

class Player

{
public:

    std::vector<std::string> names;
    CardCollection playArea, bank;
    int score;

    Player();
    ~Player();
    void displayPlayArea();
    bool isBust();
    void moveToBank();
    void displayBank();
    int getScore();
    bool PlayCard(Card*, Game&);
};

