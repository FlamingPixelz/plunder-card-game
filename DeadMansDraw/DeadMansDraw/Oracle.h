#include "Card.h"

#pragma once
class Oracle : public Card
{
public: 

    Oracle(int value);
    void play(Game&, Player&) override;
    std::string str() override;

};