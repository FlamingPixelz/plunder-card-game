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
}

bool Player::isBust()
{
    return false;
}

void Player::moveToBank()
{
}

void Player::displayBank()
{
    printf("%s's Bank: \n", name.c_str());
    getScore();
}

void Player::getScore()
{
    printf("| Score: 0\n");
}

bool Player::PlayCard(Card*, Game&)
{
    return false;
}
