#include "Card.h"

#pragma once
class Sword : public Card
{
public:

    Sword(int value);
    void play(Game&, Player&) override;
    std::string str() override;

};