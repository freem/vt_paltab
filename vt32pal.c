#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *outFile;
	int i = 0;
	int RV, GV, BV;

	if(argc == 1){
		printf("%s - ",argv[0]);
#ifdef _BLUECASTREMOVAL
		printf("generate VT32 4bpp palette (with blue cast removal)\n");
#else
		printf("generate VT32 4bpp palette\n");
#endif
		printf("usage: %s outfile\n",argv[0]);
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

	for(i = 0; i < 4096; i++){
		RV = i & 0x0F;

		/* blue cast removal */
#ifdef _BLUECASTREMOVAL
		RV = (RV * 0x0F) / 0x0D;
		if (RV > 0x0F){
			RV = 0x0F;
		}
#endif
		/* end blue cast removal */

		GV = (i >> 4) & 0x0F;
		BV = (i >> 8) & 0x0F;

		RV = (RV * 0xFF) / 0x0F;
		GV = (GV * 0xFF) / 0x0F;
		BV = (BV * 0xFF) / 0x0F;
		fputc((char)RV,outFile);
		fputc((char)GV,outFile);
		fputc((char)BV,outFile);
	}

	fclose(outFile);

	exit(EXIT_SUCCESS);
}
