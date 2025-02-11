#include <stdio.h>
#include <string.h>
#include <time.h>

#include "mstring.h"


int
main(void)
{
    char buffer[80];
    char* res = GetLine();
    char* word = StrTok(res, "\t ");
    while(word != NULL){
        printf("word = '%s'\n", word);
        word = StrTok(NULL, "\t ");   
    }
    return 0;
}
