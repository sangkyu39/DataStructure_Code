#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
    int elem;
    struct node* prev, * next;
} node;

typedef struct {
    node* front, * rear;
} deque;

void initdeque(deque* D) {
    D->front = D->rear = NULL;
}

node* getNode() {
  return (node *)calloc(1, sizeof(node));
}
void add_front(deque* D, int e) {
    node* P = getNode();
    P->elem = e;
  
    P->next = D->front;
    P->prev = NULL;
  
    if (D->front != NULL) {
        D->front->prev = P;
    }
  
    D->front = P;
    if (D->rear == NULL) {
        D->rear = P;
    }
}

void add_rear(deque* D, int e) {
    node* P = getNode();
    P->elem = e;
  
    P->next = NULL;
    P->prev = D->rear;
  
    if (D->rear != NULL) {
        D->rear->next = P;
    }
    D->rear = P;
  
    if (D->front == NULL) {
        D->front = P;
    }
}

void delete_front(deque* D) {
  
    if (D->front == D->rear) {
        printf("underflow");
        exit(1);
    }

    if (D->front == NULL) {
        return;
    }
    node* temp = D->front;
    D->front = D->front->next;
  
    if (D->front != NULL) {
        D->front->prev = NULL;
    }
    else {
        D->rear = NULL;
    }
  
    free(temp);
}

void delete_rear(deque* D) {
  
    if (D->front == D->rear) {
        printf("underflow");
        exit(1);
    }
  
    if (D->rear == NULL) {
        return;
    }
    node* temp = D->rear;
    D->rear = D->rear->prev;
  
    if (D->rear != NULL) {
        D->rear->next = NULL;
    }
    else {
        D->front = NULL;
    }
  
    free(temp);
}

void print(deque* D) {
    node* p = D->front;
  
    while (p != NULL) {
        printf("%d ", p->elem);
        p = p->next;
    }
    printf("\n");
}

int main() {
    deque D;
    initdeque(&D);
    int n, num;
    char pmt[3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", pmt);
        if (strcmp(pmt, "AF") == 0) {
            scanf("%d", &num);
            add_front(&D, num);
        }
        else if (strcmp(pmt, "AR") == 0) {
            scanf("%d", &num);
            add_rear(&D, num);
        }
        else if (strcmp(pmt, "DF") == 0) {
            delete_front(&D);
        }
        else if (strcmp(pmt, "DR") == 0) {
            delete_rear(&D);
        }
        else if (strcmp(pmt, "P") == 0) {
            print(&D);
        }
    }
  
    return 0;
}

