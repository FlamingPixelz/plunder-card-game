#include "Sword.h"
#include "Game.h"
#include "Player.h"

Sword::Sword(int value) : Card(value, sword) {

}

void Sword::play(Game& game, Player& player)
{
    Player& opponent = game.getOpponent(player);

    std::vector<Card*> opponentHighestCards = opponent.getHighestCardsFromBank();

    if (opponentHighestCards.empty()) {
        printf("        No cards in other player's Bank. Play continues.\n");
        return;
    }

    printf("        Steal the top card of any suit from the other player's Bank into you Play Area:\n");
    for (int i = 0; i < opponentHighestCards.size(); i++) {
        printf("       (%d) %s\n", i + 1, opponentHighestCards[i]->str().c_str());
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

        if (choice < 1 || choice > opponentHighestCards.size()) {
        }
        else {
            break;
        }

    }

    Card* selectedCard = opponentHighestCards[choice - 1];

    //Remove Card from Opponent's Bank
    auto taken = opponent.removeFromBank(selectedCard);
    Card* rawPtr = taken.get();

    if (game.drawToPlayArea(player, std::move(taken))) {
        return;
    }

    rawPtr->play(game, player);

}

std::string Sword::str()
{
    return "Sword(" + std::to_string(value) + ")";
}
