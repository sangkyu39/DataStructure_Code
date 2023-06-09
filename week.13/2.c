#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
  int id;
	struct Node *left, *right;
} Node;

Node *makeNode(int data, Node *left, Node *right, int id) {
	Node *p = (Node *)calloc(1, sizeof(Node));

	p->data = data;
  	p->id = id;
	p->left = left;
	p->right = right;

	return (p);
}

int post_order (Node *p) {
  int sum = p->data;
  if (p->left){
    sum += post_order(p->left);
  }
  if (p->right){
    sum += post_order(p->right);
  }
  return sum;
}

Node* find_node (Node *p, int id) {
  Node * target = NULL;
  if (p->id == id){
    return p;
  }
  if (p->left) {
    target = find_node(p->left, id);
    if (target != NULL){
      return target;
    }
  }
  if (p->right) {
    target = find_node(p->right, id);
    if (target != NULL){
      return target;
    }
  }
  return target;
}
int main() {
  
	Node *F8 = makeNode(80, NULL, NULL, 8);
	Node *F7 = makeNode(130, NULL, NULL, 7);
	Node *F6 = makeNode(120, F7, F8, 6);
	Node *F5 = makeNode(90, NULL, NULL, 5);
	Node *F4 = makeNode(70, NULL, NULL, 4);
	Node *F3 = makeNode(50, NULL, F6, 3);
	Node *F2 = makeNode(30, F4, F5, 2);
	Node *F1 = makeNode(20, F2, F3, 1);

	int id, sum;
	scanf("%d" ,&id);
  Node *target = find_node(F1, id);

  if (target == NULL){
    printf("-1");
  }
  else {
    printf("%d",post_order(target));
  }

  
	return (0);
}
