#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return (a == 0) ? b : a;
	}
	//a 와 b 중 작은 값, 큰 값을 작은 값으로 나눈 나머지를 함수 호출
	return gcd((a < b) ? a : b, (a > b) ? a % b : b % a);
}


int main() {

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d", gcd(a, b));



	return 0;
}