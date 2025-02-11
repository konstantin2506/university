#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sorts.h"
#include "arrays.h"
#include "options.h"

int Test(Options* opts);
char* RandomWord(void);
char* RandomString(void);

int
main(int argc, char **argv)
{
	Options opts = {0,0,0,0,0,0,0,0,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	
	int c;
	
	while((c = getopt(argc, argv, "a:e:p:ts:")) != -1){
		switch(c){
		case 't':
			opts.tflag = 1;
			break;
		case 's':
			if(opts.sflag == 1){
				fprintf(stderr, "Option -s can be used only once.\n");
				return 1;
			}
			opts.sflag = 1;
			opts.svalue = optarg;
			break;	
		case 'p':
			if(opts.pflag == 1){
				fprintf(stderr, "Option -p can be used only once.\n");
				return 1;
			}
			opts.pflag = 1;
			opts.pvalue = optarg;
			break;	
		case 'a':
			if(opts.aflag == 1){
				fprintf(stderr, "Option -a can be used only once.\n");
				return 1;
			}
			opts.aflag = 1;
			opts.arrnum = optarg;
			break;	
		case 'e':
			if(opts.eflag == 1){
				fprintf(stderr, "Option -e can be used only once.\n");
				return 1;
			}
			opts.eflag = 1;
			opts.elemnum = optarg;
			break;		
		case '?':
			
			if( isprint(optopt) )
				fprintf(stderr, "Unknown option '-%c'.\n", optopt);
			else
				fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
			return 1;
		default:
			abort();
		}	
	}
	Test(&opts);
	return 0;
}



int 
Test(Options* opts)
{
	srand(time(NULL));
	int accent;
	char* meaning;
	char* word;
	Dict vec;
	int arrNum = atoi(opts->arrnum);
	int elemNum = atoi(opts->elemnum);
	
	double fullTime = 0;
	for(int k = 0; k < arrNum; k++){
		vec = CreateVector(10);
		for(int j = 0; j < elemNum; j++){
			word = RandomWord();
			meaning = RandomString();
			accent = rand() % 1000 + 1;
			Append(&vec, word, accent, meaning);
			free(word);
			free(meaning);
		}
		
		double time, start, finish;
		start = clock();
		Sort(&vec, opts);
		finish = clock();
		time = (finish - start)*1000000 / CLOCKS_PER_SEC; // time in mcs;
		fullTime += time;
		DeleteVector(&vec);
	}
	double avrTime = fullTime / arrNum;
	printf("num of elems = %d, avrTime = %.0lf microseconds\n", elemNum, avrTime); 

	return 0;
}
char* 
RandomWord(void)
{
	char* word = (char*)malloc(20 * sizeof(char));
	for(int i = 0; i < 20; i++){
		word[i] = 'a' + rand() % 26;
	}
	word[19] = '\0';
	return word;
}
char* 
RandomString(void)
{
	char* str = (char*)malloc(100 * sizeof(char));
	for(int i = 0; i < 20; i++){
		str[i] = rand() % 128;
	}
	str[99] = '\0';
	return str;
}
