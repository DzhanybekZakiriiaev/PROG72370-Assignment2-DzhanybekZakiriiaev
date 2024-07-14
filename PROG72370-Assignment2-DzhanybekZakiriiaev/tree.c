// tree.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void traverse(PLINK h)
{
    if (h == NULL) return;
    traverse(h->pLeft);
    printf("%c ", h->content);
    traverse(h->pRight);
    return;
}


PLINK Init(char c, PLINK left, PLINK right) {
    PLINK node = (PLINK)malloc(sizeof(LINK));
    if (node != NULL) {
        node->content = c;
        node->pLeft = left;
        node->pRight = right;
    }
    return node;
}

PLINK Insert(PLINK h, char c) {
    if (h == NULL) {
        return Init(c, NULL, NULL);
    }
    if (c < h->content) {
        h->pLeft = Insert(h->pLeft, c);
    }
    else {
        h->pRight = Insert(h->pRight, c);
    }
    return h;
}

PLINK Search(PLINK h, char c) {
    if (h == NULL) {
        return NULL;
    }
    if (c == h->content) {
        return h;
    }
    if (c < h->content) {
        return Search(h->pLeft, c);
    }
    else {
        return Search(h->pRight, c);
    }
}

int CountNodes(PLINK h) {
    if (h == NULL) {
        return 0;
    }
    return 1 + CountNodes(h->pLeft) + CountNodes(h->pRight);
}

int DetermineTreeHeight(PLINK h) {
    int iLeftH, iRightH;
    if (h == NULL) {
        return -1;
    }
    iLeftH = DetermineTreeHeight(h->pLeft);
    iRightH = DetermineTreeHeight(h->pRight);
    if (iLeftH > iRightH) {
        return iLeftH + 1;
    }
    else {
        return iRightH + 1;
    }
}
