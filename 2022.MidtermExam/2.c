#include <stdio.h>

typedef struct Node {
	int elem;
	struct Node* next;
} Node;

typedef struct {
	Node* header;

} ListType;

Node* getNode() {
	return (Node*)calloc(1, sizeof(Node));
}

void init(ListType* list) {
	list->header = getNode();
}

void insertLast(ListType* list, int e) {
	Node* p = list->header;
	Node* node = getNode();

	node->elem = e;

	while (p->next != NULL) {
		p = p->next;
	}

	p->next = node;
}

void print(ListType* list) {
	Node* p = list->header->next;

	printf("생성된 연결 리스트 :");

	while (p != NULL) {
		printf(" %d ->", p->elem);
		p = p->next;
	}
	printf("\b\b  ");
}

int main() {
	ListType list;
	
	init(&list);

	int cnt, elem;

	printf("노드의 개수 :");
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		printf("노드 #%d 데이터 :", i);
		scanf("%d", &elem);
		insertLast(&list, elem);
	}
	print(&list);
	
	return 0;
}