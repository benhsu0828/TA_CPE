#include <stdio.h>
#include <string.h>

#define MAX_GRID_SIZE 50
#define MAX_COMMANDS 100

// Directions represented as integers for easier manipulation
enum Direction { NORTH, EAST, SOUTH, WEST };

// Movement offsets for each direction
const int moveX[] = {0, 1, 0, -1};
const int moveY[] = {1, 0, -1, 0};

// Function to convert character direction to enum Direction
int charToDirection(char c) {
    switch (c) {
        case 'N': return NORTH;
        case 'E': return EAST;
        case 'S': return SOUTH;
        case 'W': return WEST;
        default: return -1;
    }
}

// Function to convert enum Direction to character
char directionToChar(int d) {
    switch (d) {
        case NORTH: return 'N';
        case EAST: return 'E';
        case SOUTH: return 'S';
        case WEST: return 'W';
        default: return '?';
    }
}

int main() {
    int gridX, gridY;
    scanf("%d %d", &gridX, &gridY);

    // Array to keep track of scents
    int scent[MAX_GRID_SIZE + 1][MAX_GRID_SIZE + 1] = {0};

    int x, y;
    char dirChar;
    char commands[MAX_COMMANDS + 1];

    while (scanf("%d %d %c", &x, &y, &dirChar) == 3) {
        scanf("%s", commands);
        int dir = charToDirection(dirChar);
        int lost = 0;

        for (int i = 0; commands[i] != '\0'; i++) {
            if (commands[i] == 'L') {
                dir = (dir + 3) % 4; // Turn left
            } else if (commands[i] == 'R') {
                dir = (dir + 1) % 4; // Turn right
            } else if (commands[i] == 'F') {
                int newX = x + moveX[dir];
                int newY = y + moveY[dir];

                if (newX < 0 || newX > gridX || newY < 0 || newY > gridY) {
                    if (!scent[x][y]) {
                        lost = 1;
                        scent[x][y] = 1;
                        break;
                    }
                } else {
                    x = newX;
                    y = newY;
                }
            }
        }

        printf("%d %d %c", x, y, directionToChar(dir));
        if (lost) {
            printf(" LOST");
        }
        printf("\n");
    }

    return 0;
}
