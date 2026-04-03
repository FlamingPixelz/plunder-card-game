#include "Chest.h"
#include "Player.h"
#include "Game.h"

Chest::Chest(int value) : Card(value, chest) {

}

void Chest::play(Game&, Player&)
{
    printf("\t\tNo immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n");
}

std::string Chest::str()
{
    return "Chest(" + std::to_string(value) + ")";
}

//Implementation here and not in key
void Chest::willAddToBank(Game& game, Player& player)
{
    bool hasKey = false;
    bool hasChest = false;

    CardCollection& playArea = player.getPlayArea();
    CardCollection& discard = game.getDiscard();
    CardCollection& bank = player.getBank();

    for (Card* card : playArea) {

        if(card->type() == key) hasKey = true;
        if (card->type() == chest) hasChest = true;
    }

    if (!(hasChest && hasKey)) return;

    auto cardsToDraw = playArea.size();
    std::vector<Card*> bonusCards;

    for (int i = 0; i < cardsToDraw && !discard.empty(); i++)
    {
        Card* card = discard.back();
        discard.pop_back();
        bank.push_back(card);
        bonusCards.push_back(card);
    }

    //Builds string response and states drawn cards added to bank

    if(discard.empty()) {
        printf("\tChest and Key activated, but the Discard pile is empty. Play continues.\n");
        return;
    }

    printf("\tChest and Key activated. Added ");
    for (int i = 0; i < bonusCards.size(); i++)
    {
        printf("%s", bonusCards[i]->str().c_str());
        if (i < bonusCards.size() - 1) {
            printf(", ");
        }
    }
    printf(" to your bank.\n");
}
