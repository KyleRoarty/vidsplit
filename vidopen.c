#include <stdio.h>

int main(){
	FILE *fp, *of;
	int c;
	fp = fopen("in.mp4", "r");
	of = fopen("tmp.mp4", "w");
	if(fp == NULL){
		perror("Error when opening file\n");
		return(-1);
	}
	printf("File opened\n");
	for(int i = 0; i < 1024*1024*600; i++){
		c = fgetc(fp);

		if(feof(fp)){
			break;
		}
		fputc(c, of);
	}

//	for(int i = 0; i < 1024*1024*511; i++){
//		c = fgetc(fp);
//	}
//
//	for(int i = 0; i < 1024*1024*10; i++){
//		c = fgetc(fp);
//
//		if(feof(fp)){
//			break;
//		}
//
//		fputc(c, of);
//	}

	fclose(of);
	fclose(fp);
	printf("\nFile closed.\n");
	return(0);
}
