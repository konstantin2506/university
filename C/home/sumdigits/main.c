#include <stdio.h>

int SumDigits(int);
int main()
{
    int val;
    printf("Input value: ");
    scanf("%d", &val);
    if(val < 0){
        printf("error: input value must be greater than zero\n");
        return 0;
    }
    int sumdigits = SumDigits(val);
    printf("value = %d, sum of digits = %d\n", val, sumdigits);
    return 0;
}
int SumDigits(int n)
{
    int sumdigits = 0;
    while(n > 0){
        sumdigits += n%10;
        n /= 10;
    }
    return sumdigits;
}