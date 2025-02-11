#include <stdio.h>
#include "arrays.h"

void HardTask(const VectorInt* vec)
{
	int n;
	scanf("%d",&n);
	int l = 0;
	int r = vec->len-1;
	int m,k1,len1,p1;
	int p = 0;
	
	while(l != r-1){
		m = (r-l)/2 + l;
		k1 = vec->base[m] - vec->base[l] - 1;

		len1 = m - l - 1;
		
		p1 = k1 - len1;
		printf("m = %d, l = %d, r = %d, k1 = %d, len1 = %d, p1 = %d, p = %d\n",m,l,r,k1,len1,p1,p);
		if(n > p + p1){
			l = m;
			p += p1;
		}
		else
			r = m;
	}
	printf("ans = %d l = %d\n",l+vec->base[0]+n, l);
}
