#include <stdio.h>
#include "error.h"

void Error(char status)
{
	switch(status){
	case error_x:
		printf("error: x must be float\n");
		break;
	case error_accuracy:
			printf("error: accuracy must be float\n");
			break;
	case error_range:
			printf("error: x must be in [-1,1] and accuracy must be greater than zero\n");
			break;
	case error_EOF:
				printf("\nerror: EOF\n");
				break;
	}
}
