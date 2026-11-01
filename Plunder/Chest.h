#include "Card.h"

#ifndef CHEST_H
#define CHEST_H 

class Chest : public Card
{
public:

    Chest(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;
    void willAddToBank(Game& game, Player& player) override;

};

#endif