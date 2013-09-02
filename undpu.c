#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char compare_string[] = "DOUBLEPLUS UNZIP, FACTOR=";

int main (int argc, char **argv){
	FILE *bob, *joe;
	int factor, thing, i;
	char output[FILENAME_MAX];
	if(argc < 2){
		fputs("I pity the fool who don't have an input file!\n",stderr);
		return EXIT_FAILURE;
	}
	if(strlen(argv[1]) <= 4 || strcmp(argv[1] + strlen(argv[1]) - 4, ".dpu"))
	{
		fputs("Where's the rest of the filename?", stderr);
		return EXIT_FAILURE;
	}
	if((bob = fopen(argv[1],"r"))==NULL){
		fputs("That's no input file, THAT'S A SPACE STATION!\n",stderr);
		return EXIT_FAILURE;
	}
	for(i = 0; compare_string[i]; i++) {
		thing = fgetc(bob);
		if(thing != compare_string[i]) {
			fputs("You suck!  That's not a DPU file!\n", stderr);
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
