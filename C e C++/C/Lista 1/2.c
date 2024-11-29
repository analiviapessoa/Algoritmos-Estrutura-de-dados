#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int n,k,tamanho,diferenca,cont = 0;

    tamanho=pow(10,5);
    int a[tamanho];

    scanf("%d %d",&n,&k);

    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
                diferenca = abs(a[i]-a[j]);
                if (diferenca == k){
                    cont+=1;
                }
        }
    }

    printf("%d",cont);

    return 0;
}