#include "Card.h"

#pragma once
class Cannon : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};

