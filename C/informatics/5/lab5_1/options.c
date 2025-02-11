#include "arrays.h"
#include "options.h"
#include "mstring.h"
#include "sorts.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void
Help(void)
{
	printf("Help:\nFlags:\n \
	'-h' help\n\
	'-r' (read data from file)\n\
	\t ./a -r ./input.txt (read data from input.txt)\n\
	'w' (write data to the end of file)\n\
	\t ./a -w ./output.txt (write data to output.txt)\n\
	If '-w' parameter requires - data will be written to stdout.\n\
	If '-r' parameter requires - data will be taken from stdin.\n\
	'-b' (binary read and write [rw])\n\
	\t ./a -r input.txt -w output.txt -b 01 [read in txt, write in binary]\n\
	Examples:\n\
	\t ./a -r input.txt -w output.txt (reads from input.txt and writes to output.txt)\n\
	\t ./a -w output.txt -b 01 (user writes data (in txt) to stdin and then writes to output.txt (in binary))\n\
	Last example will not work if -b 11 (incorrect input)\n\
	'-s' sorting algorithm:\n\
	\t -b - bubble sort\n\
	\t -q - quick sort\n\
	\t -i - insertion sort \n\
	'-t' - parameter to for reversive sort\n\
	'-p' - sorting pole (1,2,3) --> (word, accent, meaning)\n");
}
int
IsBinary(char* permissions, char c)
{
	int res;
	if(permissions == NULL)
		return 0;
	if(strlen(permissions) != 2){
		fprintf(stderr, "incorrect input in -b option\n");
		return -1;
	}
	switch(c){
	case 'r':
		res = permissions[0] - '0';
		if (res == 0 || res == 1)
			return res;
		fprintf(stderr, "incorrect permissions (must be 0 or 1)");
		return -3;
	case 'w':
		res = permissions[1] - '0';
		if (res == 0 || res == 1)
			return res;
		fprintf(stderr, "incorrect permissions (must be 0 or 1)");
		return -3;
	default:
		fprintf(stderr, "unknown parameter in IsBinary\n");
		return -4;
	}	
}

int
OptionsHandler(Options* opts)
{
// INITIALIZATON

	char* outputfile = NULL;
	char* inputfile = NULL;
	
	int wbinary = IsBinary(opts->bvalue, 'w');
	int rbinary = IsBinary(opts->bvalue, 'r');
	if (rbinary < 0 || wbinary < 0)
		return 1;
	if(opts->hflag == 1){
		Help();
		return 0;
	}
	FILE* fin;
	FILE* fout;
	Dict vec = CreateVector(10);
	
// READING FROM FILE		
		
	inputfile = opts->rvalue;
	if(rbinary){
		if(inputfile == NULL)
			fin = stdin;
		else
			fin = fopen(inputfile, "rb");
		if(fin == NULL){
			fclose(fin);
			return 1;
		}
		int c, size;
		
		while((c = (fread(&size, sizeof(int), 1, fin))) > 0){
			char* meaning = (char*)calloc(size, 1);
			char* word = (char*)calloc(20, 1);
			int accent;
			fread(word, 20*sizeof(char), 1, fin);
			fread(&accent, sizeof(int), 1, fin);
			fread(meaning, size, 1, fin);
			Append(&vec, word, accent, meaning);
			free(word);
			free(meaning);
		}
		fclose(fin);
	}
	else{
		
		if(inputfile == NULL)
			fin = stdin;
		else
			fin = fopen(inputfile, "r");
		if(fin == NULL){
			fclose(fin);
			return 1;
		}
		char word[40] = {0};
		int accent;
		char* meaning = NULL;

		while(!feof(fin)){
			int c = 0;
			if(fin == stdin){
				printf("entry:\n");
				printf("word: ");
				scanf("%s", word);
				getc(fin);
				printf("accent: ");
				c += scanf("%d", &accent);
				getc(fin);
				printf("meaning: ");
				meaning = GetLine(fin);
			}
			else{
				fscanf(fin, "%s", word);
				getc(fin);
				c += fscanf(fin, "%d", &accent);
				getc(fin);
				meaning = GetLine(fin);
			}
			if(strlen(word) <= 19)
				c++;
			if(feof(fin))
				break;
			if (c != 2){
				fprintf(stderr, "incorrect input\n");
				free(meaning);
				continue;
			}
			Append(&vec, word, accent, meaning);
			free(meaning);
		}
		free(meaning);
		fclose(fin);
	}

//SORTING 
	if(opts->svalue != NULL){
		int err = Sort(&vec,opts);
		if(err == 0){
			printf("After sort:\n");
			PrintVec(&vec);
		}
	}
		
	
//WRITING TO FILE
	outputfile = opts->wvalue;
	if(wbinary){
		if(outputfile == NULL)
			fout = stdout;
		else
			fout = fopen(outputfile, "ab");
		if(fout == NULL){
			fclose(fout);
			return 1;
		}
		for(int i = 0; i < vec.len; i++){
			int size = strlen(vec.base[i].meaning) + 1;
			fwrite(&size, sizeof(size), 1, fout);
			fwrite(vec.base[i].word, 20, 1, fout);
			fwrite(&vec.base[i].accent, sizeof(int), 1, fout);
			fwrite(vec.base[i].meaning, size, 1, fout);
		}
		fclose(fout);
	}
	else{
		if(outputfile == NULL)
			fout = stdout;
		else
			fout = fopen(outputfile, "a");
		if(fout == NULL){
			fclose(fout);
			return 1;
		}
		for(int i = 0; i < vec.len; i++)
			fprintf(fout, "%s %d %s\n", vec.base[i].word, vec.base[i].accent, vec.base[i].meaning);
		fclose(fout);		
	}

	DeleteVector(&vec);
	return 0;
}

