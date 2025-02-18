#ifndef LIST_H
#define LIST_H

typedef struct Item{
	int key;
	int value;
	int hash;
}Item;
struct ListNode{
	struct ListNode* next;
	struct ListNode* prev;
	Item* item;
};
typedef struct ListNode ListNode;

typedef struct List{
	ListNode* first;
	ListNode* last;
}List;


List* CreateList(void);
void DeleteList(List* list);
int ListHeadAppend(List* list, ListNode* vecptr, Item* item, ListNode** nodeptr);
int ListFind(ListNode* list, int hash, int key, int** res);
int DeleteNode(List* list, ListNode* vecptr, int hash, int key, ListNode** nextInBucket);
#endif
