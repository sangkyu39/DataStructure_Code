#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define N 101

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

void calculate (char *expr){
  Stack s;
  init(&s); 
  int front = 0, back = 0;
  char c, t;
  int n = strlen(expr);
  
  for (int i = 0;i < n;i++){
    c = expr[i];
    switch(c){
      case '+' : 
        back = pop(&s);
        front = pop (&s);
        push(&s, front + back);
        break;
      case '-' : 
        back = pop(&s);
        front = pop (&s);
        push(&s, front - back);
        break;
      case '*' : 
        back = pop(&s);
        front = pop (&s);
        push(&s, front * back);
        break;
      case '/' :
        back = pop(&s);
        front = pop (&s);
        push(&s, front / back);
        break;
      default: 
        push(&s,atoi(&c));
        break;
    }
  }
  printf("%d\n",pop(&s));
}

int main(){
  char expr[N];
  int cnt = 0;

  scanf("%d",&cnt);

  for (int i = 0;i < cnt;i++){
  scanf("%s",expr);
  calculate(expr);
  }

  return 0;   
}
