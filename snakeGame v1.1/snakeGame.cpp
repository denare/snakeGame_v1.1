/*
  Description: The classic snake game!!
  Coded by : Denis D
  Date : Mindnight 20-21 th December 2024
*/
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Function prototypes
void run();
void displayMap();
void initializeMap();
void moveSnake(int deltaX, int deltaY);
void updateMap();
void changeDirection(char keyPress);
void clearConsole();
void newFood();
void displayAuthor();
int selectLevel();
char getTileValue(int tileValue);

// Map dimensions
const int mapWidth = 20;
const int mapHeight = 30;
const int totalTiles = mapWidth * mapHeight;

// The tile values for the map
int gameMap[totalTiles];

// Snake head details
int snakeHeadX;
int snakeHeadY;
int snakeDirection;

// Amount of food the snake has (How long the body is)
int snakeLength = 2;

// Determine if game is running
bool isGameRunning;
string playerName;

int main() {
    cout << "Enter your name: ";
    cin >> playerName;
    cout << endl;
    run();
    return 0;
}

// Main game function
void run() {
    string chosenLevel;
    int gameLevel;
    //Selects the game Level
	gameLevel = selectLevel();
	
	
    // Initialize the map
    initializeMap();
    isGameRunning = true;
    while (isGameRunning) {
        // If a key is pressed
        if (kbhit()) {
            // Change to direction determined by key pressed
            changeDirection(getch());
        }
        // Update the map
        updateMap();
        // Clear the screen
        clearConsole();
        // Print the map
        displayMap();
        // Delay for the level of difficulty
        Sleep(gameLevel);
    } 

    // Determine the level chosen by user
    if (gameLevel == 400)
        chosenLevel = "Easy";
    else if (gameLevel == 200)
        chosenLevel = "Medium";
    else
        chosenLevel = "Hard";

    // Game Over Text
    cout << "------------------------------\n";
    cout << "\n\tGAME OVER!!!" << endl 
         << "\t" << playerName << "'s score is: " << snakeLength
         << "\n\tLevel played: " << chosenLevel;
    cout << "\n\n------------------------------\n";
    
	char ch;
	  cout << "RESTART SNAKE GAME? [Y/N]:  ";
      cin>>ch;

	if (ch == 'Y' || ch == 'y'){
      system("cls");
     snakeLength = 3;
    for(int as = 0; as < totalTiles; as++){
      gameMap[as] = 0;
      }
      run();
    }
    else{
    	displayAuthor(); 
    	system("pause");
	}
	

    cin.ignore();
}

// Function to set the game difficulty level
int selectLevel() {
    int difficulty, userChoice;
    cout << "SET LEVEL\n1: Easy\n2: Medium\n3: Hard\nNOTE: Hard is default level\nChoose the level: ";
    cin >> userChoice;
    switch (userChoice) {
    case 1: difficulty = 400; break;
    case 2: difficulty = 200; break;
    //case 3: difficulty = 50; break;
    default: difficulty = 50;
    }
    return difficulty;
}


// Returns graphical character for display from map value
char getTileValue(int tileValue) {   
    if (tileValue > 0) {
        return 'o';
    }
    switch (tileValue) {
        // Return wall
        case -1: return 'X';
        // Return food
        case -2: return 'O';
        // Default case to handle unspecified values
        default: return ' ';
    }
}

// Changes snake direction from input
void changeDirection(char keyPress) {
    switch (keyPress) {
    case 'w':
        if (snakeDirection != 2) snakeDirection = 0;
        break;
    case 'd':
        if (snakeDirection != 3) snakeDirection = 1;
        break;
    case 's':
        if (snakeDirection != 4) snakeDirection = 2;
        break;
    case 'a':
        if (snakeDirection != 5) snakeDirection = 3;
        break;
    }
}

// Moves snake head to new location
void moveSnake(int deltaX, int deltaY) {
    int newSnakeX = snakeHeadX + deltaX;
    int newSnakeY = snakeHeadY + deltaY;

    // Check if there is food at location
    if (gameMap[newSnakeX + newSnakeY * mapWidth] == -2) {
        // Increase food value (body length)
        snakeLength++;
        // Generate new food on map
        newFood();
    }
    // Check if location is free
    else if (gameMap[newSnakeX + newSnakeY * mapWidth] != 0) {
        isGameRunning = false;
    }

    // Move head to new location
    snakeHeadX = newSnakeX;
    snakeHeadY = newSnakeY;
    gameMap[snakeHeadX + snakeHeadY * mapWidth] = snakeLength + 1;
}


// Clears the console screen
void clearConsole() {
    system("cls");
}

// Generates new food on map
void newFood() {
    int x, y;
    do {
        // Generate random x and y values within the map
        x = rand() % (mapWidth - 2) + 1;
        y = rand() % (mapHeight - 2) + 1;
    } while (gameMap[x + y * mapWidth] != 0);

    // Place new food
    gameMap[x + y * mapWidth] = -2;
}

// Updates the map
void updateMap() {
    // Move in direction indicated
    switch (snakeDirection) {
    case 0: moveSnake(-1, 0); break;
    case 1: moveSnake(0, 1); break;
    case 2: moveSnake(1, 0); break;
    case 3: moveSnake(0, -1); break;
    }
    // Reduce snake values on map by 1
    for (int i = 0; i < totalTiles; i++) {
        if (gameMap[i] > 0) gameMap[i]--;
    }
}

// Initializes the map
void initializeMap() {
    // Places the initial head location in middle of map
    snakeHeadX = mapWidth / 2;
    snakeHeadY = mapHeight / 2;
    gameMap[snakeHeadX + snakeHeadY * mapWidth] = 1;

    // Places top and bottom walls 
    for (int x = 0; x < mapWidth; ++x) {
        gameMap[x] = -1;
        gameMap[x + (mapHeight - 1) * mapWidth] = -1;
    }
    // Places left and right walls
    for (int y = 0; y < mapHeight; y++) {
        gameMap[0 + y * mapWidth] = -1;
        gameMap[(mapWidth - 1) + y * mapWidth] = -1;
    }
    // Generates first food
    newFood();
}


// Sets the color for console text 
void setColor(int color) { 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}

// Prints the map to console
void displayMap() {
    setColor(7); // Default color
    cout << "Here is the Manual: \n 'W' for UP,  'S' for DOWN";
    cout << " \n 'A' for LEFT,'D' for RIGHT"<<endl;
    cout << "-------------------------------\n";
    cout << "Score: " << snakeLength << endl;
    
    for (int x = 0; x < mapWidth; ++x) {
        for (int y = 0; y < mapHeight; ++y) {
            char tile = getTileValue(gameMap[x + y * mapWidth]);
            if (tile == 'X') {
                setColor(2); // Red color for walls
            } else if (tile == 'O') {
                setColor(10); // Green color for food
            } else if (tile == 'o') {
                setColor(14); // Yellow color for snake
            } else {
                setColor(2); // Default color
            }
            cout << tile;
        }
        cout << endl;
    }
}


void displayAuthor(){
	cout << "Thank you for Playing\nCoded by : "<<endl;
	system("color 0a");
	sleep(1);
	cout << "  ____                  _____    ____    " << endl;
    sleep(1);
	cout << " |  _ \\ ___ __  _  (_) /  ___|  |  _ \\ " << endl;
    sleep(1);
	cout << " | | | / _ \\| \\| | | | |____    | | | |" << endl;
    sleep(1);
	cout << " | |_| |  _/|  ` | | | _\___ \\   | |_| |" << endl;
    sleep(1);
	cout << " |____/ \\___|_|\\_| |_|/_____/   |____/ " << endl;
    cout << "                                   " << endl;
}

