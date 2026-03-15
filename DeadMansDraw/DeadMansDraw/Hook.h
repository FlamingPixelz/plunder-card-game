#include "Card.h"

#pragma once
class Hook : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};