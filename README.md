# Plunder

<img width="1484" height="1033" alt="Screenshot_20261101_172919" src="https://github.com/user-attachments/assets/c33fc756-6a92-48ef-bc8e-82e05f9bfc0a" />

In this console-based card game, 2 players take turns drawing cards that activate special abilities that can affect the amount of points you or your opponent receives. However, you will bust when you draw a duplicate suit and lose all of your cards in your play area, encouraging risk vs. reward gameplay. The player with the most points at the end of the game wins!

## How to Play

| Card | Ability |
|------|---------|
| Cannon | Discard the highest scoring card of any suit from the other player's Bank, which will remove it from their bank and add it to the discard pile |
| Chest | Only activates when banked with a key - Draw as many bonus cards from the discard pile as you have moved into your bank. For example, if you have 4 cards in your play area (two of which are a chest and key), and you bank, if there are 4 cards in the discard pile, you will also bank those cards. |
| Hook | Select the highest-value card from any of the suits in your bank, move it to your play area, and play its ability |
| Key | Only activates when banked with a Chest (See above explanation for chest) |
| Kraken | Must draw three cards from the deck and play each |
| Map | Draw 3 cards from the discard and pick one to add to your play area |
| Mermaid | Doesn't have an effect, but is worth more than other cards |
| Oracle | Will show you the next card in the deck |
| Sword | Steal the highest scoring card of any suit from the other player's bank, and add to your play area |

There are 6 cards of each suit, with points ranging from 2 - 7 (except for mermaid, which is 4-9). Each player will draw a card, play its ability, and have to decide whether to keep playing or pass to the next player using the y and n keys. 

Some card abilities will ask the player to pick a number in order to pick a card. Inputting that number and pressing enter will select that card.

If you draw 2 of the same suit into your play area, you will bust, losing all of your cards in the play area and passing on to the next player.

At the end of your turn, the cards in your play area will move to your bank, and add to your score. 

The game will end after 20 turns, or when the deck runs out of cards, and will declare the winner. 

## Installation

### Requirements
You must have a C++17 compiler installed on your system (g++ 7+, clang 5+, or MSVC 2017+), and Linux / MacOS need the `make` package

### Build & Run on Linux/MacOS
```bash
git clone https://github.com/FlamingPixelz/plunder-card-game.git
cd plunder-card-game
make run
```

### Build and Run on Windows

Users of WSL can follow the above commands for linux.
Open `Plunder/Plunder.slnx` in Visual Studio and press **F5**.

## Development
This project was built in C++ using OOP principles and smart pointers. 

Each card class ability overrides the play() method of the abstract Card class.  

Unique pointers were used for the creation of card objects and players so that no manual delete is needed, preventing memory leaks. Error handling via input validation was also implemented so that the user cannot break the game if they make a mistake.

### Class Diagram
The game was first designed using a UML class diagram before being implemented:
<img width="1777" height="1118" alt="image" src="https://github.com/user-attachments/assets/553dfd35-24e6-4ff5-a73c-2e32af66432a" />

See the [System Design Document](System%20Design%20Document.pdf) for more detail on the design decisions that went into this project. 

This project compiles cleanly with -Wall with no errors or warnings, and contains no memory leaks, which was verified using AddressSanitizer.

## Plans For Further Improvement

- Add unit tests for scoring and bust logic
- Create an AI opponent instead of local 2 player (or a choice between the two)
- Ask for player names rather than generating random ones from a list
- Add better visual design, like a python-textual front-end or coloured ascii to represent each card ability
- Switch the build to CMake for one cross platform build system
