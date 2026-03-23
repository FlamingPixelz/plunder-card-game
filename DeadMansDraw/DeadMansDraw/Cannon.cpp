#include "Cannon.h"

Cannon::Cannon(int value) : Card(value, cannon) {

}

void Cannon::play(Game&, Player&)
{
}

std::string Cannon::str()
{
    return "Cannon(" + std::to_string(value) + ")";
}
