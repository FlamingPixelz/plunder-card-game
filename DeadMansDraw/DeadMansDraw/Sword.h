#include "Card.h"

#pragma once
class Sword : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};