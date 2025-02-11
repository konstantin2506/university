#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>

int
LinearSearch(VectorInt vec, int val)
{
	for(int i = 0; i < vec.len; ++i){
		if(vec.base[i] == val)
			return i;
	}
	return -1;
}
int
BinarySearch(VectorInt vec, int val)
{
	int m;
	int l = 0, r = vec.len - 1;

	if(val < vec.base[0] || val > vec.base[vec.len-1]) // if val exacly not in array
		return -1;
		
	while(l <= r){
		m = l+(r-l)/2;
		if(vec.base[m] == val)
			return m;
		if(vec.base[m] < val)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}
int
Expand(VectorInt* vec, int n)
{
	if(n < 0)
		return 2;
	vec->cap += n;
	vec->base = (int*)realloc(vec->base, (vec->cap)*sizeof(int));
	if(vec->base == NULL)
		return 1;
	return 0;
}
int
Reduce(VectorInt* vec, int n)
{
	if(n < 0)
		return 2;
	if(vec->len > vec->cap - n)
			return 1;
	vec->cap -= n;
	vec->base = (int*)realloc(vec->base, (vec->cap)*sizeof(int));
	if(vec->base == NULL)
			return 1;
	return 0;
}
void
PrintVec(const VectorInt* vec)
{
	for(int i = 0; i < vec->len; i++){
		printf("vec[%d] = %d\n", i, vec->base[i]);
	}
	printf("len = %d, cap = %d\n", vec->len, vec->cap);
}
int
Append(VectorInt* vec, int val)
{
	if(vec->cap == vec->len)
		return 1;
	vec->base[vec->len++] = val;
	return 0;
}
VectorInt
CreateVector(int cap)
{
	int* base = (int*)malloc(sizeof(int)*cap);
	VectorInt vec;
	vec.len = 0;
	vec.cap = cap;
	vec.base = base;
	return vec;
}
int
Insert(VectorInt* vec, int val, int p)
{
	if(p < 0)
		return 2;
	if(vec->cap == vec->len)
		return 1;
	if(p >= vec->len)
		return Append(vec, val);
	for(int i = (vec->len); i > p; --i){
		vec->base[i] = vec->base[i-1];
	}
	vec->base[p] = val;
	vec->len++;
	return 0;
}
int
Delete(VectorInt* vec, int p)
{
	if(p > (vec->len) || p < 0)
		return -1;
	for(int i = p; i < vec->len-1; ++i){
		vec->base[i] = vec->base[i+1];
	}
	vec->len--;
	return 0;
}
void
Swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
void
Reverse(VectorInt vec)
{
	int len = vec.len;
	for(int i = 0; i < len/2; ++i)
		Swap(&vec.base[i],&vec.base[len-1-i]);
}	
void
Task(VectorInt* vec)
{
	
	VectorInt tmp = CreateVector(vec->cap); //1 2 1 1 3 1 3 4 4 5 6
	VectorInt res = CreateVector(vec->cap);
	for(int i = 1, c = 1; i < vec->len; i++){
			
			if(vec->base[i] != vec->base[i-1]){
				Append(&tmp, vec->base[i-1]);
				
			}
			if(i == vec->len - 1){
				Append(&tmp, vec->base[i]);

				if(vec->base[i] == vec->base[i-1])
					Append(&res, vec->base[i]);
			}
				
			if(vec->base[i] == vec->base[i-1]){
				c++;
				Append(&res, vec->base[i-1]);
			}

			if(c>1 && vec->base[i] != vec->base[i-1]){
				Append(&res, vec->base[i-1]);
				c = 1;	
			}
		}
	free(vec->base);
	vec->base = tmp.base;
	vec->len = tmp.len;
	PrintVec(&res);
	free(res.base);
}
