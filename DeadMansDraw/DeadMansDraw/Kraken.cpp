#include "Kraken.h"

Kraken::Kraken(int value) : Card(value, kraken) {

}

void Kraken::play(Game&, Player&)
{
}

std::string Kraken::str()
{
    return "Kraken(" + std::to_string(value) + ")";
}
