#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "hashtable.h"
#include "input.h"


Matrix* 
CreateMatrix(void)
{
	int numLines = 0;
	int err = 0;
	err = GetNumber("Enter number of lines: ", &numLines, NOT_IN_LOOP, SIGNED);
	
	if(err == ERROR_EOF)
		return NULL;
	Matrix* matrix = (Matrix* ) malloc(sizeof(Matrix));
	if(matrix == NULL){
		fprintf(stderr, "Fatal: MATRIX memory was not allocated\n");
		return NULL;
	}
	matrix->numLines = numLines;
	matrix->lines = (Line* ) calloc(sizeof(Line) * numLines, sizeof(Line));						//////////
	if(matrix->lines == NULL){
		fprintf(stderr, "Fatal: LINES memory was not allocated\n");
		DeleteMatrix(matrix);
		return NULL;
	}
	for(int i = 0; i < numLines; i++){
		int numElems = 0;
		matrix->lines[i].numElems = 0;
		err = GetNumber("Enter number of elements in line", &numElems, i+1, SIGNED);
		
		matrix->lines[i].numElems = numElems;
		matrix->lines[i].elems = (int* ) malloc(sizeof(int) * numElems);
		if(matrix->lines[i].elems == NULL){
			fprintf(stderr, "Fatal: LINE[%d] memory was not alocated\n", i);
			DeleteMatrix(matrix);
			return NULL;
		}
		if(err == ERROR_EOF){
			DeleteMatrix(matrix);
			return NULL;
		}
		
		for(int j = 0; j < numElems; j++){
			int elem;
			err = GetNumber("Enter elems", &elem, j+1, UNSIGNED);
			if(err == ERROR_EOF){
				DeleteMatrix(matrix);
				return NULL;
			}
			
			matrix->lines[i].elems[j] = elem;
		}	
	}	
	return matrix;
}
int 
TransformMatrix(const Matrix* matrix, Matrix* result)
{
	for(int i = 0; i < matrix->numLines; i++){
		HashTable* htable = HTCreate(TABLE_SIZE);
		if(htable == NULL){
			fprintf(stderr, "error: null htable");
			DeleteMatrix(result);
			return 1;
		}
		result->lines[i].numElems = 0;
		for(int j = 0; j < matrix->lines[i].numElems; j++){
			int resFind = 0;
			int err = 0;
			int key = matrix->lines[i].elems[j];
			HTFind(htable, key, &resFind);
			if(resFind == 1){
				(result->lines[i].numElems)++;
			}
			err = HTSmartInsert(&htable, key, resFind + 1);
			if(err != 0){
				fprintf(stderr, "error: insert in htable\ncode: %d", err);
				HTDelete(htable);
				DeleteMatrix(result);
				return 1;
			}
		}
		result->lines[i].elems = (int* ) malloc(sizeof(int) * result->lines[i].numElems);
		if(result->lines[i].elems == NULL){
			fprintf(stderr, "error: null result->lines[%d].elems", i);
		}
		int k = 0;
		ListNode* ptr = htable->list->first;
		while((k < result->lines[i].numElems) && (ptr != NULL)){
			if(ptr->item->value >= 2){
				result->lines[i].elems[k] = ptr->item->key;
				k++;
			}
			ptr = ptr->next;
		}
		HTDelete(htable);
	}
	return 0;
}
void 
PrintMatrix(Matrix* matrix)
{
	if(matrix == NULL){
		fprintf(stderr,"Error: null-matrix\n");
		return;
	}
	printf("numLines = %d\n", matrix->numLines);
	for(int i = 0; i < matrix->numLines; i++){
		printf("Line[%d]: ", i+1);
		for(int j = 0; j < matrix->lines[i].numElems; j++){
			printf("%d ", matrix->lines[i].elems[j]);
		}
		printf("\n");
	}
}

void
DeleteMatrix(Matrix* matrix)
{
	if(matrix == NULL)
		return;
	if(matrix->lines != NULL){	
		for(int i = 0; i < matrix->numLines; i++){
			if(matrix->lines[i].elems != NULL)
				free(matrix->lines[i].elems);
		}
		free(matrix->lines);
	}
	free(matrix);
}
