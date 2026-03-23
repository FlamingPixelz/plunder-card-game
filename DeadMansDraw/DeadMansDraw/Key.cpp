#include "Key.h"

Key::Key(int value) : Card(value, key) {

}

void Key::play(Game&, Player&)
{
}

std::string Key::str()
{
    return "Key(" + std::to_string(value) + ")";
}
