#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int low_digit(int n) {

	printf("%d\n", n % 10);

	if (n / 10 == 0) {
		return 0;
	}

	return low_digit(n / 10);
}

int main() {
	int n;

	scanf("%d", &n);

	low_digit(n);

	return 0;
}

	