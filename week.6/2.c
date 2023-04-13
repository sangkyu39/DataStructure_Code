#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
   int coef;
   int exp;
   struct Node* next;
}Node;

typedef struct List {
   Node* header;
} List;

Node* getNode() {
   return (Node*)calloc(1, sizeof(Node));
}
   
void init(List* list) {
   list->header = getNode();
}

void appendTerm(List* list, int coef, int exp) {
   Node *back = list->header;
   Node* point = getNode();
   
   point->coef = coef;
   point->exp = exp;

   while (back->next != NULL) {
      back = back->next;
   }

   back->next = point;   
}

void print(List* list) {
   Node* point = list->header->next;

   while (point != NULL) {
      printf(" %d %d", point->coef, point->exp);
      point = point->next;
   }
   printf("\n");
}


List* addPoly(List* list1, List* list2) {
   List *result = (List *)calloc(1, sizeof(List));
   
   init(result);

   Node* n1 = list1->header->next;
   Node* n2 = list2->header->next;

   while (n1 != NULL || n2 != NULL) {
      if (n2 == NULL) {
         appendTerm(result, n1->coef, n1->exp);
         n1 = n1->next;
      }
      else if (n1 == NULL) {
         appendTerm(result, n2->coef, n2->exp);
         n2 = n2->next;
      }
      else if (n1->exp > n2->exp) {
         appendTerm(result, n1->coef, n1->exp);
         n1 = n1->next;
      }
      else if (n1->exp < n2->exp) {
         appendTerm(result, n2->coef, n2->exp);
         n2 = n2->next;
      }
      else if (n1->exp == n2->exp){
         int sum = n1->coef + n2->coef;

         if (sum) {
            appendTerm(result, sum, n1->exp);
         }
         n1 = n1->next;
         n2 = n2->next;
      }
   }
   
   return result;
}

int main() {
   List list1, list2;

   init(&list1);
   init(&list2);

   int cnt, coef, exp;

   scanf("%d", &cnt);

   for (int i = 0; i < cnt; i++) {
      scanf("%d %d", &coef, &exp);
      appendTerm(&list1, coef, exp);
   }

   scanf("%d", &cnt);

   for (int i = 0; i < cnt; i++) {
      scanf("%d %d", &coef, &exp);
      appendTerm(&list2, coef, exp);
   }

   List* result = addPoly(&list1, &list2);
   print(result);

   return 0;
}

   