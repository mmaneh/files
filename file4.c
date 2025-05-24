#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	FILE* fptr = fopen("file.txt", "r");
	fseek(fptr, 0,SEEK_END);
        long int size = ftell(fptr);
	rewind(fptr);

	char* str = (char*)malloc(2*size*sizeof(char));
	fread(str, sizeof(char), 1, fptr);
	fread(str + 1, sizeof(char), 3, fptr);
	str[9] = '\0';

	printf("%s", str);
	

}
