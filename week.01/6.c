#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	int score;
}student;

int main() {
	student students[5];
	int avg = 0;
	for (int i = 0; i < 5; i++) {
		scanf("%s %d", students[i].name, &students[i].score);
		avg += students[i].score;
	}
	avg /= 5;

	for (int i = 0; i < 5; i++) {
		if (students[i].score <= avg) {
			printf("%s", students[i].name);
		}
	}



	return 0;
}
