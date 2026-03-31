#include "Player.h"

Player::Player()
{
    const std::string nameArray[10] = {"Emma", "Billy", "Sasha", "Bob", "Jack", "Olivia", "Ed", "Diane", "Phil", "Jade"};
    name = nameArray[rand() % 10];
}

Player::~Player()
{
    for (Card* card : bank) {
        //printf("Deleting card %s from bank\n", card->str().c_str()); // test
        delete card;
    }
    for (Card* card : playArea) {
        //printf("Deleting card %s from play area\n", card->str().c_str()); // test
        delete card;
    }
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
    std::set<CardType> checkDuplicate;

    // Creates set and checks for duplicate cards
    for (Card* card : playArea) {

        CardType suit = card->type();

        if (checkDuplicate.find(suit) != checkDuplicate.end()) {
            return true;
        }

        checkDuplicate.insert(suit);
    }

    return false;
}

CardCollection& Player::getPlayArea()
{
    return playArea;
}

const CardCollection& Player::getBank()
{
    return bank;
}

const std::string& Player::getName()
{
    return name;
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

    printf("| Score: %d\n", calculateScore());
}

int Player::calculateScore()
{
    int score = { 0 };
    std::map<CardType, int> highestCard;    

    for (Card* card : bank) {
    CardType suit = card->type();

      if (highestCard.find(suit) == highestCard.end() || card->getValue() > highestCard[suit]) {

           highestCard[suit] = card->getValue();
      }
    }

    for (auto& pair : highestCard) {
        score += pair.second;
    }

    return score;
}

bool Player::PlayCard(Card* card, Game&)
{

    playArea.push_back(card);

    if (isBust()) {
        return true;
    }

    return false;
}

// Helper Functions for Card Abilities


std::vector<Card*> Player::getHighestCardsFromBank()
{
    std::map<CardType, Card*> highestCard;

    for (Card* card : bank) {
        CardType suit = card->type();

        if (highestCard.find(suit) == highestCard.end() || card->getValue() > highestCard[suit]->getValue()) {
            highestCard[suit] = card;
        }
    }

    std::vector<Card*> results;

    for (auto& pair : highestCard) {
        results.push_back(pair.second);
    }

    return results;
}

Card* Player::removeFromBank(Card* card)
{

    for (auto i = bank.begin(); i != bank.end(); ++i) {
        if (*i == card) {
            Card* removedCard = *i;
            bank.erase(i);
            return removedCard;
        }
    }

    return nullptr;
}
