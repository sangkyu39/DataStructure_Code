#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[8];
	int kor;
	int eng;
	int math;
	double avg;
}student;
int main() {
	student* students;

	int n;

	scanf("%d", &n);

	students = (student*)calloc(n, sizeof(student));

	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].math);
		students[i].avg = students[i].kor + students[i].eng + students[i].math;
		students[i].avg /= 3;
	}

	for (int i = 0; i < n; i++) {
		printf("%s %.1lf ", students[i].name, students[i].avg);
		if (students[i].kor >= 90 || students[i].eng >= 90 || students[i].math >= 90) {
			printf(" GREAT");
		}
		if (students[i].kor < 70 || students[i].eng < 70 || students[i].math < 70) {
			printf(" BAD");
		}
		printf("\n");
	}
	return 0;
	}
