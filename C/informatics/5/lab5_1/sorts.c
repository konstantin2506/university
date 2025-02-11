#include "sorts.h"
#include "arrays.h"
#include "options.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void
BubbleSort(Dict* dict, int (*Compare)(const void*, const void*))
{
	for(int i = 0; i < dict->len-1; i++){
		for(int j = 0; j < dict->len-1; j++){
			if(Compare( &(dict->base[j]) ,  &(dict->base[j+1]) ) > 0)
				SwapEntries(&(dict->base[j]) ,  &(dict->base[j+1]));
		}
	}	
}

void
InsertionSort(Dict* dict, int (*Compare)(const void*, const void*))
{
	for(int i = 1; i < dict->len; i++){
		for(int j = i; j > 0 && (Compare( &(dict->base[j-1]) ,  &(dict->base[j]) ) > 0); j--)
			SwapEntries(&(dict->base[j]) ,  &(dict->base[j-1]));
	}
}
void
QuickSort(Dict* dict, int (*Compare)(const void*, const void*))
{
	qsort(dict->base, dict->len, sizeof(DictEntry), Compare);
}
int
AccentCmp(const void* x, const void* y)
{
	DictEntry* a = (DictEntry*)x;
	DictEntry* b = (DictEntry*)y;
	return a->accent - b->accent;
}
int
WordCmp(const void* x, const void* y)
{
	DictEntry* a = (DictEntry*)x;
	DictEntry* b = (DictEntry*)y;
	return strcmp(a->word, b->word);
}
int
MeaningCmp(const void* x, const void* y)
{
	DictEntry* a = (DictEntry*)x;
	DictEntry* b = (DictEntry*)y;
	return strcmp(a->meaning, b->meaning);
}
int
AccentCmpR(const void* x, const void* y)
{
	DictEntry* a = (DictEntry*)x;
	DictEntry* b = (DictEntry*)y;
	return -(a->accent - b->accent);
}
int
WordCmpR(const void* x, const void* y)
{
	DictEntry* a = (DictEntry*)x;
	DictEntry* b = (DictEntry*)y;
	return -strcmp(a->word, b->word);
}
int
MeaningCmpR(const void* x, const void* y)
{
	DictEntry* a = (DictEntry*)x;
	DictEntry* b = (DictEntry*)y;
	return -strcmp(a->meaning, b->meaning);
}
int Sort(Dict* vec, Options* opts)
{
	int err = 0;

	if(opts->pvalue == NULL){
		fprintf(stderr, "error: sorting pole is not choosen\n");
		err = 2;
		return err;	
	}
	
	void (*Sort)(Dict*, int (*Compare)(const void*, const void*));

	if(strlen(opts->svalue) > 1){
		fprintf(stderr, "error: unknown sorting algorithm\n");
		err = 1;
		return err;
	}
	switch(opts->svalue[0]){
	case 'b':
		Sort = BubbleSort;
	break;
	case 'i':
		Sort = InsertionSort;
		break;
	case 'q':
		Sort = QuickSort;
		break;
	default:
		fprintf(stderr, "error: unknown sorting algorithm\n");
		err = 1;
	}
	if (err != 0)
		return err;

	if(strlen(opts->svalue) > 1){
		fprintf(stderr, "error: incorrect sort parameter\n");
		err = 3;
		return err;
		}
	int reversed = opts->tflag;
	switch(opts->pvalue[0]){
	default:
		fprintf(stderr, "error: incorrect sort parameter\n");
		err = 3;
		return err;
	case '1':
		if(reversed)
			Sort(vec, WordCmpR);
		else	
			Sort(vec, WordCmp);
		break;
	case '2':
		if(reversed)
			Sort(vec, AccentCmpR);
		else
			Sort(vec, AccentCmp);
		break;
	case '3':
		if(reversed)
			Sort(vec, MeaningCmpR);
		else
			Sort(vec, MeaningCmp);
		break;
	}
	
	return err;
}


