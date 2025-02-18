#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"
#include "matrix.h"

#define TABLE_SIZE 128

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
	for(int i = 0; i < matrix->numLines; i++){
		HashTable* htable = HTCreate(TABLE_SIZE);
		if(htable == NULL){
			fprintf(stderr, "error: null htable");
			DeleteMatrix(matrix);
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
				DeleteMatrix(matrix);
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
	printf("***		RESULT		***\n");
	PrintMatrix(result);
	DeleteMatrix(matrix);
	DeleteMatrix(result);
	return 0;
}
