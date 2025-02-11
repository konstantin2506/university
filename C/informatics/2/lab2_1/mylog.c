#include "mylog.h"

float MyLog(float x, int ops)
{
	float res = x;
	float summa = 0;
	float msquare = -(float)x*x;
	float factor = x;

	for(int n = 1; n <= ops; ++n){
		factor *= msquare * (2*n-1) * (2*n-1) / ( (2*n+1) * (2*n) );
		summa += factor;
	}
	res += summa;
	return res;
}
