#include <stdio.h>

int main() {
	int n = 0;
	printf("Enter n: ");
	scanf("%d", &n);

	FILE* fptr = fopen("factorial.txt", "w");
	if (!fptr) return 1;

	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= i;
		fprintf(fptr,"%d",res);
		fprintf(fptr, ",");
	}
	fclose(fptr);
}
