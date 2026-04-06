#include "Card.h"

#ifndef MAP_H
#define MAP_H

class Map : public Card
{
public: 

    Map(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;

};
#endif