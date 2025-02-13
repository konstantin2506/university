#include <stdio.h>

#include "input.h"
#include "matrix.h"

int
main(void)
{
	Matrix* matrix = CreateMatrix();
	PrintMatrix(matrix);
	DeleteMatrix(matrix);
	return 0;
}
