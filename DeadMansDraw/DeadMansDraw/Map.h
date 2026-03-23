#include "Card.h"

#pragma once
class Map : public Card
{
public: 

    Map(int value);
    void play(Game&, Player&) override;
    std::string str() override;

};