#include <stdio.h>

int main(){

    int a[] = {2,8,5,3,9,4,1},posicao,temp;
    for (int i = 0 ; i<6 ; i++){
        posicao = i;
        for (int j = i+1 ; j<7 ; j++){
            if (a[j]<a[posicao]){
                posicao=j;
            }
        }
        temp = a[i];
        a[i]=a[posicao];
        a[posicao]=temp;
    }

    for (int i = 0 ; i<7 ; i++){
        printf("%d ",a[i]);
    }
    return 0;
}