#include <stdio.h>
#ifndef MSTRING_H
#define MSTRING_H

int StrLen(const char* str);
void StrCpy(char* dst, const char* src);
char* GetLine(FILE*);
char* StrHandler(const char* str);
int Contains(const char* symbols, char c);
char* GetWord(char* str, const char* delims);
char* SwapCase(const char* str);
void* MemCpy(void* , const void*, int);
void* MemSet(void* ptr, int val, int size);
#endif
