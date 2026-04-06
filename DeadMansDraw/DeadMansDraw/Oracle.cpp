#include "Oracle.h"
#include "Game.h"

Oracle::Oracle(int value) : Card(value, oracle) {

}

void Oracle::play(Game& game, Player&)
{
    const CardCollection& deck = game.getDeck();

    if (deck.empty()) {
        printf("        Deck is empty. The Oracle sees nothing.\n");
        return;
    }

    printf("        The Oracle sees a %s\n", deck.back()->str().c_str());
}

std::string Oracle::str()
{
    return "Oracle(" + std::to_string(_value) + ")";
}
