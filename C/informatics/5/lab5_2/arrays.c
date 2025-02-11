#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
Expand(Dict* vec, int n)
{
	if(n < 0)
		return 2;
	vec->cap += n;
	vec->base = (DictEntry*)realloc(vec->base, (vec->cap)*sizeof(DictEntry));
	if(vec->base == NULL)
		return 1;
	return 0;
}

void
PrintVec(const Dict* vec)
{
	for(int i = 0; i < vec->len; i++){
		printf("vec[%d]= word: %s, accent: %d, meaning: %s\n", i, vec->base[i].word, vec->base[i].accent, vec->base[i].meaning);
	}
}
void
PrintEntry(const DictEntry* entry)
{
	printf("%s %d %s\n", entry->word, entry->accent, entry->meaning);
}
int
Append(Dict* vec, char* word, int accent, char* meaning)
{
	if(vec->cap == vec->len)
		Expand(vec, vec->cap);
	strcpy(vec->base[vec->len].word, word);
	vec->base[vec->len].accent = accent;
	vec->base[vec->len].meaning = (char*)malloc(strlen(meaning)+1);
	strcpy(vec->base[vec->len].meaning, meaning);
	vec->len++;
	return 0;
}
Dict
CreateVector(int cap)
{
	DictEntry* base = (DictEntry*)malloc(sizeof(DictEntry)*cap);
	Dict vec;
	vec.len = 0;
	vec.cap = cap;
	vec.base = base;
	return vec;
}
void
DeleteVector(Dict* vec)
{
	for(int i = 0; i < vec->len; i++){
		free(vec->base[i].meaning);
	}
	free(vec->base);
	
}
void 
SwapEntries(DictEntry* x, DictEntry* y)
{
	DictEntry tmp = *x;
	*x = *y;
	*y = tmp;
}


