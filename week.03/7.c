#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_engs(char* engs, char base_eng) {
	
	if (*engs == '\0') {
		return 0;
	}
	//목표 글자와 같은 경우 1을 더한 후 다음 글자 확인 
	return ((*engs == base_eng) ? 1 : 0) + check_engs(engs + 1, base_eng);
}

int main() {
	char engs[101], base_eng;

	scanf("%s", engs);
	getchar();
	scanf("%c", &base_eng);

	printf("%d", check_engs(engs, base_eng));

	return 0;
}