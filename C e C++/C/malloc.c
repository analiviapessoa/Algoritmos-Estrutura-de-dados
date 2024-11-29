#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Print the number of integers: ");
    scanf("%d",&n);

    int *ponteiro = (int *)malloc(n*sizeof(int));

    if (ponteiro == NULL){
        printf("Memory not available.");
        exit(1);
    }
    for (int i=0 ; i<n ; i++){
        printf("Enter an integer: ");
        scanf("%d",ponteiro+i);
    }

    for (int i = 0 ; i<n ; i++){
        printf("%d",*(ponteiro+i));
    }
   
    return 0;
}