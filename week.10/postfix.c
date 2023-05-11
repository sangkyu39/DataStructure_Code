#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N 20

typedef struct {
  int elem[N];
  int top;
}Stack;

void init (Stack *s){
  s->top = -1;
}

int isEmpty (Stack *s){
  return s->top == -1;
}

int isFull(Stack *s){
  return s->top == N - 1;
}

void push (Stack *s, int data){
  if (isFull(s)){
    printf("Stack Overflow\n");
  }
  else {
    s->top++;
    s->elem[s->top] = data;
  }
}

int peek (Stack *s){
  if (isEmpty(s)){
    printf("Stack is Empty\n");
    return -1;
  }
  else {
    return s->elem[s->top];
  }
  
}
int pop(Stack *s){
  if (isEmpty(s)){
    printf("Stack is Empty\n");
    return -1;
  }
  else {
    return s->elem[s->top--];
  }
}

int prec(char op){
  switch(op){
    case '(' : case ')' :
      return 0;
    case '+' : case '-' :
      return 1;
    case '*' : case '/' :
      return 2;
  }
}

void convert (char *expr){
  Stack s;
  init(&s);

  char c, t;
  int n = strlen(expr);

  for (int i = 0;i < n;i++){
    c = expr[i];
    switch(c){
      case '+' : case '-' : case '*' : case '/' :
        while (!isEmpty(&s) && (prec(c) <= prec(peek(&s))))
          printf("%c",pop(&s));
        push(&s, c);
        break;
      case '(':
        push(&s, c);
        break;
      case ')':
        t = pop(&s);
        while (t != '('){
          printf("%c", t);
          t = pop(&s);
        }
      default: 
        printf("%c",c);
        break;
    }
  }
  while (!isEmpty(&s))
    printf("%c",pop(&s));
  printf("\n");
}

int main(){
  char expr[N];
  printf("Input Infix : ");
  scanf("%s",expr);

  printf("Postfix Output : ");
  convert(expr);

  return 0;   
}