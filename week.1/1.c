#include <stdio.h>

//sum 1 ~ n
int sum(int n) { 
    if (n == 1) return 1;
    return n + sum(n-1);
}

int main(){
    int num, sumNum = 0;

    scanf("%d",&num);

    for (int i = 1;i <= num;i++) {
        sumNum += sum(i);
    }
    printf("%d",sumNum);

    return 0;
}