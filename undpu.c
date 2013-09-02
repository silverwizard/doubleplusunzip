#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv){
	FILE *bob, *joe;
	int factor, thing;
	char output[FILENAME_MAX];
	if((bob = fopen(argv[1],"r"))==NULL){
		fputs("That's no input file, THAT'S A SPACE STATION!\n",stderr);
		return EXIT_FAILURE;
	}
	while(thing != '='){
		thing=fgetc(bob);
		if(thing==EOF){
			fputs("You suck!  That's not a DPU file!\n",stderr);
			return EXIT_FAILURE;
		}
	}
	factor=0;
	for(;;){
		thing=fgetc(bob);
		if(isdigit(thing)){
			factor=(factor*10)+(thing-'0');
		}else if(thing==';'){
			break;
		}else{
			fputs("You should make it work!\n",stderr);
			return EXIT_FAILURE;
		}
	}
	strncpy(output,argv[1],strlen(argv[1])-4);
	if((joe = fopen(output,"w"))==NULL){
		fputs("Ummm, the output file doesn't work.\n",stderr);
		return EXIT_FAILURE;
	}
	while((thing=fgetc(bob))!=EOF){
		fputc(thing,joe);
		int i;
		for(i=0;i<factor;i++){
			thing = fgetc(bob);
		}
	}
	return 0;
}
