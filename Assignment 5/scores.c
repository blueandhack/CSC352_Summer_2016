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

int main() {

    struct Node *tree = createTree();
    if (tree == NULL) {
        fprintf(stderr, "Out of memory!");
        return EXIT_FAILURE;
    }

    char nameOne[20];
    int scoreOne;
    int check;
    while ((check = scanf("%s %d", nameOne, &scoreOne)) != EOF) {
        if (check != 2) {
            fprintf(stderr, "Invalid scores entered\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }
        char nameTwo[20];
        int scoreTwo;
        int checkTwo;
        checkTwo = scanf("%s %d", nameTwo, &scoreTwo);
//        printf("%s %d %s %d\n", nameOne, scoreOne, nameTwo, scoreTwo);
        if (checkTwo != 2) {
            fprintf(stderr, "Invalid scores entered\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }
        if (scoreOne == scoreTwo) {
            fprintf(stderr, "Ties are not allowed\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }
        if (strcmp(nameOne, nameTwo) == 0) {
            fprintf(stderr, "Players cannot play against themselves\n");
            destroyTree(tree);
            return EXIT_FAILURE;
        }
        if (scoreOne > scoreTwo) {
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
    if (check != 2) {
        fprintf(stderr, "Invalid scores entered\n");
        destroyTree(tree);
        return EXIT_FAILURE;
    }

    printTree(tree);

    destroyTree(tree);

    return EXIT_SUCCESS;
}
