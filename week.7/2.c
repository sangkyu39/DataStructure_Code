#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int elem;
	struct Node* next;
} Node;

typedef struct List {
	Node* header;
} List;

void init(List* list) {
	list->header = (Node*)calloc(1, sizeof(Node));
}

void addTerm(List* list, int elem) {
	Node* p = list->header;
	Node* node = (Node*)calloc(1, sizeof(Node));

	while (p->next) {
		p = p->next;
	}

	if (p->elem == NULL) {
		p->elem = elem;
	}
	else {
		node->elem = elem;
		p->next = node;
	}
}

void print(List* list) {
	Node* p = list->header;

	while (p) {
		printf(" %d", p->elem);
		p = p->next;
	}

	printf("\n");
}

void setUnion(List* list1, List * list2) {
	List result;

	init(&result);

	Node* node1 = list2->header;
	Node* node2 = list1->header;

	while (node1 || node2) {
		if (node1 == NULL) {
			addTerm(&result, node2->elem);
			node2 = node2->next;
		}
		else if (node2 == NULL) {
			addTerm(&result, node1->elem);
			node1 = node1->next;
		}
		else if (node1->elem < node2->elem) {
			addTerm(&result, node1->elem);
			node1 = node1->next;
		}
		else if (node2->elem < node1->elem) {
			addTerm(&result, node2->elem);
			node2 = node2->next;
		}
		else if (node1->elem == node2->elem) {
			addTerm(&result, node1->elem);
			node1 = node1->next;
			node2 = node2->next;
		}
		
	}

	print(&result);
}

int setSubtract (List* list1, List* list2) {
	List result;

	init(&result);

	Node* node1 = list2->header;
	Node* node2 = list1->header;

	while (node1 && node2) {
		if (node1 == NULL) {
			addTerm(&result, node2->elem);
			node2 = node2->next;
		}
		else if (node2 == NULL) {
			addTerm(&result, node1->elem);
			node1 = node1->next;
		}
		else if (node1->elem < node2->elem) {
			node1 = node1->next;
		}
		else if (node2->elem < node1->elem) {
			node2 = node2->next;
		}
		else if (node1->elem == node2->elem) {
			addTerm(&result, node1->elem);
			node1 = node1->next;
			node2 = node2->next;
		}

	}

	print(&result);
}

int main() {
	List list1, list2;

	init(&list1);
	init(&list2);

	int cnt, elem;

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &elem);
		addTerm(&list1, elem);
	}

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &elem);
		addTerm(&list2, elem);
	}

	setUnion(&list1, &list2);

	setSubtract(&list1, &list2);

	return 0;
}