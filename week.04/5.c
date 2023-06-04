#include <stdio.h>

int main() {
	int arr[100][100];

	int n, m;

	scanf("%d %d", &n, &m);

	int x = 0, y = 0;
	int add_x = 0, add_y = 0;

	for (int i = 1; i <= n * m; i++) {

		arr[y + add_y++][x - add_x++] = i;
 
		if ((add_x > x || y + add_y == n)) {
			add_x = 0;
			add_y = 0;
			(x == m - 1) ? y++ : x++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

