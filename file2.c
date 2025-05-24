#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	FILE* fptr = fopen("file.txt", "r");
	if (!fptr) return 1;

	fseek(fptr, 0, SEEK_END);
	long int size = ftell(fptr);
	rewind(fptr);

	char* str = (char*)malloc((size + 1) * sizeof(char));
	if(!str) return 1;

	fread(str, sizeof(char), 5, fptr);
	str[6] = '\0';
	fclose(fptr);

	int i = 0;
	while(str[i] != '\0') {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
		++i;
	}	

	fptr = fopen("file.txt", "w");
	fputs(str, fptr);
	fclose(fptr);
	free(str);
}
