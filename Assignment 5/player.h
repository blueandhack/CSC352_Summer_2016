/*
 * CSc 352 Summer 2016, Assignment 05
 *
 * Author: Yujia Lin
 *
 * Instructor: Lee Savoie
 *
 * ---
 */
#ifndef PLAYER_H
#define PLAYER_H

/*
 * This struct holds the player data stored in each node of the BST. Every node stores
 * two integers, named wins and losses.
 */
struct Player {
    char *name;
    int wins;
    int losses;
};

struct Node {
    struct Player data;
    struct Node *left;
    struct Node *right;
};

/*
 * This function creates an empty binary search tree. It takes no parameters and returns
 * a pointer to a newly allocated struct Node.
 */
struct Node *createTree();

/*
 * This function adds the provided element to the binary search tree.
 *
 * Parameters:
 * tree - the BST to add the element to
 * name - the element of name to add to the BST
 * isWin - the element of isWin to add to the BST
 * isLos - the element of isLos to add to the BST
 *
 * Returns: 1 if insert successful, and 0 if it was not.
 */
int insertPlayer(struct Node *tree, char *name, int isWin, int isLos);

/*
 * This function finds an element in the binary search tree. It searches for the element
 * whose data.name value matches the name value passed to the function.
 *
 * Parameters:
 * tree - the BST to search in
 * name - the name to search for.
 *
 * Returns: 1 if the element was found in the BST, and 0 if it was not.
 */
int findPlayer(struct Node *tree, char *name);

/*
 * Updates an element in the BST in place.  Nothing is added or removed from the BST.
 * This function searches through the BST to find the element such that data.name
 * equals name. If it finds such an element, that element is set to the value of
 * isWin and isLos.
 *
 * Parameters:
 * tree - the BST to update
 * name - the name to search for.
 * isWin - the element of isWin to update for.
 * isLos - the element of isLos to update for.
 *
 * Returns: 1 if the BST was updated, 0 if the BST was not updated.
 */
int updatePlayer(struct Node *tree, char *name, int isWin, int isLos);

/*
 * Destroys a BST.  Every node in the BST will be deallocated, along with the BST itself.
 *
 * Parameters:
 * tree - the BST to destroy
 */
void destroyTree(struct Node *tree);

/*
 * Prints out the data stored in the BST.
 * The function would print:
 *
 * a, 0, 1
 * b, 1, 0
 *
 * Parameters:
 * tree - the BST to print
 */
void printTree(struct Node *tree);

#endif //PLAYER_H
