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
#include <stdbool.h>
#include "player.h"

// The function will destroy BST and free all memory.
void boom(struct TreeNode *tree) {
    printTree(tree);
    destroyTree(tree);
}

// The function will check who is winner by scores.
void checkWinner(struct TreeNode *tree, char *nameOne, char *nameTwo, int scoreOne, int scoreTwo) {
    struct Player *playerOne = (struct Player *) malloc(sizeof(struct Player));
    if (playerOne == NULL) {
        fprintf(stderr, "Out of memory!");
        return;
    }
    struct Player *playerTwo = (struct Player *) malloc(sizeof(struct Player));
    if (playerTwo == NULL) {
        fprintf(stderr, "Out of memory!");
        return;
    }
    playerOne->name = strdup(nameOne);
    if (playerOne->name == NULL) {
        free(playerOne);
        fprintf(stderr, "Out of memory!");
        return;
    }
    playerTwo->name = strdup(nameTwo);
    if (playerTwo->name == NULL) {
        free(playerTwo);
        fprintf(stderr, "Out of memory!");
        return;
    }

    // Check player1 and player2 scores.
    if (scoreOne > scoreTwo) {
        // If player1's score bigger than player2's score, then player1 win, player2 lose.

        // Player1 win
        playerOne->wins = 1;
        playerOne->losses = 0;
        // Player2 lose
        playerTwo->wins = 0;
        playerTwo->losses = 1;
    } else {
        // If player2's score bigger than player1's score, then player2 win, player1 lose.

        // Player1 lose
        playerOne->wins = 0;
        playerOne->losses = 1;
        // Player2 win
        playerTwo->wins = 1;
        playerTwo->losses = 0;
    }

    // Check player1 name for BST
    if (findPlayer(tree, nameOne) == 1) {
        updatePlayer(tree, playerOne);
    } else {
        insertPlayer(tree, playerOne);
    }

    // Check player2 name for BST
    if (findPlayer(tree, nameTwo) == 1) {
        updatePlayer(tree, playerTwo);
    } else {
        insertPlayer(tree, playerTwo);
    }

    // Free playerOne and playerTwo
    free(playerOne->name);
    free(playerOne);
    free(playerTwo->name);
    free(playerTwo);

}

// The function will read user's inputting, then put data for BST.
int input(struct TreeNode *tree) {
    char nameOne[20];
    int scoreOne;
    int check;

    bool flag = false;

    while ((check = scanf("%s %d", nameOne, &scoreOne)) != EOF) {

        flag = true;
        // If user doesn't input score, then it would print error.
        if (check != 2) {
            fprintf(stderr, "Invalid scores entered\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }

        int checkTwo;
        char nameTwo[20];
        int scoreTwo;

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

        checkWinner(tree, nameOne, nameTwo, scoreOne, scoreTwo);

    }

    // If user stop the program when the user didn't input anything, the program just destroy the BST.
    if (flag == false && check == -1) {
        destroyTree(tree);
        return EXIT_SUCCESS;
    }

    boom(tree);

    return EXIT_SUCCESS;
}

// The main function would create a empty BST.
int main() {

    // Create a new BST.
    struct TreeNode *tree = createTree();
    // If out of memory, then it print error information.
    if (tree == NULL) {
        return EXIT_FAILURE;
    }

    // Call input function to read user's inputting.
    return input(tree);

}
