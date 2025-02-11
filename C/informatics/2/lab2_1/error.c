#include <stdio.h>
#include "error.h"

void Error(char status)
{
	switch(status){
	case error_x:
		printf("error: x must be float\n");
		break;
	case error_ops:
		printf("error: ops must be int\n");
		break;
	case error_range:
		printf("error: x must be in [-1,1] and ops must be > 1\n");
		break;
	case error_EOF:
		printf("\nerror: EOF\n");
		break;
	default:
		printf("error: unknown error status '%d'",status);
		break;
	}
}
