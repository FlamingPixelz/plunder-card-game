#include "Card.h"

#pragma once
class Mermaid : public Card
{
public:

    Mermaid(int value);
    void play(Game&, Player&) override;
    std::string str() override;

};
