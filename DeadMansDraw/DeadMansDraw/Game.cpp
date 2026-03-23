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

    printf("Player Wins!");

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

    printf("%s's Turn.\n", players[currentPlayer]->name.c_str());
    players[currentPlayer]->displayBank();
    draw();
    // players[currentPlayer]->PlayCard(Card*, Game&); // Moves card to play area and checks if bust
    players[currentPlayer]->displayPlayArea();

    while (true) {

        printf("Draw Again? (y/n):");
        std::getline(std::cin, response);

        // FIX THIS TO BE BETTER LATER
        if (response.front() == 'n') {
            currentPlayer++;
            break;
        }
        if (response.front() == 'y') {
            break;
        }
    }
}

void Game::draw()

{ 
    Card* card = deck.back();
    deck.pop_back();
    printf("%s draws a %s\n", players[currentPlayer]->name.c_str(), card->str().c_str());
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
