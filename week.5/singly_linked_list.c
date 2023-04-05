#include <stdio.h>
#include <stdlib.h>

//단순 연결 리스트

typedef struct ListNode{
    char elem;
    struct ListNode* next;
} ListNode;

typedef struct ListType{
    ListNode* header;
} ListType;

//초기 설정 함수
void init(ListType* L){
    L->header = NULL;
}

//처음 위치 삽입
void insertFirst(ListType* L, char elem){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->elem = elem;
    node->next = L->header;
    L->header = node;
}

//마지막 위치 삽입
void insertLast(ListType* L, char elem){
    ListNode* node = (ListNode*)calloc(1, sizeof(ListNode));
    node->elem = elem;
    node->next = NULL;
    
    ListNode* p = L->header;

    if(p == NULL){
        L->header = node;
    }
    else{
        while(p->next != NULL){
            p = p->next;
        }

        p->next = node;
    }
}

//중간 위치 삽입
void insert(ListType* L, int pos, char elem){
    ListNode* node = (ListNode*)calloc(1, sizeof(ListNode));
    ListNode* p = L->header;
    
    if(pos == 1){
        insertFirst(L, elem);
    }
    else{
        for(int i = 1; i < pos - 1; i++){
            p = p->next;
        }
        node->elem = elem;
        node->next = p->next;
        p->next = node;
    }
}

// 처음 위치 삭제
void deleteFirst(ListType* L){
    ListNode* p = L->header;
    L->header = p->next;
    free(p);
}

// 마지막 위치 삭제
void deleteLast(ListType* L){
    ListNode* p = L->header;
    ListNode* q;

    while(p->next != NULL){
        q = p;
        p = p->next;
    }

    q->next = NULL;
    free(p);
}

// 중간 위치 삽입
void delete(ListType* L, int pos){
    ListNode* p = L->header;
    ListNode* node;

    if(pos == 1){
        return deleteFirst(L);
    }
    else{
        for(int i = 1; i < pos; i++){
            node = p;
            p = p->next;
        }
        node->next = p->next;
        
        free(p);
    }
}

// 연결 리스트 출력
void print(ListType* L) {

   for (ListNode* p = L->header; p != NULL; p = p->next) {
      printf("%c -> ", p->elem);
   }
   printf("\b\b\b   \n");
}

int main(){
    
    ListType L;
    init(&L);

    insertLast(&L, 'C');
    print(&L);

    insertFirst(&L, 'A'); 
    print(&L);
    
    insertFirst(&L, 'B');
    print(&L);
    
    insertLast(&L, 'D');
    print(&L);
    
    insert(&L, 2, 'E');
    print(&L);

    insert(&L, 4, 'F');
    print(&L);

    deleteFirst(&L);    
    print(&L);
    
    deleteLast(&L); 
    print(&L);
    
    delete(&L, 3);  
    print(&L);

    return 0;
}
