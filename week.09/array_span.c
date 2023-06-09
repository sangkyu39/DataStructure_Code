#include <stdio.h>
#include <stdlib.h>

#define N 6

void spans (int X[], int S[]){
  int s;

  for (int i = 0;i < N;i++){
    s = 1;

    while ((s <= i) && (X[i - s] <= X[i])){
      s++;
    }
    
    S[i] = s;
  }
}

int main(){
  int X[N] = {60, 30, 40, 20, 50, 30};
  int S[N] = { 0 };
  
  spans(X, S);

  for (int i = 0;i < N;i++){
    printf("[%d] ",S[i]);
  }
  printf("\n");

  return 0;
}