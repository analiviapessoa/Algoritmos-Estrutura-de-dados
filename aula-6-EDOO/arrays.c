#include <stdio.h>

int main(){

    int *arr;
    int n;

    printf("Enter you array size: ");
    scanf("%d", &n);

    arr = (int *)malloc(n*sizeof(int));
    
    for (int i = 0 ; i < n ; i++){
        arr[i] = (2*i) + 1;
    }

    for (int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
}