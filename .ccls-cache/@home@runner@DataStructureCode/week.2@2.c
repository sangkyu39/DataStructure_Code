#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int mostOnes(int **arr, int n){
  int row = 0, cal = 0, maxRow = 0;
  while (row < n){
    if (arr[row][cal] == 1){
    maxRow = row;
    cal++;
    }
    else {
      row++;
    }
  }
  
  return maxRow;
}

int main(){
  int n;

  scanf("%d",&n);

  int **arr = (int **)calloc(n,sizeof(int *));

  for (int i = 0;i < n;i++){
    arr[i] = (int *)calloc(n,sizeof(int));
  }

  for (int i = 0;i < n;i++){
    for (int j = 0;j < n;j++){
      scanf("%d", &arr[i][j]);
    }
  }

  printf("%d",mostOnes(arr, n));

  for (int i = 0;i < n;i++){
    free(arr[i]);
  }
  free(arr);
  
  return 0; 
}