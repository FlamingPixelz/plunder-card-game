#include "Card.h"

#pragma once
class Mermaid : public Card
{

    void play(Game&, Player&) override;
    std::string str() override;

};
