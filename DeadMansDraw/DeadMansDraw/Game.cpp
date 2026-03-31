#include "Game.h"

Game::Game()
{
    round = { 1 };
    turnNum = { 1 };
    currentPlayer = { 0 };
    turnOver = { false };
    krakenDraws = { 0 };

    initialiseDeck();
    shuffle();
    createPlayer();
}

Game::~Game()
{
    delete players[0];
    delete players[1];

    for (Card* card : deck) {
        //printf("Deleting card %s from deck\n", card->str().c_str()); // Test
        delete card;
    }
    for (Card* card : discard) {
        //printf("Deleting card %s from discard\n", card->str().c_str()); // Test
        delete card;
    }
}

CardCollection& Game::getDiscard()
{
    return discard;
}

CardCollection& Game::getDeck()
{
    return deck;
}

Player& Game::getOpponent(Player& currentPlayer)
{
    if (&currentPlayer == players[0]) {
        return *players[1];
    }
    return *players[0];
}

void Game::setKrakenDraws(int draws)
{
    krakenDraws = draws;
}

void Game::startGame()
{
    std::cout << GAME_TITLE << std::endl;
    printf("Starting Dead Man's Draw++!\n");

    // Keeps track of the turns - 20 turns per game
    for(int i = 0; i < 20; ++i) {

        gameTracker();
        turn();
    }

    endGame();
}

void Game::endGame()
{
    printf("--- Game Over ---\n");
    players[0]->displayBank();
    players[1]->displayBank();

    printf("Player Wins!"); // Change to state winning player's name

}

void Game::initialiseDeck()
{
    int cardValue[6] = { 2, 3, 4, 5, 6, 7 };

    for (int i : cardValue) {

        deck.push_back(new Cannon(i));
        deck.push_back(new Chest(i));
        deck.push_back(new Hook(i));
        deck.push_back(new Key(i));
        deck.push_back(new Kraken(i));
        deck.push_back(new Map(i));
        deck.push_back(new Mermaid(i + 2));
        deck.push_back(new Oracle(i));
        deck.push_back(new Sword(i));
    }

}

void Game::shuffle()
{
    std::shuffle(deck.begin(), deck.end(), std::mt19937{ std::random_device{}() });
}

void Game::createPlayer()
{
    players[0] = new Player();
    players[1] = new Player();
}


void Game::turn()
{
    turnOver = false;
    krakenDraws = 0;
    std::string response;

    printf("%s's Turn.\n", players[currentPlayer]->name.c_str()); // Need getters for name
    players[currentPlayer]->displayBank();
    executeCardTurn();

    while (true) {

        if (isTurnOver()) {
            return;
        }

        //Specific draw rules for the kraken ability
        if (krakenDraws > 0) {

            for (int i = 0; i < krakenDraws; ++i) {
                executeCardTurn();
            }

            krakenDraws = 0;
        }

        players[currentPlayer]->displayPlayArea();

        printf("\nDraw Again? (y/n): ");
        std::getline(std::cin, response);

        // FIX THIS TO BE BETTER LATER
        if (response.front() == 'n') {
            players[currentPlayer]->moveToBank();
            players[currentPlayer]->displayBank();
            currentPlayer = (currentPlayer + 1) % 2;
            break;
        }
        if (response.front() == 'y') {
            break;
        }
    }
}

bool Game::drawToPlayArea(Player& player, Card* card)
{
    printf("%s draws a %s\n", player.name.c_str(), card->str().c_str());
    bool isBust = player.PlayCard(card, *this);

    if (isBust) {

        printf("BUST! %s loses all cards in play area.\n", players[currentPlayer]->name.c_str());
        CardCollection& playArea = players[currentPlayer]->getPlayArea();
        moveToDiscard(playArea);
        endTurn();
        return true;
    }

    return false;
}

Card* Game::draw()

{ 
    Card* card = deck.back();
    deck.pop_back();
    return card;
}


void Game::gameTracker()
{
    if (currentPlayer == 0 && turnNum > 1) {
        round++;
    }

    printf("--- Round %d, Turn %d ---\n", round, turnNum);
    turnNum++;

}

void Game::moveToDiscard(CardCollection& playArea)
{
    for (Card* card : playArea) {
        discard.push_back(card);
        //printf("Discarding card %s\n", card->str().c_str()); // Test that discard is working
    }

    playArea.clear();
}

void Game::endTurn()
{
    turnOver = true;
}

bool Game::isTurnOver() const
{
    return turnOver;
}

void Game::executeCardTurn()
{
    Card* card = draw();

    // Check if card can be added to play area without busting, if so add and end turn, otherwise play card as normal
    if (drawToPlayArea(*players[currentPlayer], card)) {
        currentPlayer = (currentPlayer + 1) % 2;
        return;
    }

    card->play(*this, *players[currentPlayer]);

    // Checks if card ability causes a bust
    if (isTurnOver()) {
        currentPlayer = (currentPlayer + 1) % 2;
        return;
    }
}

