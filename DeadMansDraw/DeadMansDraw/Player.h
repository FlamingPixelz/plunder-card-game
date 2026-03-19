#include <iostream>
#include "Card.h"
#include <array>
#include <time.h>

#pragma once

class Game;

class Player

{
public:

    std::string name;
    CardCollection playArea, bank;

    Player();
    ~Player();
    void displayPlayArea();
    bool isBust();
    void moveToBank();
    void displayBank();
    void getScore();
    bool PlayCard(Card*, Game&);
};

