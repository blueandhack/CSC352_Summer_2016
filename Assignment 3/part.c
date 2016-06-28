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

#define LENGTH (100)

/*
 * The function will partition a string into two parts at all instances of a given character.
 */
void printParts(char str[], char key) {
    int i, j;
    int lastIndex = 0;
    for (i = 0; i < LENGTH; ++i) {
        if (str[i] == '\0') {
            break;
        } else if (str[i] == key) {
            lastIndex = i;
            printf("[");
            for (j = 0; j < LENGTH; ++j) {
                if (str[j] == '\0') {
                    break;
                } else if (j == lastIndex) {
                    printf("],[%c", str[j]);
                } else {
                    printf("%c", str[j]);
                }
            }
            printf("]\n");
        }
    }
}

/*
 * The main function is start with the program, and the function will scan user's inputs.
 * User should input a string and a character.
 * It will receive data and put to printParts function.
 */
int main() {

    char str[LENGTH];
    char key;

    if (scanf("%[^\n]", str) == EOF) {
        fprintf(stderr, "Could not read input string\n");
        return EXIT_FAILURE;
    }
    if (scanf("\n%c", &key) == EOF) {
        fprintf(stderr, "Could not read partition character\n");
        return EXIT_FAILURE;
    }

    // Call printParts function, then it will print out that partition a string into two parts at all instances of a given character.
    printParts(str, key);

    return EXIT_SUCCESS;
}
