#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int h;
	int m;
	int s;
} time;

int main() {
	time fst, sec, res;

	scanf("%d %d %d", &(fst.h), &fst.m, &fst.s);
	scanf("%d %d %d", &(sec.h), &sec.m, &sec.s);

	if (sec.s < fst.s) {
		sec.s += 60;
		sec.m -= 1;
	}

	res.s = sec.s - fst.s;

	if (sec.m < fst.m) {
		sec.m += 60;
		sec.h -= 1;
	}

	res.m = sec.m - fst.m;

	res.h = sec.h - fst.h;

	printf("%0d %d %d", res.h, res.m, res.s);


	return 0;
}
