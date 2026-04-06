#include "Card.h"

Card::Card(int value, CardType type) : _value(value), _cardType(type)
{
}

Card::~Card()
{
}

const CardType& Card::type() const
{
    return _cardType;
}

void Card::willAddToBank(Game&, Player&)
{
}

int Card::getValue() const
{
    return _value;
}

