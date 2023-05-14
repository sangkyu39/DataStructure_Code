#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101

typedef struct StackNode {
  char operator;
  int prec;
  struct StackNode *next;
}StackNode;

typedef struct {
  StackNode *top;
  int size;
} StackType;

void init (StackType *s){
  s->top = NULL;
  s->size = 0;
}

int isEmpty (StackType *s){
  return s->top == NULL;
}

StackNode* getNode () {
  return (StackNode*)calloc(1, sizeof(StackNode));
}

void push (StackType *s, char data, int p){
  StackNode *node = getNode();
  
  node->operator = data;
  node->prec = p;

  node ->next = s->top;
  s->top = node;
  s->size++;
}

int peekPrec (StackType *s){
	if (isEmpty(s)){
    printf("Stack is Empty\n");
    return 0;
  }
  else {
    return s->top->prec;
  }
}
char peek (StackType *s){
  if (isEmpty(s)){
    printf("Stack is Empty\n");
    return 0;
  }
  else {
    return s->top->operator;
  }
}

char pop(StackType *s){
  if (isEmpty(s)){
    printf("Stack is Empty\n");
  }
  else {
	char data = s->top->operator;
	s->top = s->top->next;
    return data;
  }
}

int prec(char op) {
	switch (op) {
	case '(': case ')':
		return 0;
	case '|':
		return 1;
	case '&':
		return 2;
	case '<': case '>':
		return 3;
	case '+': case '-':
		return 4;
	case '*': case '/':
		return 5;
	case '!':
		return 6;
	default :
		return -1;
	}
}

void convert(char* expr) {
	
	StackType s;
	init(&s);


	char c, t;
	int n = strlen(expr);

	for (int i = 0; i < n; i++) {
		c = expr[i];
		int p = prec(c);
		switch (c) {
		case '+': case '-': case '*': case '/': case '>': case '<': case '|': case '&': case '!':
			//앞에 숫자나 ( ) 를 제외한 기호가 나오는 경우 -> 단항 연산자
			if ((prec(expr[i - 1]) > 0 || i == 0) && (c == '+' || c == '-')){
				p = 6;
			}
			while (!isEmpty(&s) && (p <= peekPrec(&s))) {
				if (peek(&s) == '|' || peek(&s) == '&') {
					printf("%c", peek(&s));
				}
				printf("%c", pop(&s));
			}
			if (c == '|' || c == '&') {
				i++;
			}
			push(&s, c, p);
			break;

		case '(':
			push(&s, c, p);
			break;
		case ')':
			t = pop(&s);
			while (t != '(') {
				if (t == '|' || t == '&') {
					printf("%c", t);
				}
				printf("%c", t);
				t = pop(&s);
			}
			break;
		default:
			printf("%c", c);
			break;
		}
	}
	while (!isEmpty(&s)) {
		if (peek(&s) == '|' || peek(&s) == '&') {
			printf("%c", peek(&s));
		}
		printf("%c", pop(&s));
	}
	printf("\n");
}

int main() {
	int cnt;
	char expr[N];

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%s", expr);
		convert(expr);
	}

	return 0;
}