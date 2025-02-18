#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List*
CreateList(void)
{
	List* list = (List* ) malloc(sizeof(List));
	if(list == NULL){
		return NULL;
	}
	list->last = NULL;
	list->first = NULL;
	return list;
}
int
ListHeadAppend(List* list, ListNode* vecptr, Item* item, ListNode** nodeptr)
{
	ListNode* newNode = (ListNode* ) malloc(sizeof(ListNode));
	if(newNode == NULL){
		*nodeptr = NULL;
		return 1;
	}
	if(list == NULL){
		free(newNode);
		return 2;
	}
	newNode->item = item;
	*nodeptr = newNode; 
	if(vecptr == NULL){	
											//no collision
		if(list->last == NULL){	
			list->last = newNode;
			list->first = newNode;
			newNode->prev = NULL;
			newNode->next = NULL;
		}
		else{
			list->last->next = newNode;
			newNode->prev = list->last;
			newNode->next = NULL;
			list->last = newNode;
		}
		return 0;
	}
	else{	
											//collision
		if(vecptr->prev == NULL){
			newNode->next = vecptr;
			vecptr->prev = newNode;
			newNode->prev = NULL;
			list->first = newNode;
		}
		else{	
			vecptr->prev->next = newNode;
			newNode->prev = vecptr->prev;
			newNode->next = vecptr;
			vecptr->prev = newNode;
		}
	}
	return 0;
}

int 
ListFind(ListNode* list, int hash, int key, int** resptr)
{
	if(list == NULL){
		*resptr = NULL;
		return 1;
	}
	ListNode* ptr = list;
	while((ptr != NULL) && (ptr->item->hash == hash)){
		if(ptr->item->key == key){
			*resptr = &(ptr->item->value);
			return 0;
		}
		ptr = ptr->next;
	}
	return 1;
}
int 
DeleteNode(List* list, ListNode* vecptr, int hash, int key, ListNode** nextInBucket)
{
	ListNode* ptr = vecptr;
	while(ptr != NULL && ptr->item->hash == hash){
		if(ptr->item->key == key){
			if((ptr->next == NULL ) || (ptr->item->hash != ptr->next->item->hash)){
				*nextInBucket = NULL;
			}
			else{
				*nextInBucket = ptr->next;
			}
			if(ptr == list->last && ptr == list->first){
				list->first = NULL;
				list->last = NULL;
				free(ptr->item);
				free(ptr);
				return 0;
			}
			else if(ptr == list->first){
				list->first = ptr->next;
				ptr->next->prev = NULL;
				free(ptr->item);
				free(ptr);
				return 0;
			}
			else if(ptr == list->last){
				list->last = ptr->prev;
				ptr->prev->next = NULL;
				free(ptr->item);
				free(ptr);
				return 0;
			}
			else{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				free(ptr->item);
				free(ptr);
				return 0;
			}
		}
		ptr = ptr->next;
	}
	return 1;
}
void
DeleteList(List* list)
{
	ListNode* ptrfree = list->first;
	ListNode* ptr = list->first;
	
	while(ptr != NULL){
		ptrfree = ptr;
		ptr = ptr->next;
		free(ptrfree->item);
		free(ptrfree);
	}
	free(list);
}

