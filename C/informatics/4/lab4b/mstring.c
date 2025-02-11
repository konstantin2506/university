#include "mstring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000
int 
StrLen(const char* str)
{
    int len = 0;
    int i = 0;
    while(str[i++])
        len++;
    return len;
}
void
StrCpy(char* dst, const char* src)
{
    for(int i = 0; (dst[i] = src[i]); i++);
}
char*
GetWord(char* str, const char* delims)
{
    static char* word;
    char* res = NULL;
    if(str != NULL)
        word = str;
    int word_len = StrLen(word);
    if(word_len == 0)
        return NULL;
    while((Contains(delims, *word))){   // skip first delims
        *word = '\0';
        word++;
    } 
    word_len = StrLen(word);
    for(int i = 0; (i < word_len+1); i++, word++){
        if(*word == '\0'){
            res = word - i;
            break;
        }
        if(Contains(delims, *word)){
            *word = '\0';
            res = word-i;
            if(i != word_len-1)
                word++;
            break;
        }
    }
    if(res[0] == '\0')
        return NULL; 
    return res;
}
int
Contains(const char* symbols, char c)
{
    for(int i = 0; i < StrLen(symbols); i++){
        if(c == symbols[i])
            return 1;
    }
    return 0;
}
char*
GetLine(void)
{
    char buffer[BUFFER_SIZE] = {0};
    char* res = NULL;
    
    long n = 0, res_len = 0;
    
    do{
        n = scanf("%999[^\n]", buffer);
        if(n < 0){
            if(res == NULL)
                return NULL;
        }
        else if(n > 0){
            int buffer_len = StrLen(buffer);
            long new_len = res_len + buffer_len;
            res = (char* )realloc(res, new_len + 1);
           
            MemCpy(res + res_len, buffer, buffer_len);
            res_len = new_len;
        }
        else{
            scanf("%*c");
        }
    }while(n > 0);

    if(res_len > 0)
        res[res_len] = '\0';
    else
        res = calloc(1, sizeof(char));
    return res;
}
void* 
MemCpy(void* dest, const void* src, int n)
{
    char* d = dest;
    const char* s = src; 
    for(int i = 0; i < n; i++)
        d[i] = s[i];
    return d;
}
void*
MemSet(void* ptr, int val, int size)
{
    char* p = ptr;
    for(int i = 0; i < size; i++)
        p[i] = val;
    return p;
}
char*
StrHandler(const char* str)
{                                                                  
    char* cpy = (char*)malloc(StrLen(str)+1); 
    char* res = (char*)malloc(StrLen(str)+1);
    char* new_word = NULL;
    StrCpy(cpy, str);
    MemSet(res, 0, StrLen(str)+1);
    int i = 0;
    char* word = GetWord(cpy, " ");
    while(word != NULL){
        new_word = SwapCase(word);
        MemCpy(res+i, new_word, StrLen(new_word));
        i += StrLen(new_word);
        free(new_word);
        res[i] = ' ';
        i++;
        word = GetWord(NULL, " ");
    }
    res[--i] = '\0';
    res = (char*)realloc(res, StrLen(res)+1);
    free(cpy);
    return res;
}
char* 
SwapCase(const char* str)
{
    char* new_str = (char*)malloc(StrLen(str) + 1);
    int delta = 'a' - 'A';
    char nc;
    for(int i = 0; str[i]; i++){
        if(str[i] >= 'a' && str[i] <= 'z')
            nc = str[i] - delta;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            nc = str[i] + delta;
        else 
            nc = str[i];
        new_str[i] = nc;
    }
    new_str[StrLen(str)] = '\0';
    return new_str;
}
