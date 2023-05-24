#include <stdio.h>
#include <conio.h>

#define ROWS 10
#define COLS 10

// Function to display the maze
void displayMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player in the maze
void movePlayer(char maze[ROWS][COLS], int* playerRow, int* playerCol, int newRow, int newCol) {
    // Check if the new position is within the maze boundaries and not a wall '#'
    if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] != '#') {
        // Update the maze
        maze[*playerRow][*playerCol] = ' ';
        maze[newRow][newCol] = 'P';

        // Update the player's position
        *playerRow = newRow;
        *playerCol = newCol;

        // Clear the console and display the updated maze
        system("cls");
        displayMaze(maze);
    }
}

int main() {
    // Define the maze
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // Initialize player's position
    int playerRow = 1;
    int playerCol = 1;
    maze[playerRow][playerCol] = 'P';

    // Display the initial maze
    displayMaze(maze);

    // Game loop
    int ch;
    do {
        // Get user input
        ch = getch();
        switch (ch) {
            case 'w': // Up
                movePlayer(maze, &playerRow, &playerCol, playerRow - 1, playerCol);
		break;
            case 's': // Down
                movePlayer(maze, &playerRow, &playerCol, playerRow + 1, playerCol);
		break;
            case 'a': // Left
                movePlayer(maze, &playerRow, &playerCol, playerRow, playerCol - 1);
                break;
            case 'd': // Right
               movePlayer(maze, &playerRow, &playerCol, playerRow, playerCol + 1);
                break;
        }
    } while (maze[playerRow][playerCol] != 'D');

    printf("\nCongratulations! You reached the destination!\n");

    return 0;
}

