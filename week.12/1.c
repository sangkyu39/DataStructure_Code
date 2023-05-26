#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left, *right;
} Node;

Node *makeNode(int data, Node *left, Node *right) {
	Node *p = (Node *)calloc(1, sizeof(Node));

	p->data = data;
	p->left = left;
	p->right = right;

	return (p);
}

void print(Node *p) {
	printf("%d ", p->data);

	if (p->left){
		printf("%d ", p->left->data);
    }
	if (p->right){
		printf("%d ", p->right->data);
    }
  
	printf("\n");
}

int main() {
  
	Node *F1 = makeNode(20, F2, F3);
	Node *F2 = makeNode(30, F4, F5);
	Node *F3 = makeNode(50, NULL, F6);
	Node *F4 = makeNode(70, NULL, NULL);
	Node *F5 = makeNode(90, NULL, NULL);
	Node *F6 = makeNode(120, F7, F8);
	Node *F7 = makeNode(130, NULL, NULL);
	Node *F8 = makeNode(80, NULL, NULL);

	int n;
	scanf("%d", &n);

    switch(n){
        case 1:
            print(F1);
            break;
        case 2:
            print(F2);
            break;
        case 3:
            print(F3);
            break;
        case 4:
            print(F4);
            break;
        case 5:
            print(F5);
            break;
        case 6:
            print(F6);
            break;
        case 7:
            print(F7);
            break;
        case 8:
            print(F8);
            break;
        default:
            printf("-1\n");
            break;
    }
  
	return (0);
}
