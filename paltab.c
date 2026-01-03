#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *inFile;
	FILE *outFile;
	int curVal = 0;
	int i = 0;

	if(argc == 1){
		printf("%s - convert EmuVT/PIC32VT color table files\n",argv[0]);
		printf("usage: %s infile outfile\n",argv[0]);
		exit(EXIT_SUCCESS);
	}

	if(argc > 3){
		printf("Error: Too many arguments\n");
		exit(EXIT_FAILURE);
	}

	inFile = fopen(argv[1],"rb");
	if(inFile == NULL){
		perror("Unable to open input file");
		exit(EXIT_FAILURE);
	}

	outFile = fopen(argv[2],"wb");
	if(outFile == NULL){
		perror("Unable to open input file");
		exit(EXIT_FAILURE);
	}

	do{
		curVal = fgetc(inFile);
		if(curVal != EOF){
			if(++i % 4 != 0){
				fputc(curVal,outFile);
			}
		}
	}while(curVal != EOF);

	fclose(inFile);
	fclose(outFile);

	exit(EXIT_SUCCESS);
}
