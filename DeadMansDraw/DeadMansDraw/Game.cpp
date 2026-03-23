#include "Game.h"

Game::Game()
{
    round = 1;
    turnNum = 1;
    currentPlayer = 0;

    initialiseDeck();
    shuffle();
    createPlayer();
}

Game::~Game()
{
    delete players[0];
    delete players[1];

    for (Card* card : deck) {
        delete card;
    }
}

void Game::startGame()
{
    std::cout << GAME_TITLE << std::endl;
    printf("Starting Dead Man's Draw++!\n");

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
    std::string response;

    printf("%s's Turn.\n", players[currentPlayer]->name.c_str()); // Need getters for name
    players[currentPlayer]->displayBank();
    Card* card = draw();
    bool isBust = players[currentPlayer]->PlayCard(card, *this); // Moves card to play area and checks if bust

    // Need to implement discard system
    if (isBust) {
        printf("BUST! %s loses all cards in play area.\n", players[currentPlayer]->name.c_str()); 
        currentPlayer++;
        return;
     }

    players[currentPlayer]->displayPlayArea();

    while (true) {

        printf("\nDraw Again? (y/n): ");
        std::getline(std::cin, response);

        // FIX THIS TO BE BETTER LATER
        if (response.front() == 'n') {
            players[currentPlayer]->moveToBank();
            players[currentPlayer]->displayBank();
            currentPlayer++;
            break;
        }
        if (response.front() == 'y') {
            break;
        }
    }
}

Card* Game::draw()

{ 
    Card* card = deck.back();
    deck.pop_back();
    printf("%s draws a %s\n", players[currentPlayer]->name.c_str(), card->str().c_str());
    return card;
}


void Game::gameTracker()
{
    if (currentPlayer == 2) {
        currentPlayer = 0;
        round++;
    }

    printf("--- Round %d, Turn %d ---\n", round, turnNum);
    turnNum++;

}
