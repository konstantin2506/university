#include "input.h"
#include "mylog.h"
#include <math.h>

int main(void)
{	
	float x, std, accuracy;	
	int ops;
	
	Input(&x, &accuracy);
	std = log(x + sqrt(1+x*x));
	float mylog = MyLog(x, accuracy, &ops);
	printf("results:\n std: %.6f\n my:  %.6f\nops: %d\n", std, mylog, ops);
	
	return 0;
}
