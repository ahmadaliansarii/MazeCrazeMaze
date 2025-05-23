# MazeCrazeMaze - A Classic C++ Console Maze Game

[![GitHub](https://img.shields.io/badge/GitHub-Repo-blue?style=flat-square&logo=github)](https://github.com/ahmadaliansarii/MazeCrazeMaze)

MazeCrazeMaze is a thrilling console-based maze game developed in C++. Navigate intricate mazes as the Hero, collect points, strategically use power-ups, and outsmart mischievous ghosts. With multiple difficulty levels and dynamic gameplay, challenge yourself to achieve the highest score before time runs out or the ghosts catch you!

## Table of Contents

-   [Features](#features)
-   [How to Play](#how-to-play)
-   [Game Elements Legend](#game-elements-legend)
-   [Installation and Setup](#installation-and-setup)
-   [Controls](#controls)
-   [Compatibility](#compatibility)
-   [Credits](#credits)

## Features

*   **Multiple Difficulty Levels:** Choose from Easy, Medium, or Hard mazes, each offering a unique challenge.
*   **Dynamic Maze Loading:** Mazes are loaded from external text files, allowing for easy expansion and customization.
*   **Hero Character:** Control your `@` hero to explore the maze.
*   **Collectible Points:** Gather `.` symbols to increase your score.
*   **Power-Ups:** Collect `+` power-ups to temporarily freeze ghosts, giving you a strategic advantage.
*   **Intelligent Ghosts:** `G` ghosts employ basic AI, chasing the hero when close or moving randomly otherwise.
*   **Portals:** Discover `0` portals, which serve as an alternative way to end the game.
*   **Score Tracking:** Keep track of your points as you navigate the maze.
*   **Time-Based Gameplay:** Complete the maze and gather points within a set time limit.
*   **Console-Based Graphics:** A minimalist yet effective ASCII art interface.

## How to Play

1.  **Start the Game:** Run the compiled executable.
2.  **Choose Your Level:** Select your preferred difficulty (Easy, Medium, Hard).
3.  **Navigate:** Use the `W`, `A`, `S`, `D` keys to move your hero (`@`) through the maze.
4.  **Collect Points:** Move over `.` symbols to earn points.
5.  **Use Power-Ups:** Grab `+` symbols to temporarily stop ghosts from moving.
6.  **Avoid Ghosts:** If a `G` ghost touches your hero, the game ends!
7.  **Find the Portal:** Stepping on a `0` portal also ends the game.
8.  **Survive:** The game ends if time runs out, a ghost catches you, or you step into a portal. Aim for the highest score!

## Game Elements Legend

*   `@` - **Hero:** Your player character.
*   `G` - **Ghost:** The enemy. Avoid contact!
*   `#` / `-` - **Wall:** Impassable obstacles.
*   `.` - **Collectible Point:** Collect these to increase your score.
*   `+` - **Power-Up:** Grants a temporary invincibility (ghosts freeze) period.
*   `0` - **Portal:** An exit point; entering it ends the game.

## Installation and Setup

To compile and run MazeCrazeMaze, you will need a C++ compiler (like g++ or MinGW).

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/ahmadaliansarii/MazeCrazeMaze.git
    ```
2.  **Navigate to the Project Directory:**
    ```bash
    cd MazeCrazeMaze
    ```
3.  **Compile the Source Code:**
    ```bash
    g++ project.cpp -o maze_game
    ```
    *(Note: On some systems, especially Windows, you might need to link `conio.h` specific libraries, but `g++` usually handles it automatically. Ensure your environment is set up for console development.)*
4.  **Run the Executable:**
    ```bash
    ./maze_game.exe  # On Windows
    ./maze_game      # On Linux/macOS (if compiled using g++ on those platforms)
    ```

## Controls

*   `W` - Move Up
*   `A` - Move Left
*   `S` - Move Down
*   `D` - Move Right
*   Any key press will be registered for hero movement.

## Compatibility

This game is primarily designed for **Windows console environments** due to the use of `conio.h` for non-buffered keyboard input (`_kbhit`, `_getch`) and `system("cls")` for clearing the screen. While it might compile on other platforms with compatible libraries or modifications, its full functionality is guaranteed on Windows.

## Credits

This game was created by:

*   **Jaswant Lal** (22K-4473)
*   **Ahmad Ali Ansari** (22K-4385)
