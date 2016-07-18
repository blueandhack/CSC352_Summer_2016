/*
 * CSc 352 Summer 2016, Assignment 05
 *
 * Author: Yujia Lin
 *
 * Instructor: Lee Savoie
 *
 * ---
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

// The function will read user's inputting, then put data for BST.
int input(struct Node *tree) {
    char nameOne[20];
    int scoreOne;
    int check;
    char nameTwo[20];
    int scoreTwo;

    int count = 0;

    while ((check = scanf("%s %d", nameOne, &scoreOne)) != EOF) {

        count++;

        // If user doesn't input score, then it would print error.
        if (check != 2) {
            fprintf(stderr, "Invalid scores entered\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }

        int checkTwo;

        // Wait user input player2's information.
        checkTwo = scanf("\n%s %d", nameTwo, &scoreTwo);

        // If user doesn't input score, then it would print error.
        if (checkTwo != 2) {
            fprintf(stderr, "Invalid scores entered\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }

        // If player1 and player2 have same scores, then it is not allowed.
        if (scoreOne == scoreTwo) {
            fprintf(stderr, "Ties are not allowed\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }

        // If player1 and player2 have same name, then it is not allowed.
        if (strcmp(nameOne, nameTwo) == 0) {
            fprintf(stderr, "Players cannot play against themselves\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }


        // Check player1 and player2 scores.
        if (scoreOne > scoreTwo) {
            // If player1's score bigger than player2's score, then player1 win, player2 lose.
            if (findPlayer(tree, nameOne) == 1) {
                updatePlayer(tree, nameOne, 1, 0);
            } else {
                insertPlayer(tree, nameOne, 1, 0);
            }
            if (findPlayer(tree, nameTwo) == 1) {
                updatePlayer(tree, nameTwo, 0, 1);
            } else {
                insertPlayer(tree, nameTwo, 0, 1);
            }
        } else {
            // If player2's score bigger than player1's score, then player2 win, player1 lose.
            if (findPlayer(tree, nameOne) == 1) {
                updatePlayer(tree, nameOne, 0, 1);
            } else {
                insertPlayer(tree, nameOne, 0, 1);
            }
            if (findPlayer(tree, nameTwo) == 1) {
                updatePlayer(tree, nameTwo, 1, 0);
            } else {
                insertPlayer(tree, nameTwo, 1, 0);
            }
        }

    }

    // If user stop the program when the user didn't input anything, the program just destroy the BST.
    if (count == 0 && check == -1) {
        destroyTree(tree);
        return EXIT_SUCCESS;
    }

    printTree(tree);
    destroyTree(tree);

    return EXIT_SUCCESS;
}

// The main function would create a empty BST.
int main() {

    // Create a new BST.
    struct Node *tree = createTree();
    // If out of memory, then it print error information.
    if (tree == NULL) {
        fprintf(stderr, "Out of memory!");
        return EXIT_FAILURE;
    }

    // Call input function to read user's inputting.
    return input(tree);

}
