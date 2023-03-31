#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char elem;
	struct Node* prev, * next;
} Node;

typedef struct {
	Node* header;
	Node* trailer;
} List;

//초기화
void init(List* list) {
	list->header = (Node*)calloc(1, sizeof(Node));
	list->trailer = (Node*)calloc(1, sizeof(Node)); //단일 연결 리스트일 경우 필요 X

	list->header->next = list->trailer;
	list->trailer->prev = list->header; //단일 연결 리스트일 경우 필요 X
	list->trailer->next = NULL;
}

void add(List* list, int rank, char elem) {

	Node* node = (Node*)calloc(1, sizeof(Node));
	Node* back = list->header;

	while (--rank && node->next != list->trailer) {
		back = back->next;
	}

	if (back == list->trailer) {
		return 0;
	}

	node->elem = elem;

	node->next = back->next;
	node->next->prev = node;

	back->next = node;
	node->prev = back;
}

void delete(List* list, int rank) {
	Node* del_node = list->header;
	
	while (rank-- && del_node->next != list->trailer) {
		del_node = del_node->next;
	}

	if (del_node == list->trailer) {
		return 0;
	}

	del_node->prev->next = del_node->next;
	del_node->next->prev = del_node->prev;
	
	free(del_node);
}

char get(List* list, int rank) {
	Node* get_node = list->header;

	while (rank-- && get_node->next != list->trailer) {
		get_node = get_node->next;
	}

	if (get_node == list->trailer) {
		return 0;
	}

	return get_node->elem;
}

void print(List* list) {
	Node* node = list->header;

	while (node->next != list->trailer) {
		node = node->next;
		printf("%c", node->elem);
	}
}

int main() {
	List list;

	init(&list);

	char eng;
	int rank, cnt = 0, n;
	char choice;

	scanf("%d", &n);
	getchar();

	for (int i = 0;i < n;i++) {
		scanf("%c", &choice);
		getchar();

		if (choice == 'A') {
			scanf("%d %c", &rank, &eng);
			getchar();
			if ((cnt + 1 < rank) || (0 >= rank)) {
				printf("invalid position\n");
			}
			else {
				add(&list, rank, eng);
				cnt++;
			}
		}
		else if (choice == 'D') {
			scanf("%d", &rank);
			getchar();
			if ((cnt < rank) || (0 >= rank)) {
				printf("invalid position\n");
			}

			else {
				delete(&list, rank);
				cnt--;
			}
		}
		else if (choice == 'G') {
			scanf("%d", &rank);
			getchar();
			if ((cnt < rank) || (0 >= rank)) {
				printf("invalid position\n");
			}

			else {
				printf("%c\n", get(&list, rank));
			}
		}
		else if (choice == 'P') {
			print(&list);
			printf("\n");
			
		}
	}
			
	return 0;
}