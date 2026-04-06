#include "Player.h"

Player::Player()
{
    const std::string nameArray[10] = {"Emma", "Billy", "Sasha", "Bob", "Jack", "Olivia", "Ed", "Diane", "Phil", "Jade"};
    _name = nameArray[rand() % 10];
}

Player::~Player() = default;

void Player::displayPlayArea() const
{
    printf("%s's Play Area: \n", _name.c_str());

    if (_playArea.empty()) {
        return;
    }

    for (auto& card : _playArea) {
        printf("\t%s\n", card->str().c_str());
    }
}

bool Player::isBust() const
{
    std::set<CardType> checkDuplicate;

    //Creates set and checks for duplicate cards
    for (auto& card : _playArea) {

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
    return _playArea;
}

CardCollection& Player::getBank()
{
    return _bank;
}

const std::string& Player::getName() const
{
    return _name;
}

void Player::moveToBank(Game& game)
{
    //Checks for chest and key together in playArea
    for(auto& card : _playArea)
    {
        card->willAddToBank(game, *this);
    }

    for (auto& card : _playArea)
    {
        _bank.push_back(std::move(card));
    }

    _playArea.clear();
}

void Player::displayBank() const
{
    printf("%s's Bank: \n", _name.c_str());

    std::map<CardType, std::vector<Card*>> suit;

    //Adding cards to suit map
    for (auto& card : _bank) {
        suit[card->type()].push_back(card.get());
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

int Player::calculateScore() const
{
    int score = { 0 };
    std::map<CardType, int> highestCard;    

    for (auto& card : _bank) {
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

bool Player::PlayCard(std::unique_ptr<Card> card, Game& game)
{

    _playArea.push_back(std::move(card));

    if (isBust()) {
        return true;
    }

    return false;
}

//---Helper Functions for Card Abilities---


std::vector<Card*> Player::getHighestCardsFromBank()
{
    std::map<CardType, Card*> highestCard;

    for (auto& card : _bank) {
        CardType suit = card->type();

        if (highestCard.find(suit) == highestCard.end() || card->getValue() > highestCard[suit]->getValue()) {
            highestCard[suit] = card.get();
        }
    }

    std::vector<Card*> results;

    for (auto& pair : highestCard) {
        results.push_back(pair.second);
    }

    return results;
}

std::unique_ptr<Card> Player::removeFromBank(Card* card)
{

    for (auto i = _bank.begin(); i != _bank.end(); ++i) {
        if (i->get() == card) {

            std::unique_ptr<Card> removedCard = std::move(*i);
            _bank.erase(i);
            return removedCard;
        }
    }

    return nullptr;
}
