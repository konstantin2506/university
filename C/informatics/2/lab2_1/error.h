#include <stdio.h>

enum error_status {
	error_x       =  -1,
	error_ops =      -2,
	error_range    = -3,
	error_EOF    =   -4,
};
void Error(char status);
