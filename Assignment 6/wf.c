#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hashtable.h"

// The function will print the HashTable and destroy the HashTable.
void boom(struct HashTable *table) {
    // Call print function to print the HashTable
    print(table);

    // Call destroy function to destroy the HashTable
    destroy(table);
}

/*
 * The main function will read every file and scan every word in those files.
 * Then find the word in the HashTable, if not find the word, insert the word in the HashTable.
 * If find the word, update the word in the HashTable.
 */
int main(int argc, char *argv[]) {

    // Check arguments from command line.
    if (argc < 2) {
        fprintf(stderr, "Must provide a list of file names as command line arguments\n");
        return EXIT_FAILURE;
    }

    int j;

    // Call createHashTable function to create a empty HashTable.
    struct HashTable *table = createHashTable();

    if (table == NULL) {
        return EXIT_FAILURE;
    }

    // Get every filename
    for (j = 1; j < argc; ++j) {
        FILE *fp = fopen(argv[j], "r");
        if (fp == NULL) {
            fprintf(stderr, "No such file or directory\n");
            return EXIT_FAILURE;
        }
        char word[1025];
        int i, k;

        // Read file and put every word to HashTable
        while (fscanf(fp, "%s", word) > 0) {

            char *newWord = NULL;

            // Check the word that it does not have any character except "a" to "z" and "0" to "9".
            for (i = 0, k = 0; word[i] != '\0'; i++) {
                if ((word[i] <= 'z' && word[i] >= 'a') || (word[i] <= 'Z' && word[i] >= 'A') ||
                    (word[i] >= '0' && word[i] <= '9')) {
                    if (word[i] <= 'Z' && word[i] >= 'A') {
                        word[k++] = (char) tolower(word[i]);
                    } else {
                        word[k++] = word[i];
                    }
                }
            }
            word[k] = '\0';

            // If the word is empty, then skip the word.
            if (word[0] == '\0') {
                continue;
            }

            // Store the word to newWord
            newWord = strdup(word);

            // If out of memory then print error.
            if (newWord == NULL) {
                destroy(table);
                fprintf(stderr, "Out of memory!");
                return EXIT_FAILURE;
            }

            // find the word in the HashTable, if find then update, if not find then insert.
            if (find(table, word) != 1) {
                insert(table, newWord);
            } else {
                update(table, newWord);
            }

            free(newWord);
        }

        // Close file pointer.
        if (fclose(fp) == EOF) {
            fprintf(stderr, "error");
        }
    }

    // Call boom function to print and destroy the HashTable.
    boom(table);

    return EXIT_SUCCESS;
}
