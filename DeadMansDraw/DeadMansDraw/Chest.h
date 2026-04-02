#include "Card.h"

#pragma once
class Chest : public Card
{
public:

    Chest(int value);
    void play(Game&, Player&) override;
    std::string str() override;
    void willAddToBank(Game&, Player&) override;

};