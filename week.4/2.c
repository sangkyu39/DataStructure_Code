#include <stdio.h>
#include <stdlib.h>

int swap(int* arr, int* swap_arr, int num, int len) {
	if (len == 0) {
		return 0;
	}
	swap(arr, swap_arr + 1, arr[*swap_arr], len - 1);
	arr[*swap_arr] = num;
}
	


int main() {
	int arr[100];
	int arr_len, swap_cnt, swap_arr[100];

	scanf("%d", &arr_len);

	for (int i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &swap_cnt);

	for (int i = 0; i < swap_cnt; i++) {
		scanf("%d", &swap_arr[i]);
	}
	
	swap(arr, swap_arr, arr[swap_arr[swap_cnt - 2]], swap_cnt);

	for (int i = 0; i < arr_len; i++) {
		printf(" %d", arr[i]);
	}

	return 0;
}