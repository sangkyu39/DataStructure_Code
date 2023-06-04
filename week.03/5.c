#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int hanoi(int n, int loc, int move) {
	char tower[3] = {'A','B','C'};
	//맨 위의 층인 경우
	if (n == 1) {
		printf("%c %c\n", tower[loc], tower[move]);
	}
	else {
		hanoi(n - 1, loc, 3 - loc - move);
		printf("%c %c\n", tower[loc], tower[move]);
		hanoi(n - 1, 3 - loc - move, move);
	}
}

int main() {
	int disk = 0;

	scanf("%d", &disk);

	hanoi(disk, 0, 2);

	return 0;
}
