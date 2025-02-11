#include "input.h"
#include "error.h"
#include <stdlib.h>

int CheckBuffer(void)
{
	char c;
	int count = 0;
	while((c = getchar()) != '\n'){
		++count;
		if(c == EOF){
			putchar('\n');
			exit(1);
		}
	}
	return count;
}
int CheckInput(float* x, int* ops)
{	
	char err = 0;
	
	printf("Enter x: ");
	if(scanf("%f", x) < 1)
		err = error_x;
	if(CheckBuffer() != 0)
		err = error_x;	
	printf("Enter number of ops: ");	
	if(scanf("%d", ops) < 1)
		err = error_ops;
	if(CheckBuffer() != 0)
		err = error_ops;
	if ((*x)*(*x) > 1)
		err = error_range;
	if (*ops < 1 && err == 0)
		err = error_range;
	return err;
}
int Input(float* x, int* ops)
{
	while(1){
		char err = CheckInput(x, ops);
		if(err == 0)
			break;
		Error(err);	
	}
	return 0;
}
