#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int find_max(int* arr, int len) {

	if (len == 0) {
		return arr[len];
	}

	int back_num = find_max(arr, len - 1);

	return (arr[len] > back_num) ? arr[len] : back_num;
}

int main() {
	int n, arr[20];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d", find_max(arr, n - 1));
	return 0;
}
