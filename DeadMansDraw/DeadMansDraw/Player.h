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

    std::string name;

    Player();
    ~Player();

    CardCollection& getPlayArea();
    const CardCollection& getBank();

    void displayPlayArea();
    bool isBust();
    void moveToBank();
    void displayBank();
    int getScore();
    bool PlayCard(Card*, Game&);

protected:

    CardCollection playArea, bank;

private:

};

