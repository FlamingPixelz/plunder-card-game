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

    for (Card* card : bank) {
        printf("        %s\n", card->str().c_str());
    }

    getScore();
}

void Player::getScore()
{
    printf("| Score: 0\n");
}

bool Player::PlayCard(Card* card, Game&)
{
    playArea.push_back(card);
    return false; // Also implement bust here
}
