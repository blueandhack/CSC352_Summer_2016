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

struct TreeNode {
    struct Player data;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
 * This function creates an empty binary search tree. It takes no parameters and returns
 * a pointer to a newly allocated struct TreeNode.
 */
struct TreeNode *createTree();

/*
 * This function adds the provided element to the binary search tree.
 *
 * Parameters:
 * tree - the BST to add the element to
 * player - the element to add to the BST
 *
 * Returns: 1 if insert successful, and 0 if it was not.
 */
int insertPlayer(struct TreeNode *tree, struct Player *player);

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
int findPlayer(struct TreeNode *tree, char *name);

/*
 * Updates an element in the BST in place.  Nothing is added or removed from the BST.
 * This function searches through the BST to find the element such that data.name
 * equals name. If it finds such an element, that element is set to the value of
 * isWin and isLos.
 *
 * Parameters:
 * tree - the BST to update
 * player - the player to search for.
 *
 * Returns: 1 if the BST was updated, 0 if the BST was not updated.
 */
int updatePlayer(struct TreeNode *tree, struct Player *player);

/*
 * Destroys a BST.  Every node in the BST will be deallocated, along with the BST itself.
 *
 * Parameters:
 * tree - the BST to destroy
 */
void destroyTree(struct TreeNode *tree);

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
void printTree(struct TreeNode *tree);

#endif //PLAYER_H
