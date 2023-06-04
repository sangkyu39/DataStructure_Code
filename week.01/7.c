#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int n;

	scanf("%d", &n);

	int* arr1 = (int*)calloc(n, sizeof(int));
	int* arr2 = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr2[i]);
	}
	for (int i = 0; i < n; i++) {
		printf(" %d", arr1[i] + arr2[n - 1 - i]);
	}

	return 0;
}
