#include <stdio.h>

typedef long long int64;

int64 Palindrome(int64);
int64 Reverse(int64);
int IsPalindrome(int64);

int main()
{
    int64 val;
    printf("Input value: ");
    scanf("%lld",&val);
    if(val < 0){
        printf("error: incorrect input(value must be must be greater than zero)\n");
        return 0;
    }
    int64 palindrome;
    if((palindrome = Palindrome(val)) < 0){
        printf("error: too long palindrome\n");
        return 0;
    }
    printf("value = %lld, palindrome = %lld\n", val, palindrome);
    return 0;
}

int64 Palindrome(int64 val)
{
    while(!IsPalindrome(val)){
        val = val + Reverse(val);
        if(val < 0){
            return -1;
        }
    }    
    return val;
}
int64 Reverse(int64 n)
{
    int64 res = 0;
    while(n > 0)
    {
        res = res*10 + n%10;
        n /= 10;
    }
    return res;
}
int IsPalindrome(int64 n)
{
    return Reverse(n) == n;
}