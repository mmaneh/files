#include <stdio.h>
int main() {
	FILE* fp = fopen("file.txt", "w");
	if(!fp) return 1;
	
	fputs("Hello World!", fp);
	fclose(fp);
}
