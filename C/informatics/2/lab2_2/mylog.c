#include "mylog.h"

#define abs(x) (x>0 ? x : -x)

float MyLog(float x, float accuracy, int* ops)
{
	int n = 1;
	float summa = x;
	float msquare = -(float)x*x;
	float factor = x;


	while(abs(factor) > accuracy){
		factor *= msquare * (2*n-1) * (2*n-1) / ( (2*n+1) * (2*n) );
		summa += factor;
		n++;

	}
	*ops = n;
	return summa;
}
