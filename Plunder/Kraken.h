#include "Card.h"

#ifndef KRAKEN_H
#define KRAKEN_H    

class Kraken : public Card
{
public: 

    Kraken(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;

};
#endif