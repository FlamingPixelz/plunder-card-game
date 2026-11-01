#include "Card.h"

#ifndef MERMAID_H
#define MERMAID_H

class Mermaid : public Card
{
public:

    Mermaid(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;

};
#endif
