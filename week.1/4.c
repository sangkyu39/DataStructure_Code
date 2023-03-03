#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char word[101];
	scanf("%s", word);
	int len = strlen(word);
    
	for (int i = 0; i < len; i++) {
		printf("%s\n", word);
		char first = word[0];
		for (int j = 1; j < len; j++) {
			word[j - 1] = word[j];
		}
		word[len - 1] = first;
	}

	
	return 0;
}
