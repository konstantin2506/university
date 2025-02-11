#include "input.h"
#include "mylog.h"
#include <math.h>

int main(void)
{	
	float x, std, mylog;	
	int ops;
	
	if(Input(&x, &ops) != 0){
		return 0;
	}
	std = log(x + sqrt(1+x*x));
	mylog = MyLog(x, ops);
	printf("results:\n std: %.6f\n my:  %.6f\n", std, mylog);
	
	return 0;
}
