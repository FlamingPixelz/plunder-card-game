#include <iostream>
#include "Card.h"
#include <array>
#include <vector>
#include <map>
#include <time.h>

#pragma once

class Game;

class Player

{
private:

    CardCollection playArea, bank;

public:

    std::string name;

    Player();
    ~Player();
    void displayPlayArea();
    bool isBust();
    void moveToBank();
    void displayBank();
    void getScore();
    bool PlayCard(Card*, Game&);
};

