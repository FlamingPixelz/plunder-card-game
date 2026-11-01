# Plunder

<img width="1484" height="1033" alt="Screenshot_20261101_172919" src="https://github.com/user-attachments/assets/c33fc756-6a92-48ef-bc8e-82e05f9bfc0a" />

In this console-based card game, 2 players take turns drawing cards that activate special abilities that can affect the amount of points you or your opponent receives, but busting when you draw a duplicate card, encouraging risk vs. reward gameplay. The player with the most points at the end of the game wins!

## Installation

### Requirements
You must have a c++17 compiler installed on your system (g++ 7+, clang 5+, or MSVC 2017+)

### Build & Run on Linux/MacOS
```bash
git clone https://github.com/FlamingPixelz/plunder-card-game.git
cd plunder-card-game
make run
```

### Build and Run on Windows
Open `Plunder/Plunder.slnx` in Visual Studio and press **F5**.

## Development
This project was built in C++ using OOP principles and smart pointers. Unique pointers were used for the creation of card objects and players so that no manual delete is needed, preventing memory leaks. Error handling via input validation was also implemented so that the user cannot break the game if they make a mistake.

### Class Diagram
The game was first designed using a UML class diagram before being implemented:
<img width="1777" height="1118" alt="image" src="https://github.com/user-attachments/assets/553dfd35-24e6-4ff5-a73c-2e32af66432a" />

See also the System Design Document for further implementation of requirements and diagrams.
