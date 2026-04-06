#include "Game.h"

Game::Game()
{
    round = { 1 };
    turnNum = { 1 };
    currentPlayer = { 0 };
    turnOver = { false };
    roundTracker = { 2 };
    krakenDraws = { 0 };

    initialiseDeck();
    shuffle();
    createPlayer();
}

Game::~Game() = default;


// -----Getters and setters------

CardCollection& Game::getDiscard()
{
    return discard;
}

CardCollection& Game::getDeck()
{
    return deck;
}

Player& Game::getOpponent(const Player& currentPlayer) const
{
    if (&currentPlayer == players[0].get()) {
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

    if (players[0]->calculateScore() > players[1]->calculateScore()) {
        printf("%s Wins!\n", players[0]->getName().c_str());
        return;
    }
    if(players[1]->calculateScore() > players[0]->calculateScore()) {
        printf("%s Wins!\n", players[1]->getName().c_str());
        return;
    }
    else {
        printf("It's a tie!\n");
    }
}

void Game::initialiseDeck()
{
    int cardValue[6] = { 2, 3, 4, 5, 6, 7 };

    for (int i : cardValue) {

        deck.push_back(std::make_unique<Cannon>(i));
        deck.push_back(std::make_unique<Chest>(i));
        deck.push_back(std::make_unique<Hook>(i));
        deck.push_back(std::make_unique<Key>(i));
        deck.push_back(std::make_unique<Kraken>(i));
        deck.push_back(std::make_unique<Map>(i));
        deck.push_back(std::make_unique<Mermaid>(i + 2));
        deck.push_back(std::make_unique<Oracle>(i));
        deck.push_back(std::make_unique<Sword>(i));
    }

}

void Game::shuffle()
{
    std::shuffle(deck.begin(), deck.end(), std::mt19937{ std::random_device{}() });
}

void Game::createPlayer()
{
    players[0] = std::make_unique<Player>();
    players[1] = std::make_unique<Player>();
}


void Game::turn()
{
    turnOver = false;
    krakenDraws = 0;
    std::string response;

    printf("%s's Turn.\n", players[currentPlayer]->getName().c_str()); // Need getters for name
    players[currentPlayer]->displayBank();
    executeCardTurn();

    while (true) {

        if (isTurnOver()) {
            return;
        }

        //Specific draw rules for the kraken ability
        if (krakenDraws > 0) {

            while (krakenDraws > 0) {

                executeCardTurn();
                krakenDraws--;

                if (isTurnOver()) {
                    return;
                }
            }

            krakenDraws = 0;
        }

        players[currentPlayer]->displayPlayArea();

        printf("\nDraw Again? (y/n): ");
        std::getline(std::cin, response);

        if (!response.empty() && response.front() == 'n') {

            players[currentPlayer]->moveToBank(*this);
            players[currentPlayer]->displayBank();
            endTurn();
            break;
        }
        if (!response.empty() && response.front() == 'y') {
            break;
        }
    }
}

bool Game::drawToPlayArea(Player& player, std::unique_ptr<Card> card)
{
    printf("%s draws a %s\n", player.getName().c_str(), card->str().c_str());
    bool isBust = player.PlayCard(std::move(card), *this);

    if (isBust) {

        printf("BUST! %s loses all cards in play area.\n", players[currentPlayer]->getName().c_str());
        CardCollection& playArea = players[currentPlayer]->getPlayArea();
        moveToDiscard(playArea);
        endTurn();
        return true;
    }

    return false;
}

std::unique_ptr<Card> Game::draw()

{ 
    auto card = std::move(deck.back());
    deck.pop_back();
    return card;
}


void Game::gameTracker()
{
    printf("--- Round %d, Turn %d ---\n", round, turnNum);
    turnNum++;

}

void Game::moveToDiscard(CardCollection& playArea)
{
    for (auto& card : playArea) {
        discard.push_back(std::move(card));
        //printf("Discarding card %s\n", card->str().c_str()); // Test that discard is working
    }

    playArea.clear();
}

void Game::endTurn()
{
    turnOver = true;
    roundTracker--;

    // After both players have had a turn, move to the next round
    if (roundTracker <= 0) {

        round++;
        roundTracker = 2;
    }

    currentPlayer = (currentPlayer + 1) % 2;
}

bool Game::isTurnOver() const
{
    return turnOver;
}

void Game::executeCardTurn()
{
    auto card = draw();
    Card* rawPtr = card.get();

    // Check if card can be added to play area without busting, if so add and end turn, otherwise play card as normal
    if (drawToPlayArea(*players[currentPlayer], std::move(card))) {
        return;
    }

    rawPtr->play(*this, *players[currentPlayer]);

    // Checks if card ability causes a bust
    if (isTurnOver()) {
        return;
    }
}

