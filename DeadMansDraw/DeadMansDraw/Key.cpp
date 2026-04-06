#include "Key.h"

Key::Key(int value) : Card(value, key) {

}

void Key::play(Game&, Player&)
{
    printf("        No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n");
}

std::string Key::str()
{
    return "Key(" + std::to_string(_value) + ")";
}
