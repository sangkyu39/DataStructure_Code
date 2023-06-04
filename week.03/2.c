#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int high_digit(int n, int num_len) {

	printf("%d\n", n / num_len);
	
	if (num_len == 1) {
		return 0;
	}

	return high_digit(n % num_len, num_len / 10);
}

int main() {
	int n, num_len = 1;

	scanf("%d", &n);

	for (;;) {
		if (n / num_len == 0) {
			num_len /= 10;
			break;
		}
		num_len *= 10;
	}

	high_digit(n, num_len);

	return 0;
}

	