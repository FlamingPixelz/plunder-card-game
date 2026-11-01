#include "Card.h"

#ifndef ORACLE_H
#define ORACLE_H

class Oracle : public Card
{
public: 

    Oracle(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;

};
#endif