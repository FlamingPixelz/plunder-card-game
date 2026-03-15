#include <iostream>
#include <vector>
#include <string>


#pragma once

class Card;
class Player;
class Game;

typedef std::vector<Card*> CardCollection;

class Card
{
public:

    enum CardType { Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken };

    const CardType& type() const;
    virtual std::string str() = 0;
    virtual void play(Game&, Player&) = 0;
    virtual void willAddToBank(Game&, Player&) = 0;
};

