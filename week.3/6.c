#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return (a == 0) ? b : a;
	}

	return gcd((a < b) ? a : b, (a > b) ? a % b : b % a);
}


int main() {

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d", gcd(a, b));



	return 0;
}