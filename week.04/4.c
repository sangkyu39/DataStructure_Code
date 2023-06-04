#include <stdio.h>

int main() {
	int arr[100][100];

	int n, m;

	scanf("%d %d", &n, &m);

	int remN = n, remM = m;

	int x = 0, y = 0, flag = m + n - 2;

	for (int i = 1; i <= remN * remM; i++) {
		if (flag >= n) {
			arr[y][x++] = i;
		}
		else if (flag > 0) {
			arr[y++][x] = i;
		}
		else if (flag >= -(m - 2)) {
			arr[y][x--] = i;
		}
		else {
			arr[y--][x] = i;
		}
		flag--;

		if (flag == -(m + n - 2)) {
			m -= 2;
			n -= 2;
			flag = m + n - 2;
			x += 1;
			y += 1;
		}

	}

	for (int i = 0; i < remN; i++) {
		for (int j = 0; j < remM; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
		