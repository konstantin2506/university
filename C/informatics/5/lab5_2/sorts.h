#include "arrays.h"
#include "options.h"
#include <stddef.h>
#ifndef SORTS_H
#define SORTS_H

void BubbleSort(Dict* dict, int (*Compare)(const void*, const void*));
void QuickSort(Dict* dict, int (*Compare)(const void*, const void*));
void InsertionSort(Dict* dict, int (*Compare)(const void*, const void*));
void SortDict(void);
void Swap(char* x, char* y, size_t size, char* tmp);
int AccentCmp(const void* x, const void* y);
int WordCmp(const void* x, const void* y);
int MeaningCmp(const void* x, const void* y);
int AccentCmpR(const void* x, const void* y);
int WordCmpR(const void* x, const void* y);
int MeaningCmpR(const void* x, const void* y);
int Sort(Dict* dict, Options* opts);
#endif
