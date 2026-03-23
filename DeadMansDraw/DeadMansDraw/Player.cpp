#include "Player.h"

Player::Player()
{
    const std::string nameArray[10] = {"Emma", "Billy", "Sasha", "Bob", "Jack", "Olivia", "Ed", "Diane", "Phil", "Jade"};
    name = nameArray[rand() % 10];
}

Player::~Player()
{
}

void Player::displayPlayArea()
{
    printf("%s's Play Area: \n", name.c_str());

    if (playArea.empty()) {
        return;
    }

    for (Card* card : playArea) {
        printf("        %s\n", card->str().c_str());
    }
}

bool Player::isBust()
{
    return false;
}

void Player::moveToBank()
{
    for (Card* card : playArea)
    {
        bank.push_back(card);
    }

    playArea.clear();
}

void Player::displayBank()
{
    printf("%s's Bank: \n", name.c_str());

    std::map<CardType, std::vector<Card*>> suit;

    // Adding cards to suit map
    for (Card* card : bank) {
        suit[card->type()].push_back(card);
    }

    for (auto& group : suit) {

        auto& cards = group.second;

        //Sort cards in descending order
        std::sort(cards.begin(), cards.end(), [](const Card* a, const Card* b) {
            return a->getValue() > b->getValue();
            });

        printf("       ");

       for (Card* card : cards) {
           printf(" %s", card->str().c_str());

       }

       printf("\n");
}

    getScore();
}

int Player::getScore()
{
    printf("| Score: 0\n");
    return 0;
}

bool Player::PlayCard(Card* card, Game&)
{
    playArea.push_back(card);
    return false; // Also implement bust here
}
