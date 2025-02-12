#include "input.h"
#include <stdio.h>

#define BUFFER_SIZE 100

int 
InputInt(long* x, int size)
{
	int err = 0;
	if(size % 2 != 0 || size > 64 || size<=0){
		return ERROR_SIZE;
	}
	long predict = (Pow(2, size-1)-1)/10;
	long tmp = 0;
	char sign = 0;
	char buffer[BUFFER_SIZE];
	char current;
	int i;
	for(i = 0; (current = getchar()); ++i){
		if(i >= BUFFER_SIZE - 1)
			break;
		if( current == '\n')
			break;
			
		if( current == EOF)
			return ERROR_EOF;
		
		if(!IsDigit(current) && current != '-')
			err = ERROR_TYPE;
				
		buffer[i] = current;
	}
	buffer[i] = '\0';
	if(err == ERROR_TYPE)
		return ERROR_TYPE;
	if(buffer[0] == '\0')
		return ERROR_EMPTY_INPUT;
	
	for(int i = 0; (i < BUFFER_SIZE) && (buffer[i] != '\0'); ++i){
		if (feof(stdin) != 0)
			return ERROR_EOF;
	
		if(tmp >= predict)
			return ERROR_RANGE;
		
		if(buffer[i] == '-' && sign == 0){
			sign = 1;
			continue;
		}
		if(buffer[i] == '-' && sign == 1)
			return ERROR_TYPE;
		
		
		tmp = tmp * 10 + (buffer[i] - '0');		
	}

	*x = (sign == 0) ? tmp : -tmp;

	return err;
}
int
InputInt64(long* x)
{
	long t = *x;
	char err = InputInt(&t, 64);
	*x = t;
	return err;
}
int
InputInt32(int* x)
{
	long t = *x;
	int err = InputInt(&t, 32);
	*x = (int)t;
	return err;
}
int
InputInt16(short* x)
{
	long t = *x;
	char err = InputInt(&t, 16);
	*x = (short)t;
	return err;
}
int
InputInt8(char* x)
{
	long t = *x;
	char err = InputInt(&t, 8);
	*x = (char)t;
	return err;
}
int
IsDigit(char c)
{
	char dif = c - '0';
	if(dif > 9 || dif < 0)
		return 0;
	return 1;
}
long
Pow(int x, int pow)
{
	long res = 1;
	for(int i = 0; i < pow; ++i)
		res *= x;
	return res;
}

