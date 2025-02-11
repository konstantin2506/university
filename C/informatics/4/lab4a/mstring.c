#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mstring.h"

char*
StrHandler(const char* str)
{                                                                  
    char* cpy = (char*)malloc(strlen(str)+1); 
    char* res = (char*)malloc(strlen(str)+1);
    char* new_word = NULL;
    strcpy(cpy, str);
    memset(res, 0, strlen(str)+1);
    int i = 0;
    char* word = strtok(cpy, " ");
    while(word != NULL){
        new_word = SwapCase(word);
        memcpy(res+i, new_word, strlen(new_word));
        //printf("in handler: '%s'\n", res);
        i += strlen(new_word);
        free(new_word);
        res[i] = ' ';
        i++;
        word = strtok(NULL, " ");
    }
    res[--i] = '\0';
    res = (char*)realloc(res, strlen(res)+1);
    free(cpy);
    return res;
}
char* 
SwapCase(const char* str)
{
    char* new_str = (char*)malloc(strlen(str) + 1);
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
    new_str[strlen(str)] = '\0';
    return new_str;
}
