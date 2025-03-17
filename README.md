
# Snake Game v1.1 🐍 By Denis D

[Snake Game Screenshot]

![image](https://github.com/user-attachments/assets/64da6364-001f-46c8-b147-beab3fc1b189)


**A classic Snake Game implementation in C++!**  
Coded by Denis D on December 20-21, 2024, this project brings the nostalgic Snake Game to life with a console-based interface, customizable difficulty levels, and a colorful display.

---

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Game Levels](#game-levels)
- [Contributing](#contributing)
- [Credits](#credits)
- [License](#license)

---

## Description
This is a console-based implementation of the classic Snake Game, where you control a snake to eat food, grow in length, and avoid hitting walls or yourself. The game features adjustable difficulty levels (Easy, Medium, Hard), a scoring system based on the snake's length, and a colorful display using console text attributes. It’s a fun, lightweight project perfect for beginners learning C++ or anyone looking to relive a retro gaming experience.

---

## Features
- **Customizable Difficulty Levels**: Choose between Easy, Medium, and Hard modes to adjust the game speed.
- **Colorful Display**: Walls, food, and the snake are displayed in different colors for a better visual experience.
- **Score Tracking**: Your score is based on the snake's length, displayed during gameplay and at the end.
- **Restart Option**: Restart the game after a game over without exiting.
- **Player Name Input**: Personalize your experience by entering your name at the start.
- **ASCII Art Credits**: A stylish author display at the end of the game.

---

## Installation

### Prerequisites
- A C++ compiler (e.g., g++ on Linux/Mac or MinGW on Windows).
- Windows OS (since the code uses `windows.h` and `conio.h` for console manipulation and keyboard input).
- Git (optional, for cloning the repository).

### Steps
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/denare/snakeGame_v1.1.git
   cd snakeGame_v1.1
   ```

2. **Compile the Code**:
   Use a C++ compiler to compile the `snakeGame.cpp` file. For example, with g++:
   ```bash
   g++ snakeGame.cpp -o snakeGame
   ```

3. **Run the Game**:
   Execute the compiled program:
   ```bash
   snakeGame.exe  # On Windows
   ```

### Notes
- This game is designed for Windows due to the use of `windows.h` and `conio.h`. To run on other operating systems (Linux/Mac), you’ll need to modify the code to use cross-platform libraries like `ncurses` for console manipulation and keyboard input.

---

## Usage
1. Launch the game by running the compiled executable (`snakeGame.exe`).
2. Enter your name when prompted.
3. Select a difficulty level (1 for Easy, 2 for Medium, 3 for Hard). The default is Hard if an invalid option is chosen.
4. Use the WASD keys to control the snake:
   - **W**: Move up
   - **A**: Move left
   - **S**: Move down
   - **D**: Move right
5. Eat the food (`O`) to grow your snake and increase your score.
6. Avoid hitting the walls (`X`) or the snake’s own body (`o`).
7. When the game ends, view your score and choose to restart (`Y`) or exit (`N`).

---

## Controls
- **W**: Move Up
- **A**: Move Left
- **S**: Move Down
- **D**: Move Right

The game prevents the snake from reversing directly into itself (e.g., you can’t move down if you’re moving up).

---

## Game Levels
The game offers three difficulty levels, which determine the speed of the snake:
- **Easy**: 400ms delay per move (slower).
- **Medium**: 200ms delay per move (moderate).
- **Hard**: 50ms delay per move (faster, default).

Choose a level at the start of the game by entering 1, 2, or 3.

---

## Contributing
Contributions are welcome! If you’d like to improve the game, here’s how you can contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature/your-feature`).
3. Make your changes and commit them (`git commit -m "Add your feature"`).
4. Push to your branch (`git push origin feature/your-feature`).
5. Open a pull request.

Ideas for improvements:
- Add cross-platform support (e.g., using `ncurses` for Linux/Mac).
- Implement a high score system.
- Add sound effects or background music.
- Enhance the UI with more graphical elements.

---

## Credits
- **Author**: Denis D
- **Date**: December 20-21, 2024
- **GitHub**: [denare](https://github.com/denare)

Special thanks to the C++ community for inspiration and resources!

---

## License
This project is not licensed, and it is open source

****** THANK YOU ********
