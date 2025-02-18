#include <stdlib.h>
#include <stdio.h>

#include "hashtable.h"

int 
HashFunc(HashTable* htable, int key)
{
	int hash = key % htable->cap;
	
	return hash;
}
Item*
CreateItem(HashTable* htable, int key, int value)
{
	Item* item = (Item* ) malloc(sizeof(Item));
	if(item == NULL){
		return NULL;
	}
	item->value = value;
	item->key = key;
	int hash = HashFunc(htable, key);
	item->hash = hash;

	return item;
}

HashTable* 
HTCreate(int cap)
{
	HashTable* htable = (HashTable* ) malloc(sizeof(HashTable));
	if(htable == NULL){
		return NULL;
	}
	htable->vec = CreateVector(cap);
	if (htable->vec == NULL){
		free(htable);
		return NULL;
	}
	htable->list = CreateList();
	if (htable->list == NULL){
		free(htable->vec);
		free(htable);
		return NULL;
	}
	
	htable->cap = cap;
	htable->len = 0;
	htable->loadFactor = 0;
	return htable;
}

int 
HTInsert(HashTable* htable, int key, int value)
{
	Item* item = CreateItem(htable, key, value);
	if(item == NULL){
		return 2;
	}
	int err = VecInsert(htable->vec, htable->list,  item);
	if(err != 0){
		return err;
	}	
	htable->len = htable->vec->len;
	htable->cap = htable->vec->cap;
	htable->loadFactor = (float) (htable->len) / (htable->cap);
	return 0;
}
int
HTSmartInsert(HashTable** htable, int key, int value)
{
	if(*htable == NULL){
		return 1;
	}
	int err = HTInsert(*htable, key, value);
	if(err != 0){
		return err;
	}
	if((*htable)->loadFactor >= 0.7){
		HashTable* newHtable = HTResize(*htable);
		if(newHtable == NULL){
			printf("error: resize not ok\n");
			return 3;
		}
		HTDelete(*htable);
		*htable = newHtable;
	}
	return 0;
}
int 
HTFind(HashTable* htable, int key, int* res)
{
	int* resfind = NULL;
	int hash = HashFunc(htable, key);
	int err = VecFind(htable->vec, hash, key, &resfind);
	if(err != 0){
		return err;
	}
	*res = *resfind;
	return 0;
}
int 
HTErase(HashTable* htable, int key)
{
	int hash = HashFunc(htable, key);
	int err = VecErase(htable->vec, htable->list, hash, key);
	if(err != 0){
		return err;
	}
	htable->len = htable->vec->len;
	htable->cap = htable->vec->cap;
	htable->loadFactor = (float) (htable->len) / (htable->cap);
	return 0;
	
}

void 
HTDelete(HashTable* htable)
{
	DeleteList(htable->list);
	DeleteVector(htable->vec);
	free(htable);
}

HashTable* 
HTResize(HashTable* htable)
{
	const int factor = 2;
	HashTable* newHtable = HTCreate(htable->cap * factor);
	if(newHtable == NULL){
		return NULL;
	}
	int err = 0;
	ListNode* ptr = htable->list->first;
	while (ptr != NULL){
		err += HTInsert(newHtable, ptr->item->key, ptr->item->value);
		ptr = ptr->next;
	}
	if(err != 0){
		return NULL;
	}
	return newHtable;
}
