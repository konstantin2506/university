#include "mstring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 101

char*
GetLine(FILE* file)
{
    char buffer[BUFFER_SIZE] = {0};
    char* res = NULL;
    
    long n = 0, res_len = 0;
    
    do{
    	if(file == stdin)
    		n = scanf("%100[^\n]", buffer);
    	else
        	n = fscanf(file,"%100[^\n]", buffer);
        if(n < 0){
            if(res == NULL)
                return NULL;
        }
        else if(n > 0){
            int buffer_len = strlen(buffer);
            long new_len = res_len + buffer_len;
            res = (char* )realloc(res, new_len + 1);
           
            memcpy(res + res_len, buffer, buffer_len);
            res_len = new_len;
        }
        else{
            fscanf(file,"%*c");
        }
    }while(n > 0);

    if(res_len > 0)
        res[res_len] = '\0';
    else
        res = calloc(1, sizeof(char));
    return res;
}

