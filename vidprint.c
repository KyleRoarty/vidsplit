#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *fp;
	int c;
	char cstr[17];
	memset(cstr, 0, sizeof(cstr));
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

		printf("%.2X",c);
		cstr[i % 15] = c;

		if(i % 16 == 15){
			printf("        ");
			for(int j = 0; j < 17; j++){
				printf("%c", cstr[j]);
			}
			memset(cstr, 0, sizeof(cstr));
			printf("\n");
		} else if(i % 4 == 3) {
			printf("    ");
		} else {
			printf(" ");
		}
	}
	fclose(fp);
	printf("\nFile closed.\n");
	return(0);
}
