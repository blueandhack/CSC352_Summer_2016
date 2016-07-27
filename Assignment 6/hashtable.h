
#ifndef HASHTABLE_H
#define HASHTABLE_H

/*
 * This struct holds the linked list data stored in each node. Every node stores
 * one word and one integer. Then every linked list store to HashTable.
 */
struct LinkedList_data {
    char *word;
    int count;
};

struct LinkedList {
    struct LinkedList_data data;
    struct LinkedList *next;
};

struct HashTable {
    int size;
    struct LinkedList *list[1000];
};

/*
 * This function creates an empty HashTable. It takes no parameters and returns
 * a pointer to a newly allocated struct HashTable.
 */
struct HashTable *createHashTable();

/*
 * This function adds the provided element to the HashTable.
 *
 * Parameters:
 * table - the HashTable to add the element to
 * word - the element to add to the HashTable
 *
 * Returns: 1 if insert successful, and 0 if it was not.
 */
int insert(struct HashTable *table, char *word);

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
int update(struct HashTable *table, char *word);

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
int find(struct HashTable *table, char *word);

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
void print(struct HashTable *table);

/*
 * Destroys a HashTable.  Every node in the HashTable will be deallocated, along with the HashTable itself.
 *
 * Parameters:
 * table - the HashTable to destroy
 */
void destroy(struct HashTable *table);

int hash(char *data, int size);

#endif //HASHTABLE_H
