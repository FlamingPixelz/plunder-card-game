#include "Card.h"

#pragma once
class Oracle : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};