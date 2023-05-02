#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct {
	element *data;
	int top;
  int N;
}StackType;

void init(StackType *S, int N) {
  S->data = (char *)calloc(N, sizeof(char));
  S->N = N;
	S->top = -1;
}

int isEmpty(StackType *S) {
	return S->top == -1;
}

int isFull(StackType *S) {
	return S->top == S->N - 1;
}

void push(StackType *S, element e) {
	if(isFull(S)){
		printf("Stack FULL\n");
	}
	else {
		S->top++;
		S->data[S->top] = e;
	}
}

element pop(StackType *S) {
	if(isEmpty(S)){
		printf("Stack Empty\n");
		return -1;
	}
	
	element e = S->data[S->top];
	S->top--;
	return e;
}

element peek(StackType *S) {
	if(isEmpty(S)){
		printf("Stack Empty\n");
		return -1;
	}
	
	return S->data[S->top];
}

void duplicate(StackType* S) {
	element temp = pop(S);

  push(S, temp);
  push(S, temp);
}

void upRotate(StackType* S, int n) {
	int t = S->top;
	if (n <= t + 1) {
		element temp = S->data[t];
		for (int i = 1; i < n; i++) {
			S->data[t] = S->data[t - 1];
			t--;
		}
		S->data[t] = temp;
	}
}

void downRotate(StackType* S, int n) {
	int t = S->top;

	if (n <= t + 1) {
		element temp = S->data[t - n + 1];
		for (int i = t - n + 1; i < t; i++) {
			S->data[i] = S->data[i + 1];
		}
		S->data[t] = temp;
	}
}

void print(StackType *S){
	for (int i = S->top;i >= 0;i--){
		printf("%c",S->data[i]);
	}
	printf("\n");
}

int main() {
	StackType S;
  int N, cnt = 0;
  char cmd[10];
  
  scanf("%d",&N);
	init(&S, N);
  scanf("%d", &cnt);

  for (int i = 0;i < cnt;i++) { 
    scanf("%s", cmd);
    if (strcmp(cmd,"POP") == 0) {
      pop(&S);
    }
    else if (strcmp(cmd, "PUSH") == 0) {
      char e;
      getchar();
      scanf("%c", &e);
      push(&S, e);
    }
    else if (strcmp(cmd, "PEEK") == 0) {
      char elem = peek(&S);
      if (elem != -1) {
        printf("%c", elem);
      }
    }
    else if (strcmp(cmd, "DUP") == 0) {
      duplicate(&S);
    }
    else if (strcmp(cmd, "UpR") == 0) {
      int n;
      scanf("%d", &n);
      upRotate(&S, n);
    }
    else if (strcmp(cmd, "DownR") == 0) {
      int n;
      scanf("%d", &n);
      downRotate(&S, n);
    }
    else if (strcmp(cmd, "PRINT") == 0 ) {
      print(&S);
    }
  }
	
	return 0;
}