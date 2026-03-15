#include "Card.h"

#pragma once
class Kraken : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};