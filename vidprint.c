#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp;
	int c;

	if(argc != 2){
		perror("Must pass a number\n");
		return(-1);
	}

	fp = fopen("in.mp4", "r");
	if(fp == NULL){
		perror("Error when opening file\n");
		return(-1);
	}
	printf("File opened\n");
	for(int i = 0; i < 1024*1024*atof(argv[1]); i++){
		c = fgetc(fp);

		if(feof(fp)){
			break;
		}

		printf("%.2X ",c);
	}
	fclose(fp);
	printf("\nFile closed.\n");
	return(0);
}
