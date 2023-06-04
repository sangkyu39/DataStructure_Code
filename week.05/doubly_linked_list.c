#include <stdio.h>
#include <stdlib.h>

//이중 연결 리스트
typedef struct DListNode {
    char elem;
    struct DListNode *prev;
    struct DListNode *next;
} DListNode;

typedef struct DListType {
   DListNode* header;
   DListNode* trailer;
   int n;
}DListType;

DListNode* getnode(){
   DListNode* node = (DListNode*)calloc(1, sizeof(DListNode));
   return node;
}

//초기 설정 함수
void init(DListType* DL) {
    DL->header = getnode();
    DL->trailer = getnode();

    DL->header->next = DL->trailer;
    DL->header->prev = DL->header;
    
    DL->n = 0;
};

//처음 위치 삽입
void insertFirst(DListType* DL, char elem){
    DListNode* node = getnode();
    DListNode* p = DL->header;

    node->elem = elem;
    
    node->prev = p;
    node->next = p->next;
    
    p->next->prev = node;
    p->next = node;

    DL->n++;
}

//마지막 위치 삽입
void insertLast(DListType* DL, char elem){
    DListNode* node = getnode();
    DListNode* p = DL->header;

    node->elem = elem;
    while (p->next != DL->trailer) {
        p = p->next;
    }

    node->prev = p;
    node->next = p->next;
    
    p->next->prev = node;
    p->next = node;

    DL->n++;
}

//중간 위치 삽입
void insert(DListType *DL, int pos, char elem) {
    DListNode * node = getnode();
    DListNode * p = DL->header;

    if(pos == 1){
        insertFirst(DL, elem);
    }
    else{
        for(int i = 1; i < pos; i++){
            p = p->next;
        }
        node->elem = elem;

        node->prev = p;
        node->next = p->next;

        p->next->prev = node;
        p->next = node;

        DL->n++; 
    }
}

//처음 위치 삭제
void deleteFirst(DListType* DL){
    DListNode* p = DL->header;

    if(p->next == NULL){
        DL->header = DL->trailer = NULL;
    }
    else{
        DL->header = p->next;
        p->next->prev = NULL;
    }

    free(p);
}

//마지막 위치 삭제
void deleteLast(DListType* DL){
    DListNode* p = DL->trailer;
    
    if(p->prev == NULL){
        DL->header = DL->trailer = NULL;
    }
    else{
        DL->trailer = p->prev;
        p->prev->next = NULL;
    }

    free(p);
}

//중간 위치 삭제
void delete(DListType* DL, int pos){
    DListNode* p = DL->header;
    
    if(pos == 1){
        deleteFirst(DL);
    }
    else{
        for(int i = 1; i <= pos; i++){
            p = p->next;
        }
        p->elem;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);

    }
}

// 연결 리스트 출력
void print(DListType *DL) {
    DListNode *p = DL->header->next;
    for (p ;p != DL->trailer; p = p->next) {
        printf("%c <=> ",p->elem);
    }

    printf("\b\b\b\b   \n");
}

int main(){
    DListType DL;

    init(&DL);

    insertFirst(&DL, 'A'); 
    print(&DL);

    insertFirst(&DL, 'B'); 
    print(&DL);
    
    insertLast(&DL, 'C'); 
    print(&DL);
    
    insertLast(&DL, 'D'); 
    print(&DL);

    insert(&DL, 2, 'E');
    print(&DL);
    
    insert(&DL, 4, 'F');
    print(&DL);

    deleteFirst(&DL);
    print(&DL);

    deleteLast(&DL);
    print(&DL);
    
    delete(&DL, 3);    
    print(&DL);

    return 0;
}