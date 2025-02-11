#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "options.h"

int
main(int argc, char **argv)
{
	Options opts = {0,0,0,0,0,0,0,0,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	
	int c;
	
	while((c = getopt(argc, argv, "hr:w:b:p:ts:")) != -1){
		switch(c){
		case 'h':
			opts.hflag = 1;
			break;
		case 't':
			opts.tflag = 1;
			break;
		case 'b':
			if(opts.bflag == 1){
				fprintf(stderr, "Option -b can be used only once.\n");
				return 1;
			}
			opts.bflag = 1;
			opts.bvalue = optarg;
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
		case 'r':
			if(opts.rflag == 1){
				fprintf(stderr, "Option -r can be used only once.\n");
				return 1;
			}
			opts.rflag = 1;
			opts.rvalue = optarg;
			break;	
		case 'w':
			if(opts.wflag == 1){
				fprintf(stderr, "Option -w can be used only once.\n");
				return 1;
			}
			opts.wflag = 1;
			opts.wvalue = optarg;
			break;
		case '?':
			if(optopt == 'r' || optopt == 'w')
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
			else if( isprint(optopt) )
				fprintf(stderr, "Unknown option '-%c'.\n", optopt);
			else
				fprintf(stderr, "Unknown option character '\\x%x'.\n", optopt);
			return 1;
		default:
			abort();
		}	
	}
	OptionsHandler(&opts);
	return 0;
}
