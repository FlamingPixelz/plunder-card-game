#include "Map.h"
#include "Player.h"
#include "Game.h"

Map::Map(int value) : Card(value, map) {

}

void Map::play(Game& game, Player& player)
{
    CardCollection& discard = game.getDiscard();

    if (discard.empty()) {
        printf("        No cards in the Discard pile. Play continues.\n");
        return;
    }

    printf("        Draw 3 cards from the discard and pick one to add to the play area:\n");

    // Handles if there are less than 3 cards in the discard pile
    int count = std::min(3, (int)discard.size());

    for (int i = 0; i < count && i < discard.size(); i++) {
        Card* card = discard[discard.size() - 1 - i];
        printf("       (%d) %s\n", i + 1, card->str().c_str());
    }

    std::string input;
    int choice = { 0 };

    // Input validation
    while (true) {

        printf("        Which card do you pick? ");
        std::getline(std::cin, input);

        try {
            choice = std::stoi(input);
        }
        catch (...) {
        }

        if (choice < 1 || choice > discard.size()) {
        }
        else {
            break;
        }

    }

    //Delete chosen card from discard and add to play area
    auto index = discard.size() - choice;

    Card* selectedCard = { discard[index] };
    discard.erase(discard.begin() + index);

    if (game.drawToPlayArea(player, selectedCard)) {
        return;
    }

    selectedCard->play(game, player);
}

std::string Map::str()
{
    return "Map(" + std::to_string(value) + ")";
}
