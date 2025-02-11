#include <stdio.h>

int	DevideByFactor(int, int*);
void PrimeFactorization(int);

int main(void)
{
	int num;
	printf("/~/ PRIME FACTORIZATION /~/\n");
	printf("Input number: ");
	if(scanf("%d", &num) < 1){
		printf("error: incorrect input\n");
		return 0;
	}

	if(num <= 1){
		printf("error: number must be greater than 1\n"); //??
		return 0;
	}
	PrimeFactorization(num);
	return 0;
}
int DevideByFactor(int dev, int* num) /*devides num by devisor and counts devisions*/
{
	int pow = 0;
	for(; *num % dev == 0; ++pow)
		*num /= dev;
	return pow;
}
void PrimeFactorization(int num)
{
	int dev = 2;
	printf("Prime factorization of %d:\n", num);
	while(num > 1){
		if(dev*dev <= num){ 	// <=> (dev <= sqrt(num))
			int pow = 0; 
			if((pow = DevideByFactor(dev,&num)) > 0){
				printf("%d^%d ",dev,pow);
			}
			++dev;
		}
		else{
			printf("%d^1",num);
			break;
		}
	}
	printf("\n");
}


