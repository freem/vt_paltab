#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *outFile;
	int i = 0;
	int RV, GV, BV;

	if(argc == 1){
		printf("vt369pal - generate VT369 RGB555 palette\n");
		printf("usage: vt369pal outfile\n");
		exit(EXIT_SUCCESS);
	}

	if(argc > 2){
		printf("Error: Too many arguments\n");
		exit(EXIT_FAILURE);
	}

	outFile = fopen(argv[1],"wb");
	if(outFile == NULL){
		perror("Unable to open output file");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < 32768; i++){
		RV = (i >> 10) & 0x1F;
		GV = (i >>  5) & 0x1F;
		BV = (i >>  0) & 0x1F;

		RV = (RV * 0xFF) / 0x1F;
		GV = (GV * 0xFF) / 0x1F;
		BV = (BV * 0xFF) / 0x1F;
		fputc((char)RV,outFile);
		fputc((char)GV,outFile);
		fputc((char)BV,outFile);
	}

	fclose(outFile);

	exit(EXIT_SUCCESS);
}
