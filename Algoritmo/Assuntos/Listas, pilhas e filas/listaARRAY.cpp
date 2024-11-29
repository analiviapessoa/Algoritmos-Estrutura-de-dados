#include <iostream>

using namespace std;

struct List {
    int maxSize;        //capacidade
    int listSize;       //tamanho atual da lista
    int curr;           //posição do cursor
    int* listArray;    //ponteiro para o primeiro elemento da lista de inteiros
};

typedef struct List List; //chamar struct apenas por "List"

List* create_list (int size){  //Criar uma lista

    List *lista = (List* ) malloc (sizeof(List)); //alocar a memória
    
    lista -> maxSize = size;
    lista -> listSize = 0;      //inicialmente vazia
    lista -> curr = 0;          //cursor inicia em 0
    lista -> listArray = (int*) malloc (size * sizeof(int)); //alocar a memória

    return lista; //ponteiro para a lista criada
}

int length (List *lista){  //Retornar o tamanho da lista
    return (lista -> listSize);
}

int currPos (List *lista){  //Retornar o cursor atual
    return (lista -> curr);
}

int currValue (List *lista){  //Retornar o valor do cursor atual
    return (lista -> listArray)[(lista -> curr)];
}

void moveToStart (List *lista){  //Mover cursor pro início
    (lista -> curr) = 0; 
}

void moveToEnd (List *lista){   //Mover cursor pro final
    (lista -> curr) = (lista -> listSize); 
}

void moveToPos (List *lista, int pos){   //Mover cursor pra posição
    (lista -> curr) = pos; 
}

void previous (List *lista){    //Mover cursor pro anterior
    if ((lista -> curr) != 0){
        (lista -> curr)--;
    }
}

void next (List *lista){    //Mover cursor pro próximo
    if ((lista -> curr) < (lista -> listSize)){
        (lista -> curr)++;
    } 
}

int count (List *a,int k){

    int cont = 0;

    for (int i = 0 ; i < (a -> listSize) ; i++){
        if ((a -> listArray)[i] == k){
            cont++;
        }
    }

    return cont;
}

void insert_list (List *lista,int numero){  //Adicionar um elemento à direita do cursor
    
    if (lista -> listSize >= lista -> maxSize){  //não tem espaço para deslocamento
        exit(1);
    }

    int i = lista -> listSize;

    while (i > lista -> curr){
        lista -> listArray[i] = lista -> listArray[i-1]; //lista abre um espaço à esquerda
        i--;
    }

    lista -> listArray[lista -> curr] = numero;
    lista -> listSize++;
}

void append (List *lista,int numero){  //Adicionar um elemento no final
    
    if (lista -> listSize >= lista -> maxSize){  //não tem espaço para deslocamento
        exit(1);
    }

    (lista -> listArray)[lista -> listSize] = numero;
    (lista -> listSize)++;
}

int remove_list (List *lista){  //Remover o elemento à direita do cursor
    if ((lista -> curr) < 0 || (lista -> curr) >= (lista -> listSize)){
        return NULL;
    }
    
    int numero = (lista -> listArray) [(lista -> curr)]; //adiciona a "numero" o valor referenciado pelo cursor
    int i = (lista -> curr);

    while (i < (lista -> listSize) - 1){
        (lista -> listArray)[i] = (lista -> listArray)[i+1]; //move a lista para a esquerda
        i++;
    }

    (lista -> listSize)--;

    return numero;
}

int print_list (List *lista){   //Printar lista

    for (int i = 0 ; i < (lista -> listSize) ; i++){
        cout << (lista -> listArray)[i] << " ";
    }
    cout << endl;
}

void clear(List* lista){    //limpar lista
    if ((lista -> listArray) != NULL){
        free(lista -> listArray);
    }
    lista -> listSize = 0;
    lista -> curr = 0;
}

int main(){

    List *novalista = create_list(5);

    cout <<"cursor: ";
    cout << currPos(novalista) << endl;

    insert_list(novalista,7); 
    print_list(novalista);

    moveToPos(novalista,0);
    cout << currPos(novalista) << endl;

    next(novalista);
    cout <<"cursor: ";
    cout << currPos(novalista) << endl;

    insert_list(novalista,8);
    print_list(novalista);

    previous(novalista);
    cout <<"cursor: ";
    cout << currPos(novalista) << endl;
    cout << currValue (novalista) << endl;

    insert_list(novalista,9);
    print_list(novalista);

    append(novalista,6);
    print_list(novalista);

    clear(novalista);
    print_list(novalista);

    delete(novalista->listArray);
    delete(novalista);

    return 0;
}