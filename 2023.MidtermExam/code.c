#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *next;
}ListNode;

typedef struct ListType {
	ListNode *H;
}ListType;

void init(ListType *L) {
	L->H = (ListNode*)malloc(sizeof(ListNode));
	L->H->next = NULL;
}

ListNode* getNode() {
	return (ListNode*)calloc(1, sizeof(ListNode));
}
void insertFirst(ListType *L, int elem) {
	ListNode *p = L->H;
	ListNode *node = getNode();
	node->data = elem;
	node->next = p->next;
	p->next = node;
}
void print(ListType *L) {
	ListNode *p = L->H->next;

	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

	printf("NULL\n");

}

void insertLast(ListType *L, int elem) {
	ListNode *p = L->H;
	ListNode *node = getNode();
	node->data = elem;

	while (p->next) {
		p = p->next;
	}
	p->next = node;
}

void partition(ListType *L1, ListType *L2, int pos) {
	ListNode *p = L1->H;
	
	for (int i = 0; i < pos && p != NULL; i++) {
		p = p->next;
	}
	
	ListNode *node = p->next;
	while (node) {
		insertLast(L2, node->data);
		node = node->next;
	}
	p->next = NULL;
}

void concat(ListType *L1, ListType *L2) {
	ListNode *p = L2->H->next;

	while (p) {
		insertLast(L1, p->data);
		p = p->next;
	}
}

void move(ListType *L, ListNode *prevNode) {
	if (prevNode->next == NULL) {
		return 0;
	}
	else {
		move(L, prevNode->next);
		insertLast(L, prevNode->data);
	}
}
void reverse(ListType *L) {
	ListNode *p = L->H;
	if (p->next == NULL) {
		return 0;
	}
	else {
		while (p->next) {
			p = p->next;
		}
		move(L, L->H->next);
		L->H->next = p;
	}
	
}

void deleteNode(ListType *L, int elem) {
	ListNode *p = L->H;

	while (p->next != NULL) {
		if (p->next->data == elem) {
			p->next = p->next->next;
		}
		p = p->next;
	}
}

void deleteAll(ListType *L) {
	ListNode *p = L->H;
	p->next = NULL;
}

int main() {
	ListType L1, L2;
	init(&L1);
	init(&L2);

	srand(time(NULL));

	for (int i = 0; i < 15; i++)
		insertFirst(&L1, rand() % 20 + 1);
	print(&L1);

	int pos;
	
	scanf("%d", &pos);
	
	partition(&L1, &L2, pos);
	print(&L1); 
	print(&L2);

	concat(&L1, &L2);
	print(&L1); print(&L2);

	element e;
	scanf("%d", &e);
	deleteNode(&L1, e);
	print(&L1); print(&L2);

	reverse(&L2);
	print(&L2);

	deleteAll(&L1);
	print(&L1);

	return 0;
}