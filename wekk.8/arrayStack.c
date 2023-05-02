#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef char element;

typedef struct {
   element data[N];
   int top;
}StackType;

void init(StackType *S) {
   S->top = -1;
}

int isEmpty(StackType *S) {
   return S->top == -1;
}

int isFull(StackType *S) {
   return S->top == N-1;
}

void push(StackType *S, element e) {
   if(isFull(S)){
      printf("Stack is Full.\n");
   }
   else {
      S->top++;
      S->data[S->top] = e;
   }
}

element pop(StackType *S) {
   if(isEmpty(S)){
      printf("Stack is Empty.\n");
      return -1;
   }
   
   element e = S->data[S->top];
   S->top--;
   return e;
}

element peek(StackType *S) {
   if(isEmpty(S)){
      printf("Stack is Empty.\n");
      return -1;
   }
   
   return S->data[S->top];
}

void duplicate(StackType* S) {
   element temp = peek(S);

   if (temp != -1) {
      push(S, temp);
   }
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
      printf("%c ",S->data[i]);
   }
   printf("\n");
}

int main() {
   StackType S;
   init(&S);
   
   pop(&S);
   push(&S, 's');
   push(&S, 't');
   push(&S, 'a');
   push(&S, 'r');
   
   print(&S);

   printf("%c\n",pop(&S));print(&S);
   printf("%c\n",peek(&S));print(&S);
   
   return 0;
}