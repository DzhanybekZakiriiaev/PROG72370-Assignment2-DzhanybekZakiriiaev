#pragma once
#include <stdio.h>

typedef struct link {
	char content;
	struct link* pRight;
	struct link* pLeft;
}LINK, *PLINK;

PLINK Init(char c, PLINK left, PLINK right);
void traverse(PLINK h);
PLINK Insert(PLINK h, char c);
PLINK Search(PLINK h, char c);
int CountNodes(PLINK h);
int DetermineTreeHeight(PLINK h);