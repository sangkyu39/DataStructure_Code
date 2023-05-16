#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int* data;
  int front;
  int rear;
  int size;
}QueueType;

void init (QueueType *Q, int q){
  Q->size = q;
  Q->data = (int *)calloc(Q->size, sizeof(int));
  Q->front = Q->rear = 0;
}

void print(QueueType *Q){
  for (int i = 0;i < Q->size;i++){
    printf(" %d",Q->data[i]);
  }
  printf("\n");
}

int isFull(QueueType *Q){
  return (Q->rear + 1) % (Q->size) == Q->front;
}

int isEmpty(QueueType *Q){
  return Q->rear == Q->front;
}

void enqueue(QueueType *Q, int elem){
  if (isFull(Q)) {
    printf("overflow\n");
    print(Q);
    exit(1);
  }
  else {
    Q->rear = (Q->rear + 1) % Q->size;
    Q->data[Q->rear] = elem;
  }
}

void dequeue(QueueType *Q){
  if (isEmpty(Q)){
    printf("underflow\n");
    exit(1);
  }
  else {
    Q->front = (Q->front + 1) % Q->size;
    Q->data[Q->front] = 0;
  }
}

int main(){
  int q, n, elem = 0;
  char cmd;
  scanf("%d\n%d",&q,&n);
  
  QueueType Q;
  init(&Q,q);
  
  for(int i = 0;i < n;i++){

    getchar();
    scanf("%c",&cmd);
    
    if (cmd == 'I'){
      scanf("%d",&elem);
      enqueue(&Q, elem);
    }
    else if(cmd == 'D'){
      dequeue(&Q);
    }
    else if(cmd == 'P'){
      print(&Q);
    }
  }
  return 0;
}
