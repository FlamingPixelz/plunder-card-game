#include <iostream>
#include <vector>
#include <string>


#pragma once

class Player;
class Game;
class Card;

typedef std::vector<std::unique_ptr<Card>> CardCollection;
enum CardType { cannon, chest, key, anchor, sword, hook, oracle, map, mermaid, kraken };

class Card
{

public:
    CardType cardType;

    Card(const int value, const CardType type);
    virtual ~Card();
    int getValue() const;
    const CardType& type() const;


    virtual std::string str() = 0;
    virtual void play(Game&, Player&) = 0;
    virtual void willAddToBank(Game&, Player&);

protected:

    int value;
};

