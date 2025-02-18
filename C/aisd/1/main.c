#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"
#include "matrix.h"

int
main(void)
{
	Matrix* matrix = CreateMatrix();
	if(matrix == NULL){
		fprintf(stderr, "error: null-matrix");
		return 1;
	}
	Matrix* result = (Matrix* ) malloc(sizeof(Matrix));
	if(result == NULL){
		fprintf(stderr, "error: null-result");
		DeleteMatrix(matrix);
		return 1;
	}
	result->numLines = matrix->numLines;
	result->lines = (Line* ) malloc(sizeof(Line) * result->numLines);
	if(result->lines == NULL){
		fprintf(stderr, "error: null result->lines");
		DeleteMatrix(matrix);
		DeleteMatrix(result);
		return 1;
	}
	
	printf("***		MATRIX		***\n");
	PrintMatrix(matrix);
	
	int err = TransformMatrix(matrix, result);
	
	printf("***		RESULT		***\n");
	PrintMatrix(result);
	
	DeleteMatrix(matrix);
	DeleteMatrix(result);
	
	return err;
}
