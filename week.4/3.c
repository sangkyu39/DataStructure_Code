#include <stdio.h>

int main() {
	int arr[100][100];
	int n;

	scanf("%d", &n);

	int x = 0, y = 0, flag = 1;

	for (int i = 1; i <= n * n; i++) {
		if (flag == 1) {
			arr[y][x++] = i;

		}
		else {
			arr[y][x--] = i;
		}
		if (i % n == 0) {
			flag *= -1;
			y++;
			x = (x == n) ? x - 1 : 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
		

