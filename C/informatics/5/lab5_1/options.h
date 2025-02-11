#ifndef OPTIONS_H
#define OPTIONS_H

typedef struct Options{
	int hflag;
	int wflag;
	int rflag;
	int bflag;
	int pflag;
	int tflag;
	int sflag;
	int aflag;
	int eflag;
	
	char* rvalue;
	char* wvalue;
	char* bvalue;
	char* pvalue;
	char* svalue;
	char* arrnum;
	char* elemnum;

}Options;

int OptionsHandler(Options* opts);
#endif
