#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

// When out of memory the function will print error.
void outOfMemory() {
    fprintf(stderr, "Out of memory!");
}

/*
 * This function creates an empty HashTable. It takes no parameters and returns
 * a pointer to a newly allocated struct HashTable.
 */
struct HashTable *createHashTable() {
    struct HashTable *table = (struct HashTable *) malloc(sizeof(struct HashTable));
    if (table == NULL) {
        outOfMemory();
        return NULL;
    }
    table->size = 1000;
    int i;
    for (i = 0; i < table->size; ++i) {
        table->list[i] = (struct LinkedList *) malloc(sizeof(struct LinkedList));
        if (table->list[i] == NULL) {
            outOfMemory();
            int j;
            for (j = 0; j < i; ++j) {
                free(table->list[j]);
            }
            return NULL;
        }
        table->list[i]->next = NULL;
        table->list[i]->data.word = NULL;
    }

    return table;
}


/*
 * This function adds the provided element to the HashTable.
 *
 * Parameters:
 * table - the HashTable to add the element to
 * word - the element to add to the HashTable
 *
 * Returns: 1 if insert successful, and 0 if it was not.
 */
int insert(struct HashTable *table, char *word) {
    struct LinkedList *node = (struct LinkedList *) malloc(sizeof(struct LinkedList));

    if (node == NULL) {
        outOfMemory();
        return 0;
    }
    node->data.word = strdup(word);
    node->data.count = 1;

    node->next = table->list[hash(word, table->size)];
    table->list[hash(word, table->size)] = node;
    return 1;
}

/*
 * Updates an element in the HashTable in place.  Nothing is added or removed from the HashTable.
 * This function searches through the HashTable to find the element such that data.word
 * equals word. If it finds such an element, that element is set to the value of count.
 *
 * Parameters:
 * table - the HashTable to update
 * word - the word to search for.
 *
 * Returns: 1 if the HashTable was updated, 0 if the HashTable was not updated.
 */
int update(struct HashTable *table, char *word) {
    struct LinkedList *p = table->list[hash(word, table->size)];
    while (p->data.word != NULL) {
        if (strcmp(p->data.word, word) == 0) {
            p->data.count = p->data.count + 1;
            return 1;
        }
        p = p->next;
    }
    return 0;
}


/*
 * This function finds an element in the HashTable. It searches for the element
 * whose data.word value matches the word value passed to the function.
 *
 * Parameters:
 * table - the HashTable to search in
 * word - the word to search for.
 *
 * Returns: 1 if the element was found in the HashTable, and 0 if it was not.
 */
int find(struct HashTable *table, char *word) {
    struct LinkedList *p = table->list[hash(word, table->size)];
    while (p->data.word != NULL) {
        if (strcmp(p->data.word, word) == 0) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

/*
 * Prints out the data stored in the HashTable.
 * The function would print on : wordfrequency.txt
 *
 * a, 1
 * b, 2
 *
 * Parameters:
 * table - the HashTable to print
 */
void print(struct HashTable *table) {
    FILE *fp = fopen("wordfrequency.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "error");
    }

    int i;
    for (i = 0; i < table->size; ++i) {
        if (table->list[i]->data.word == NULL) {
            continue;
        }
        struct LinkedList *p = table->list[i];
        while (p->data.word != NULL) {
            char *word = p->data.word;
            int count = p->data.count;
            fprintf(fp, "%s, %d\n", word, count);
            //printf("%s, %d\n", word, count);
            p = p->next;
        }
    }

    if (fclose(fp) == EOF) {
        fprintf(stderr, "error");
    }
}

/*
 * Destroys a HashTable.  Every node in the HashTable will be deallocated, along with the HashTable itself.
 *
 * Parameters:
 * table - the HashTable to destroy
 */
void destroy(struct HashTable *table) {
    int i;
    for (i = 0; i < table->size; ++i) {
        struct LinkedList *p;
        while (table->list[i] != NULL) {
            p = table->list[i];
            table->list[i] = table->list[i]->next;
            free(p->data.word);
            free(p);
        }
    }
    free(table);
}

/*
 * This algorithm (k=33) was first reported by dan bernstein many years ago in comp.lang.c.
 * another version of this algorithm (now favored by bernstein) uses xor: hash(i) = hash(i - 1) * 33 ^ str[i];
 * the magic of number 33 (why it works better than many other constants, prime or not) has never been adequately explained.
 * (the djb2 algorithm from http://www.cse.yorku.ca/~oz/hash.html)
 */
int hash(char *data, int size) {
    unsigned long hash = 5381;
    char *p;
    for (p = data; *p != '\0'; ++p) {
        hash = (hash * 33) + *p;
    }
    return (int) (hash % size);
}