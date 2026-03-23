#include <iostream>
#include <vector>
#include <string>


#pragma once

class Player;
class Game;
class Card;

typedef std::vector<Card*> CardCollection;
enum CardType { cannon, chest, key, anchor, sword, hook, oracle, map, mermaid, kraken };

class Card
{

protected:

    int value;

public:
    CardType cardType;

    Card(int value, CardType type);
    virtual ~Card();
    int getValue() const;
    CardType type() const;


    virtual std::string str() = 0;
    virtual void play(Game&, Player&) = 0;
    virtual void willAddToBank(Game&, Player&);
};

