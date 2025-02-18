#ifndef ARRAYS_H
#define ARRAYS_H

#include "list.h"

typedef struct NodeVector{
	ListNode** base;
	int         len;
	int         cap;
}NodeVector;

int Expand(NodeVector*, int);
int Reduce(NodeVector*, int);

NodeVector* CreateVector(int);

void DeleteVector(NodeVector*);
int VecFind(NodeVector* vec, int index, int key, int** resptr);
int VecInsert(NodeVector* vec, List* list, Item* item);
int VecErase(NodeVector* vec, List* list, int index, int key);

#endif

