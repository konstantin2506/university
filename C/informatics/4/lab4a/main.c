#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <readline/readline.h>

#include "mstring.h"


int 
main(void)
{
    char* str = NULL;
    char* res = NULL;
    double t1, t2, time;
    while((str = readline(NULL)) != NULL){
        t1 = clock();
        res = StrHandler(str);
        t2 = clock();
        time = (1000000*t2 - 1000000*t1 )/ CLOCKS_PER_SEC;
        printf("result = '%s'\nHandler finished at %lf μs.\n",res, time);
        
        
        free(str);
        
        free(res);
        
    }
    
    return 0;
}


