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

int setCompare(List* list1, List* list2) {
	Node* stand = list2->header;
	Node* compare = list1->header;

	while (stand && compare) {
		if (stand->elem == compare->elem) {
			compare = compare->next;
		}
		stand = stand->next;
	}

	return (compare == NULL) ? 0 : compare->elem;
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

	printf("%d", setCompare(&list1, &list2));

	return 0;
}