# Tic-Tac-Toe Game

## Overview

This repository contains a simple implementation of the classic Tic-Tac-Toe game in C++. The game allows two players to take turns, placing their respective pieces (X or O) on a 3x3 grid. The program checks for a winning condition after each move and declares the winner accordingly. If no winner is found and the grid is filled, the game ends in a draw.

## Features

- **User Input:** Players are prompted to input the row and column of their move.
- **Winning Condition:** The program checks for winning combinations in rows, columns, and diagonals.
- **Draw Condition:** If all positions on the grid are filled and no winner is found, the game ends in a draw.
- **Board Display:** The current state of the game board is displayed after each move.

## How to Play

1. Clone the repository to your local machine.
2. Compile the program using a C++ compiler.
3. Run the executable.
4. Follow the on-screen prompts to input your moves.

## Code Structure

- **`main.cpp`:** Contains the main function where the game loop is executed.
- **`functions.cpp`:** Defines functions for filling the array, checking for a win, taking user input, and printing the game board.

## Build and Run

Compile the program using a C++ compiler. For example:

```
bash
g++ main.cpp functions.cpp -o tic_tac_toe
```
