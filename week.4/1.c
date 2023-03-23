#include <stdio.h>

void swap_arr(int* arr, int first, int last) {
	while (first < last) {
		int tmp = arr[first];
		arr[first++] = arr[last];
		arr[last--] = tmp;
	}
}

int main() {
	int arr[100];
	int arr_len;
	int swap_cnt, swap_first, swap_last;

	scanf("%d", &arr_len);

	for (int i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &swap_cnt);

	for (int i = 0; i < swap_cnt; i++) {
		scanf("%d %d", &swap_first, &swap_last);
		swap_arr(arr, swap_first, swap_last);
	}

	for (int i = 0; i < arr_len; i++) {
		printf(" %d", arr[i]);
	}

	return 0;
}