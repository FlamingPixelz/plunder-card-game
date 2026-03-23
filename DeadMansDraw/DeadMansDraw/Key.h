#include "Card.h"

#pragma once
class Key : public Card
{
public:

    Key(int value);
    void play(Game&, Player&) override;
    std::string str() override;

};