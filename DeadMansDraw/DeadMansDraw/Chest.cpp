#include "Chest.h"

Chest::Chest(int value) : Card(value, chest) {

}

void Chest::play(Game&, Player&)
{
}

std::string Chest::str()
{
    return "Chest(" + std::to_string(value) + ")";
}
