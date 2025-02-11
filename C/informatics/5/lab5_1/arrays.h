#ifndef ARRAYS_H
#define ARRAYS_H

typedef struct DictEntry{
	char word[20];
	int accent;
	char* meaning;
}DictEntry;

typedef struct Dict{
	int len;
	int cap;
	DictEntry* base;
}Dict;

int Expand(Dict*, int);
int Reduce(Dict*, int);

Dict CreateVector(int);
int Append(Dict*, char* word, int accent, char* meaning);
int Insert(Dict*, int, int);
int Delete(Dict*, int);
void SwapEntries(DictEntry* x, DictEntry* y);
void Reverse(Dict*);
void DeleteVector(Dict*);
void PrintVec(const Dict*);
void PrintEntry(const DictEntry* entry);
#endif

