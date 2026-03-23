#include "Chest.h"

Chest::Chest(int value) : Card(value, chest) {

}

void Chest::play(Game&, Player&)
{
    printf("        No immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n");
}

std::string Chest::str()
{
    return "Chest(" + std::to_string(value) + ")";
}
