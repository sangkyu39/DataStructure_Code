#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char element;

typedef struct QueueNode {
	element data;
	struct QueueNode *next;
} QueueNode;

typedef struct {
	QueueNode* front, * rear;
} QueueType;

QueueNode* getNode() {
	return (QueueNode*)calloc(1, sizeof(QueueNode));
}

void init(QueueType* D) {
	D->front = D->rear = NULL;
}

int isEmpty(QueueType* Q) {
	return Q->front == NULL;
}

void enqueue(QueueType *Q, element e){
  QueueNode *node = getNode();
  node->data = e;
  node->next = NULL;

  if(isEmpty(Q)){
    Q->front = Q->rear = node;
  }
  else {
    Q->rear->next = node;
    Q->rear = node;
  }
}

element dequeue (QueueType *Q){
  if (isEmpty(Q)){
    printf("Empty.\n");
    return 0;
  }

  QueueNode *p = Q->front;
  element e = p->data;
  Q->front = p->next;

  if(Q->front == NULL){
    Q->rear = NULL;
  }

  free(p);
  return e;
}

element peek(QueueType *Q){
  if(isEmpty(Q)){
    printf("Empty.\n");
    return 0;
  }

  return Q->front->data;
}

void print(QueueType *Q){
  QueueNode *p;
  for (p = Q->front; p != NULL; p = p->next){
    printf("[%c] => ",p->data);
  }
  printf("NULL\n");
}

int main() {
	QueueType Q;
  init(&Q);

  enqueue(&Q, 'A');
  enqueue(&Q, 'B');
  enqueue(&Q, 'X');
  print(&Q);

  printf("Dequeue : [%c]\n",   dequeue(&Q));
  print(&Q);
  printf("Peek : [%c]\n", peek(&Q));
  print(&Q);
  return 0;
} 