#include "Cannon.h"
#include "Game.h"
#include "Player.h"

Cannon::Cannon(int value) : Card(value, cannon) {

}

void Cannon::play(Game& game, Player& player)
{
    Player& opponent = game.getOpponent(player);

    std::vector<Card*> opponentHighestCards = opponent.getHighestCardsFromBank();

    if (opponentHighestCards.empty()) {
        printf("        No cards in other player's Bank. Play continues.\n");
        return;
    }

    printf("        Shoot the top card of any suit from the other player's Bank into the Discard Pile:\n");
    for (int i = 0; i < opponentHighestCards.size(); i++) {
        printf("       (%d) %s\n", i + 1, opponentHighestCards[i]->str().c_str());
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

        if (choice < 1 || choice > opponentHighestCards.size()) {
        }
        else {
            break;
        }

    }

    Card* selectedCard = opponentHighestCards[choice - 1];

    //Remove Card from Opponent's Bank and add to discard pile
    Card* discarded = opponent.removeFromBank(selectedCard);

    printf("        You shoot the %s out of the other Player's bank\n", discarded->str().c_str());

    game.getDiscard().push_back(discarded);

}

std::string Cannon::str()
{
    return "Cannon(" + std::to_string(value) + ")";
}
