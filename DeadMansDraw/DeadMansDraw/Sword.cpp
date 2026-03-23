#include "Sword.h"

Sword::Sword(int value) : Card(value, sword) {

}

void Sword::play(Game&, Player&)
{
}

std::string Sword::str()
{
    return "Sword(" + std::to_string(value) + ")";
}
