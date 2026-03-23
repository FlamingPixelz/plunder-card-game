#include "Hook.h"

Hook::Hook(int value) : Card(value, hook)
{
}

void Hook::play(Game&, Player&)
{
}

std::string Hook::str()
{
    return "Hook(" + std::to_string(value) + ")";
}
