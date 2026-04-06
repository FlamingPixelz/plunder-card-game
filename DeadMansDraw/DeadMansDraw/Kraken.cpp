#include "Kraken.h"
#include "Game.h"

Kraken::Kraken(int value) : Card(value, kraken) {

}

void Kraken::play(Game& game, Player&)
{
    printf("        Draw 3 cards from the deck and play each:\n");
    game.setKrakenDraws(3);
}

std::string Kraken::str()
{
    return "Kraken(" + std::to_string(_value) + ")";
}
