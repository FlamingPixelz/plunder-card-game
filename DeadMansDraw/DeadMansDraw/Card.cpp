#include "Card.h"

Card::Card(int value, CardType type) : _value(value), cardType(type)
{
}

Card::~Card()
{
}

const CardType& Card::type() const
{
    return cardType;
}

void Card::willAddToBank(Game&, Player&)
{
}

int Card::getValue() const
{
    return _value;
}

