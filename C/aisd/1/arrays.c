#include <stdlib.h>

#include "arrays.h"

NodeVector*
CreateVector(int cap)
{
	ListNode** base = (ListNode**) malloc(sizeof(ListNode*) * cap);
	if(base == NULL)
		return NULL;
	for(int i = 0; i < cap; i++){
		base[i] = NULL;
	}
	NodeVector* vec = (NodeVector*) malloc(sizeof(NodeVector));
	if(vec == NULL)
		return NULL;
	vec->len = 0;
	vec->cap = cap;
	vec->base = base;
	return vec;
}

int
VecInsert(NodeVector* vec, List* list, Item* item)
{	
	int* findPtr = NULL;
	int err;
	VecFind(vec, item->hash, item->key, &findPtr);
	if(findPtr == NULL){ 
		ListNode* nodeptr = NULL;
										// not found  - we append
		err = ListHeadAppend(list, vec->base[item->hash], item, &nodeptr);
		if(err != 0){
			return err;
		}
		vec->base[item->hash] = nodeptr;
		(vec->len)++;									// load factor
		return 0;
	} 
	else{ 								// we found value by key - we change value
		*findPtr = item->value;
		free(item);
	}
	return 0;	
}

int
VecErase(NodeVector* vec, List* list, int index, int key)
{
	int err;
	ListNode* nextInBucket;
	err = DeleteNode(list, vec->base[index], index, key, &nextInBucket);
	if(err != 0){
		return err;
	}
	vec->base[index] = nextInBucket;
	(vec->len)--;										//load factor
	return 0;
}

int
VecFind(NodeVector* vec, int index, int key, int** resptr) // resptr = &ptr
{
	if(vec->base[index] == NULL){
		return 1;
	}
	int err = ListFind(vec->base[index], index, key, resptr);
	if(err != 0)
		return err;
	return 0;
}

void
DeleteVector(NodeVector* vec)
{
	free(vec->base);
	free(vec);	
}
