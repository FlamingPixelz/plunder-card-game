#include "Card.h"

#pragma once
class Cannon : public Card
{
public:

    Cannon(int value);
    void play(Game&, Player&) override;
    std::string str() override;

};

