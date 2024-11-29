#include <stdio.h>

int main(){
    
    int n1,n2,soma,sub,produto,divisao;
    
    printf("Digite um número inteiro: \n");
    scanf("%d",&n1);

    printf("Digite um segundo número inteiro: \n");
    scanf("%d",&n2);

    soma = n1 + n2;
    sub = n1 - n2;
    produto = n1 * n2;
    divisao = n1/n2;

    printf("Soma: %d \n",soma);

    printf("Subtração: %d \n",sub);

    printf("Multiplicação: %d \n",produto);

    printf("Divisão: %d \n",divisao);
    //printf("Soma: %d \nSubtração: %d \nMultiplicação: %d \nDivisão: %d \n",soma,sub,produto,divisao);

    return 0;
}