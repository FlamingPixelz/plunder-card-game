#include "Card.h"

#ifndef KEY_H
#define KEY_H
class Key : public Card
{
public:

    Key(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;

};
#endif