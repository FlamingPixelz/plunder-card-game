#include "Card.h"

#pragma once
class Kraken : public Card
{
public: 

    Kraken(int value);
    void play(Game&, Player&) override;
    std::string str() override;

};