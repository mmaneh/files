#include <stdio.h>
int main() {
	FILE* fptr = fopen("file.txt", "r");
	fseek(fptr, 0, SEEK_END);
	long int size = ftell(fptr);
	rewind(fptr);

	int word = 0;
	int count = 0;
	char current = fgetc(fptr);
	while(current != EOF) {
		if(current == '\n'){
                        ++count;
                }

		if(current == ' ' || current == '\n'){
			++word;
			while(fgetc(fptr) == ' '){
				current = fgetc(fptr);
			}
		}	
		
		current = fgetc(fptr);
	}

	printf("size of file - %ld\n lines - %d\n  words - %d", size, count, word);
	fclose(fptr);



}
