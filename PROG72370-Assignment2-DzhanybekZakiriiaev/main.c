#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

int main(void) {

    PLINK head = NULL;
    int numChars, i;
    char randomChar;
    char charArray[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    srand(time(NULL));

    numChars = rand() % 10 + 11;

    for (i = 0; i < numChars; i++) {
        randomChar = charArray[rand() % 52];
        head = Insert(head, randomChar);
    }

    printf("Characters in tree (in-order traversal): ");
    traverse(head);
    printf("\n");

    printf("Total number of nodes: %d\n", CountNodes(head));

    printf("Height of the tree: %d\n", DetermineTreeHeight(head));

    return 0;
}