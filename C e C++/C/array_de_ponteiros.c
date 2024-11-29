#include <stdio.h>

int main()
{
    
    //tipo_dado *nome_array [tamanho];
    //cada elemento da array aponta para um endereço de memória

    int *listap[2]; //lista com 2 ponteiros
    int x = 10;
    int y[2] = {20,30};

    listap [0] = &x; // endereço de X
    listap [1] = y; // endereço do vetor Y

    //listap = {x,y} = {10,{20,30}}

    printf("listap [0]: %p\n",listap[0]);// endereço de X
    printf("listap [1]: %p\n",listap[1]);// endereço do primeiro elemento de Y

    printf("Conteudo de listap [0]: %d\n",*listap[0]);
    printf("Conteudo de listap [1][1]: %d\n",listap[1][1]);//matriz

    for (int i = 0 ; i < 2 ; i++){
        printf("%d ",*listap[i]);
    }

    return 0;
}
