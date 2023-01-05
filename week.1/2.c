#include <stdio.h>

//descending sort function
void ABC(int *arr, int k){

    int maxIndex = k;

    for (int i = k; i < 10;i++) {
        if (arr[maxIndex] < arr[i]) {
            maxIndex = i;
        }
    }

    int tmp = arr[maxIndex];
    arr[maxIndex] = arr[k];
    arr[k] = tmp;

}

int main () {
    int num_arr[10];

    for (int i  = 0; i < 10; i++) {
        scanf("%d", &num_arr[i]);
    }

    for (int i = 0; i < 10;i++) {
        ABC(num_arr, i);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", num_arr[i]);
    }

    return 0;
}