#include "Card.h"

#ifndef CANNON_H
#define CANNON_H    

class Cannon : public Card
{
public:

    Cannon(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;

};

#endif