#ifndef LIST_H
#define LIST_H

struct ListNode{
	char ch;
	struct ListNode* next;
};
typedef struct ListNode ListNode;
typedef struct List{
	ListNode* first;
	ListNode* last;
}List;

void ListAppend(List* list, char c);
List* CreateList(void);
void PrintList(List* list);
void ListDupVowels(List*);
ListNode* CreateListNode(void);
void DeleteList(List* list);

#endif
