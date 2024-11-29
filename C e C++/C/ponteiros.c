#include <stdio.h>

int main(){

    int var = 15;
    int *ptr = &var;

    printf("Conteudo de var = %d\n",var);
    printf("Endereco de var = %p\n",&var);

    printf("Conteudo apontado por ptr = %d\n",*ptr);
    printf("Endereco apontado por ptr = %p\n",ptr);

    printf("Endereco do ptr = %p\n",&ptr);

    *ptr = 73;

    printf("Conteudo de var = %d\n",var);
    printf("Endereco de var = %p\n",&var);

    printf("Conteudo apontado por ptr = %d\n",*ptr);
    printf("Endereco apontado por ptr = %p\n",ptr);

    printf("Endereco do ptr = %p\n",&ptr);

    return 0;
}

/*
    *ptr = Conteúdo do endereço da variável
    ptr = Endereço da variável 
    &ptr = Endereço do ponteiro
*/