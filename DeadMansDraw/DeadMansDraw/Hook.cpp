#include "Hook.h"
#include "Player.h"
#include "Game.h"

Hook::Hook(int value) : Card(value, hook)
{
}

void Hook::play(Game& game, Player& player)
{
    std::vector<Card*> playerBank = { player.getHighestCardsFromBank() };

    if (playerBank.empty()) {
        printf("        No cards in your Bank. Play continues.\n");
        return; 
    }

    printf("        Select a highest-value card from any of the suits in your Bank:\n");
    for (int i = 0; i < playerBank.size(); i++) {
        printf("       (%d) %s\n", i + 1, playerBank[i]->str().c_str());
    }

    std::string input;
    int choice = { 0 };

    //Input Validation
    while (true) {

        printf("        Which card do you pick? ");
        std::getline(std::cin, input);

        try {
            choice = std::stoi(input);
        }
        catch (...) {
        }

        if (choice < 1 || choice > playerBank.size()) {
        }
        else {
            break;
        }
    }

    Card* selectedCard = playerBank[choice - 1];

    // Move card from bank back into play area
    auto taken = player.removeFromBank(selectedCard);
    Card* rawPtr = { taken.get() };

    if (game.drawToPlayArea(player, std::move(taken))) {
        return;
    }

    rawPtr->play(game, player);

}

std::string Hook::str()
{
    return "Hook(" + std::to_string(_value) + ")";
}
