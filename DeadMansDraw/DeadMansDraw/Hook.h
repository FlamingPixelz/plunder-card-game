#include "Card.h"

#pragma once
class Hook : public Card
{
public:

    Hook(int value);
    void play(Game&, Player&) override;
    std::string str() override;

};