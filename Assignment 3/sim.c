/*
 * CSc 352 Summer 2016, Assignment 3
 *
 * Author: Yujia Lin
 *
 * Instructor: Lee Savoie
 *
 * ---
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * The function will set up map.
 * The simulated area is divided into a 20 x 20 grid,
 * with the upper-left square having the coordinates (1,1),
 * the x coordinates increasing when moving right,
 * and the y coordinates increasing when moving down.
 */
void setMap(char map[20][20]) {
    int i, j;
    for (i = 0; i < 20; ++i) {
        for (j = 0; j < 20; ++j) {
            map[i][j] = 'o';
        }
    }
}

/*
 * The function will control the ship go to right, left, up and down.
 * The user will enter the movements of the ship by entering single characters indicating the direction that the ship moves:
 * 'N' for North,
 * 'S' for South,
 * 'E' for East, and 'W' for West.
 * These inputs are case insensitive, so 'N' and 'n' both mean North, etc.
 * There will be whitespace between each character.
 * Since the origin is at the top left, moving North corresponds to moving in the negative y direction,
 * moving East means moving in the positive x direction, and the opposites for South and West, respectively.
 * For each input, the program should simulate the ship moving one grid square in the specified direction, subject to the following rules:
 *
 * - If the movement would cause the ship to move out of the simulated area, the ship does not move.
 * - The first 3 times the ship moves to a square with an obstacle, the obstacle disappears.
 *   However, the 4th time the ship moves to a square with an obstacle, the ship sinks.
 *   the program should print out ""SUNK! at x, y", followed by a new line, with x and y replaced with the coordinates at which the ship sank.
 *   If the ship sinks, any remaining input should be ignored. the program should only print out the "SUNK!" message once, regardless of how many inputs remain after the ship has sunk.
 * - If there is no more input and the ship has not sunk, the program should print out "Survived! Ending location: x, y", with x and y replaced by the final location of the ship, followed by a new line.
 *
 */
void goAnyWhere(char map[20][20], int shipX, int shipY) {

    int score = 0;

    char go;

    while (scanf("\n%c", &go) != EOF) {
        if (score < 4) {
            if (go == 'w' || go == 'W') {
                shipX = shipX - 1;
                if (shipX < 0) {
                    shipX = 0;
                }
                if (map[shipX][shipY] == 'x') {
                    map[shipX][shipY] = 'o';
                    score++;
                }
            } else if (go == 'n' || go == 'N') {
                shipY = shipY - 1;
                if (shipY < 0) {
                    shipY = 0;
                }
                if (map[shipX][shipY] == 'x') {
                    map[shipX][shipY] = 'o';
                    score++;
                }
            } else if (go == 'e' || go == 'E') {
                shipX = shipX + 1;
                if (shipX > 19) {
                    shipX = 19;
                }
                if (map[shipX][shipY] == 'x') {
                    map[shipX][shipY] = 'o';
                    score++;
                }
            } else if (go == 's' || go == 'S') {
                shipY = shipY + 1;
                if (shipY > 19) {
                    shipY = 19;
                }
                if (map[shipX][shipY] == 'x') {
                    map[shipX][shipY] = 'o';
                    score++;
                }
            } else {
                fprintf(stderr, "Invalid direction\n");
            }

            // If get score equals 4, then BOOM!
            if (score == 4) {
                printf("SUNK! at %d, %d\n", shipX + 1, shipY + 1);
            }
        }

    }

    // If get score less than 4, then you win.
    if (score < 4) {
        printf("Survived! Ending location: %d, %d\n", shipX + 1, shipY + 1);
    }


}

/*
 * The main function will read user's inputs.
 * The user will first enter the coordinates of the obstacles one at a time,
 * by providing the x and y coordinates for each obstacle,
 * in that order. When the user is done entering the coordinates of obstacles, they will enter "-1".
 * After this, the user will enter the starting location for the ship by providing an x and y coordinate in the same format.
 */
int main() {

    char map[20][20];
    int shipX, shipY;
    int x, y;

    int checkX, checkY, checkShip;

    setMap(map);

    while ((checkX = scanf("%i", &x)) != EOF) {
        if (checkX != 1 || (x < -2 || x == 0 || x > 20)) {
            fprintf(stderr, "Invalid obstacle position\n");
            return EXIT_FAILURE;
        }
        if (x == -1) {
            break;
        }
        if ((checkY = scanf("%i", &y)) == EOF) {
            fprintf(stderr, "Ran out of input before obstacle completion\n");
            return EXIT_FAILURE;
        }
        if (checkY != 1 || (y < 1 || y > 20)) {
            fprintf(stderr, "Invalid obstacle position\n");
            return EXIT_FAILURE;
        }
        map[x - 1][y - 1] = 'x';
    }
    if (x != -1) {
        fprintf(stderr, "Ran out of input before obstacle completion\n");
        return EXIT_FAILURE;
    }

    if ((checkShip = scanf("%d %d", &shipX, &shipY)) == EOF) {
        fprintf(stderr, "Couldn't read starting location\n");
        return EXIT_FAILURE;
    }

    if (checkShip != 2 || shipX < 1 || shipX > 20 || shipY < 1 || shipY > 20) {
        fprintf(stderr, "Invalid starting position\n");
        return EXIT_FAILURE;
    }

    shipX = shipX - 1;
    shipY = shipY - 1;

    // Call goAnyWhere function
    goAnyWhere(map, shipX, shipY);


    return EXIT_SUCCESS;
}