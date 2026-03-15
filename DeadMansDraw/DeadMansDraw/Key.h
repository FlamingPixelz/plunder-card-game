#include "Card.h"

#pragma once
class Key : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};