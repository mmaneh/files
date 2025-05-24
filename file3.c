#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main() {

	FILE* fptr = fopen("file.txt", "r");
	if (!fptr) return 1;

	fseek(fptr, 0, SEEK_END);
	long int size = ftell(fptr);
	rewind(fptr);

	char* str = (char*)malloc((size + 1) * sizeof(char));
	if(!str) return 1;

	fread(str, sizeof(char), size, fptr);
	str[size + 1] = '\0';
	fclose(fptr);

	int i = 0;
	int count = 0;
	while(str[i] != '\0') {
		if(isdigit(str[i])) {
			++count;
		}
		++i;
	}	
	printf("the count is %d", count);
	free(str);
}
