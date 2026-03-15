#include "Card.h"

#pragma once
class Map : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};