#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List* 
CreateList(void)
{
	List* list = (List*)malloc(sizeof(List));
	list->first = NULL;
	list->last = NULL;
	return list;
}
ListNode*
CreateListNode(void)
{
	return (ListNode*)malloc(sizeof(ListNode));
}
//
void 
ListAppend(List* list, char c)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->ch = c;
	newNode->next = NULL;
	if(list->last == NULL)
		list->last = newNode;
	else{
		list->last->next = newNode;	
		list->last = list->last->next;
	}
	if(list->first == NULL){
		list->first = newNode;
	}
}
void 
PrintList(List* list)
{
	ListNode* ptr = list->first;
	printf("list = ");
	printf("'");
	while(ptr != NULL){
		printf("%c",ptr->ch);
		ptr = ptr->next;
	}
	printf("'\n");
}
//
void
ListDupVowels(List* list)
{
	ListNode* ptr = list->first;
	char vowels[] = {'a', 'e', 'i', 'o', 'u','A', 'E', 'I', 'O', 'U'};
	int vowelsLen = 10;
	
	while(ptr != NULL){
		for(int i = 0; i < vowelsLen; i++){
			if(ptr->ch == vowels[i]){
				ListNode* duplicate = CreateListNode();
				duplicate->next = ptr->next;
				duplicate->ch = ptr->ch;
				ptr->next = duplicate;
				ptr = ptr->next;
			}		
		}
		ptr = ptr->next;
	}
}

void
DeleteList(List* list)
{
	ListNode* ptrfree = list->first;
	ListNode* ptrnext = list->first;
	
	while(ptrnext != NULL){
		ptrfree = ptrnext;
		ptrnext = ptrnext->next;
		free(ptrfree);
	}
	free(list);
}
