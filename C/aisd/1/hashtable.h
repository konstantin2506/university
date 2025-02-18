#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "list.h"
#include "arrays.h"

typedef struct HashTable{
	NodeVector* vec;
	List* list;
	float loadFactor;
	int len;
	int cap;
}HashTable;

int HashFunc(HashTable* htable, int key);
HashTable* HTCreate(int cap);
int HTInsert(HashTable* htable, int key, int value);
int HTSmartInsert(HashTable** htable, int key, int value);
int HTFind(HashTable* htable, int key, int* res);
int HTErase(HashTable* htable, int key);
HashTable* HTResize(HashTable* htable);
void HTDelete(HashTable* htable);
Item* CreateItem(HashTable* htable, int key, int value);
#endif
