#include <stdio.h>

int main()
{
    int lista [5] = {1,2,3,4,5};

    int *ponteiro = lista;

    printf("Conteudo de lista[0] = %d\n",*ponteiro);
    printf("Conteudo de lista[0] = %d\n",*lista);

    for (int i = 0 ; i < 5 ; i++){
        printf("%d\n",ponteiro[i]);
    }

    for (int i = 0 ; i < 5 ; i++){
        printf("%d\n",*(ponteiro+i));
    }

    printf("Conteudo de lista[2] = %d\n", lista[2]);
    printf("Conteudo de lista[2] = %d\n",*(lista+2));
    
    printf("Endereco de lista[2] = %d\n", &lista[2]);
    printf("Endereco de lista[2] = %d\n", (lista+2));

    return 0;
}