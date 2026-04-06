#include "Game.h"

Game::Game() :

    _round(1),
    _turnNum(1),
    _currentPlayer(0),
    _turnOver(false),
    _roundTracker(2),
    _krakenDraws(0)

{

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

const CardCollection& Game::getDeck() const
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

void Game::setKrakenDraws(const int draws)
{
    _krakenDraws = draws;
}

// -----Game Functionality ------

void Game::startGame()
{
    printf("%s\n", GAME_TITLE);
    printf("Starting Dead Man's Draw++!\n");

    // Keeps track of the turns - 20 turns per game
    for(int i = 0; i < 20; ++i) {

        // Ends game if deck is empty
        if(deck.empty()) {
            break;
        }

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

// Main game loop for a player's turn
void Game::turn()
{
    _turnOver = { false };
    _krakenDraws = { 0 };
    std::string response;

    printf("%s's Turn.\n", players[_currentPlayer]->getName().c_str()); // Need getters for name
    players[_currentPlayer]->displayBank();
    executeCardTurn();

    while (true) {

        if (isTurnOver()) {
            return;
        }

        //Specific draw rules for the kraken ability
        if (_krakenDraws > 0) {

            while (_krakenDraws > 0) {

                executeCardTurn();
                _krakenDraws--;

                if (isTurnOver()) {
                    return;
                }
            }

            _krakenDraws = 0;
        }

        players[_currentPlayer]->displayPlayArea();

        printf("\nDraw Again? (y/n): ");
        std::getline(std::cin, response);

        if (!response.empty() && response.front() == 'n') {

            players[_currentPlayer]->moveToBank(*this);
            players[_currentPlayer]->displayBank();
            endTurn();
            break;
        }
        if (!response.empty() && response.front() == 'y') {
            break;
        }
    }
}

// Draws card to play area and checks if bust
bool Game::drawToPlayArea(Player& player, std::unique_ptr<Card> card)
{
    printf("%s draws a %s\n", player.getName().c_str(), card->str().c_str());
    bool isBust = { player.PlayCard(std::move(card), *this) };

    if (isBust) {

        printf("BUST! %s loses all cards in play area.\n", players[_currentPlayer]->getName().c_str());
        CardCollection& playArea = players[_currentPlayer]->getPlayArea();
        moveToDiscard(playArea);
        endTurn();
        return true;
    }

    return false;
}

// Draws a card from the deck and returns it as a unique_ptr
std::unique_ptr<Card> Game::draw()

{ 
    auto card = std::move(deck.back());
    deck.pop_back();
    return card;
}

void Game::gameTracker()
{
    printf("--- Round %d, Turn %d ---\n", _round, _turnNum);
    _turnNum++;

}

// Moves cards from play area to discard pile
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
    _turnOver = { true };
    _roundTracker--;

    // After both players have had a turn, move to the next round
    if (_roundTracker <= 0) {

        _round++;
        _roundTracker = { 2 };
    }

    _currentPlayer = { (_currentPlayer + 1) % 2 };
}

bool Game::isTurnOver() const
{
    return _turnOver;
}

// Executes the logic for a player's turn, including drawing a card and playing it
void Game::executeCardTurn()
{
    auto card = draw();
    Card* rawPtr = card.get();

    // Check if card can be added to play area without busting, if so add and end turn, otherwise play card as normal
    if (drawToPlayArea(*players[_currentPlayer], std::move(card))) {
        return;
    }

    rawPtr->play(*this, *players[_currentPlayer]);

    // Checks if card ability causes a bust
    if (isTurnOver()) {
        return;
    }
}

