#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * prefixAverages1(int *x, int n){
  int *arr = (int *)calloc(n,sizeof(int));
  
  for (int i = 0;i < n;i++){
    int sum = 0;
    for (int j = 0;j <= i;j++){
      sum += x[j];
    }
    arr[i] = sum / (i + 1.0) + 0.5;
  }

  return arr;
}

int *prefixAverages2(int *x, int n){
  int *arr = (int *)calloc(n,sizeof(int));
  int sum = 0;
  
  for (int i = 0;i < n;i++){
    sum += x[i];
    arr[i] = sum / (i + 1.0) + 0.5;
  }

  return arr;
}

int main(){
  int n = 0;

  scanf("%d", &n);

  int *arr1 = (int *)calloc(n, sizeof(int));

  for (int i = 0;i < n;i++){
    scanf("%d",&arr1[i]);
  }

  int *arr2 = prefixAverages1(arr1, n);
  int *arr3 = prefixAverages2(arr1, n);

  for (int i = 0;i < n;i++){
    printf("%d ", arr2[i]);
  }
  printf("\n");
  for (int i = 0;i < n;i++){
    printf("%d ",arr3[i]);
  }
  
  return 0; 
}
