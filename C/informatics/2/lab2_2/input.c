#include "input.h"
#include "error.h"
#include <stdlib.h>

int CheckBuffer(void)
{
	char c;
	int count = 0;
	while((c = getchar()) != '\n'){
		if (c == EOF){
			putchar('\n');
			exit(1);
		}
		count++;
	}
	return count;
}
int CheckInput(float* x, float* accuracy)
{	
	char err = 0;
	*accuracy = 0;
	printf("Enter x: ");
	if(scanf("%f", x) < 1)
		err = error_x;	
	if(CheckBuffer() != 0)
		err = error_x;
			
	printf("Enter accuracy: ");	
	if(scanf("%f", accuracy) < 1)
		err = error_accuracy;
	if(CheckBuffer() != 0)
		err = error_accuracy;
		
	if ((*x)*(*x) > 1 )
		err = error_range;
	if (err == 0 && *accuracy <= 0)
		err = error_range;
	return err;
}
int Input(float* x, float* accuracy)
{
	char err = 0;
	
	while(1){
		err = CheckInput(x, accuracy);
		if(err == 0)
			break;	
		Error(err);
	}
	return 0;
}
