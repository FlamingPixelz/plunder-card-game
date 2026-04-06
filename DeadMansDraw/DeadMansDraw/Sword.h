#include "Card.h"

#ifndef SWORD_H
#define SWORD_H

class Sword : public Card
{
public:

    Sword(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;

};
#endif