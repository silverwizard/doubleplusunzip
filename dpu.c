#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv){
	char name[FILENAME_MAX];
	FILE *bob,*joe,*moe;
	int thing, factor, arg;
	if(argc >= 3){
		char *end_char;
		factor = strtol(argv[1], &end_char, 0);
		if(!*(argv[1]) || *end_char)
		{
			fputs("I can haz number?\n", stderr);
			return EXIT_FAILURE;
		}
		arg = 2;
	}else{
		factor = 9;
		arg = 1;
	}
	if(argc<2){
		fputs("I pity the fool who don't have an input file!\n",stderr);
		return EXIT_FAILURE;
	}
	if(strlen(argv[arg]) >= FILENAME_MAX)
	{
		fputs("It's a filename, not a novel.\n", stderr);
		return EXIT_FAILURE;
	}
	strcpy(name,argv[arg]);
	strcat(name,".dpu");	
	if((bob = fopen(argv[arg],"r"))==NULL){
		fputs("NO YOU FOOL, A REAL ONE!\n",stderr);
		return EXIT_FAILURE;
	}
	if((joe = fopen(name,"w"))==NULL){
		fputs("Ummm, you seem to have an unwritable file or directory or something silly called the output file, this is dumb. Please stop.\n",stderr);
		return EXIT_FAILURE;
	} 
	if((moe = fopen("/dev/urandom","r"))==NULL){
		fputs("So, you aren't random enough. Annoying.\n",stderr);
		return EXIT_FAILURE;
	}
	fprintf(joe,"DOUBLEPLUS UNZIP, FACTOR=%d;",factor);
	while((thing=fgetc(bob))!=EOF){
		int i;
		if((fputc(thing,joe))==EOF){
			perror("fputc(thing,joe)");
			fputs("problematic\n",stderr);
			return EXIT_FAILURE;
		}
		for(i=0;i<factor;i++){
			thing=fgetc(moe);
			fputc(thing,joe);
		}
	}
	return 0;
}
