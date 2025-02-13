#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "matrix.h"

int
main(void)
{
	Matrix* matrix = CreateMatrix();
	Matrix* result = (Matrix* ) malloc(sizeof(Matrix));
	result->numLines = matrix->numLines;
	result->lines = (Line* ) malloc(sizeof(Line) * matrix->numLines);
	PrintMatrix(matrix);
	for(int k = 0; k < matrix->numLines; k++){
		int numElems = 0;
		int mn = matrix->lines[k].elems[0];
		int mx = matrix->lines[k].elems[0];
		for(int i = 0; i < matrix->lines[k].numElems; i++){
			if(matrix->lines[k].elems[i] > mx)
				mx = matrix->lines[k].elems[i];
			if(matrix->lines[k].elems[i] < mn)
				mn = matrix->lines[k].elems[i];
		}
		int* table = (int*)calloc(sizeof(int)*(mx-mn+1),4);
		int ofs = -mn;
		for(int i = 0; i < matrix->lines[k].numElems; i++){
			(table[matrix->lines[k].elems[i]+ofs])++;
			if(table[matrix->lines[k].elems[i]+ofs] == 2)
				numElems++;  
		}
		result->lines[k].elems = (int* ) malloc(sizeof(int) * numElems);
		result->lines[k].numElems = numElems;
		for(int i = 0, j = 0; i < mx-mn+1; i++){
			if(table[i] >= 2){
				result->lines[k].elems[j++] = i - ofs;
			}
		}
		free(table);
		   
	}
	PrintMatrix(result);
	DeleteMatrix(result);
	DeleteMatrix(matrix);
	return 0;
}
