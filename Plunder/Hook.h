#include "Card.h"

#ifndef HOOK_H
#define HOOK_H  

class Hook : public Card
{
public:

    Hook(int value);
    void play(Game& game, Player& player) override;
    std::string str() override;

};
#endif