#include "Chest.h"
#include "Player.h"
#include "Game.h"

Chest::Chest(int value) : Card(value, CardType::chest) {

}

void Chest::play(Game&, Player&)
{
    printf("\tNo immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank.\n");
}

std::string Chest::str()
{
    return "Chest(" + std::to_string(_value) + ")";
}

//Implementation here and not in key
void Chest::willAddToBank(Game& game, Player& player)
{
    bool hasKey = { false };
    bool hasChest = { false };

    auto& playArea = player.getPlayArea();
    auto& discard = game.getDiscard();
    auto& bank = player.getBank();

    for (auto& card : playArea) {

        if (card->type() == CardType::key) {
            hasKey = true;
        }
        if (card->type() == CardType::chest) {
            hasChest = true;
        }
    }

    if (!(hasChest && hasKey)) return;

    auto cardsToDraw = playArea.size();
    std::vector<Card*> bonusCards;

    for (int i = 0; i < cardsToDraw && !discard.empty(); i++)
    {
        auto& card = discard.back();
        discard.pop_back();
        bank.push_back(std::move(card));
        bonusCards.push_back(card.get());
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
