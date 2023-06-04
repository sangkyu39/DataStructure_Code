#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int arr[50] = { 0 };
	int n = 0,a,b;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d %d", &a, &b);

	swap(&arr[a], &arr[b]);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	
	return 0;
}
