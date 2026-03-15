#include "Card.h"

#pragma once
class Chest : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};