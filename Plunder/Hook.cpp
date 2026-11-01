#include "Hook.h"
#include "Player.h"
#include "Game.h"

Hook::Hook(int value) : Card(value, CardType::hook)
{
}

void Hook::play(Game& game, Player& player)
{
    std::vector<Card*> playerBank = { player.getHighestCardsFromBank() };

    if (playerBank.empty()) {
        printf("\tNo cards in your Bank. Play continues.\n");
        return; 
    }

    printf("\tSelect a highest-value card from any of the suits in your Bank:\n");
    for (size_t i = 0; i < playerBank.size(); i++) {
        printf("\t(%ld) %s\n", i + 1, playerBank[i]->str().c_str());
    }

    std::string input;
    int choice = { 0 };

    //Input Validation
    while (true) {

        printf("\tWhich card do you pick? ");
        std::getline(std::cin, input);

        try {
            choice = std::stoi(input);
        }
        catch (...) {
        }

        if (choice < 1 || choice > static_cast<int>(playerBank.size())) {
        }
        else {
            break;
        }
    }

    Card* selectedCard = playerBank[choice - 1];

    //Move card from bank back into play area
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
