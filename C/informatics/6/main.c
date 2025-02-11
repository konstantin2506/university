#include <stdio.h>

#include "list.h"

int
main(void)
{
	char c;
	List* str = CreateList();
	while((c = getchar()) != EOF){
		ListAppend(str, c);
	}
	printf("\n");
	PrintList(str);
	ListDupVowels(str);
	PrintList(str);
	DeleteList(str);
	return 0;
}
