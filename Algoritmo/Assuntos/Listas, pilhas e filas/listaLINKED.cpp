#include <iostream>

using namespace std;

struct Link {
    int element;
    Link* next;
};

typedef struct Link Link;

Link* create_header (Link* nextval){ 

    Link *n = (Link* ) malloc (sizeof(Link));

    (n -> next) = nextval;

    return n;
}

Link* create_link (int it, Link* nextval){
    
    Link *n = (Link* ) malloc (sizeof(Link));

    (n -> element) = it;
    (n -> next) = nextval;

    return n;
}

struct List {
    Link *head;  //aponta pro nó header
    Link *tail;  //aponta pro último nó da lista
    Link *curr;  //aponta pro nó anterior ao de inserção ou remoção
    int cnt;    //Número de elementos
};

typedef struct List List;

List* create_list (){

    List *l = (List* ) malloc (sizeof(List));

    (l -> head) = create_header(NULL);   //header
    (l -> tail) = l -> head;   //header
    (l -> curr) = l -> head;   //header
    (l -> cnt) = 0;

    return l;
}

void insert (List* l, int it){  //criar um novo nó

    ((l -> curr)-> next) = create_link (it, (l -> curr) -> next);//o novo nó aponta para o próximo de onde o cursor aponta

    if ((l -> tail) == (l -> curr)){ //se o novo nó for o último

        (l -> tail) = (l -> curr) -> next;  //tail apontar para o novo nó
    }

    (l -> cnt)++;
}

int currPos (List *l){
    Link* temp = (l -> head);
    int posicao = 0;

    while (temp != (l -> curr)){
        temp = temp -> next;
        posicao++;
    }
    return posicao;
}

void moveToStart (List *l){     //mover o cursor para o início
    (l -> curr) = (l -> head);  //head sempre aponta para o início
}

void next (List *l){

    if ((l->curr) != (l -> tail)){

        (l -> curr) = ((l -> curr) -> next);
    }
}

void previous (List *l){
    if ((l -> curr) != (l -> head)){

        Link *temp = (l -> head);

        while ((temp -> next) != (l -> curr)){

            temp = (temp -> next);
        }

        (l -> curr) = temp;

    }
}

int count (List *l,int x){
    Link* temp = (l -> head);
    int cont = 0;

    while (temp != (l -> tail)){
        temp = temp -> next;
        if ((temp -> element) == x){
            cont++;
        }
    }
    return cont;
}

int remove (List* l){      //retorna o valor a ser removido
    if (((l -> curr) -> next) == NULL){
        return NULL;
    }

    int it = (((l -> curr) -> next) -> element);

    if ((l -> tail) == ((l -> curr) -> next)){
        (l -> tail) = (l -> curr);
    }

    Link* temp = ((l -> curr) -> next); 

    ((l -> curr) -> next) = (((l -> curr) -> next) -> next);
    
    free(temp);

    (l -> cnt)--;

    return it;

}

void print_list (List* l) {
    
    Link* temp = (l->head)->next; // Pular o header
    
    while (temp != NULL) {

        cout << (temp->element) << " ";

        temp = (temp->next);
    }
    
    cout << endl;
}

void clear(List* lista) {
    Link* temp;

    while ((lista->head)->next != NULL) {
        temp = (lista->head)->next;
        (lista->head)->next = ((lista->head)->next)->next;
        free(temp);
    }

    (lista->head)->next = NULL; 
    lista->tail = lista->head; 
    lista->curr = lista->head; 
    lista->cnt = 0;
}

int main(){

    List *lista = create_list();

    insert(lista,1);
    insert(lista,2);
    insert(lista,3);
    insert(lista,4);
    insert(lista,5);
    print_list(lista);
    cout << currPos(lista) << endl;
    next(lista);
    cout << currPos(lista) << endl;
    next(lista);
    cout << currPos(lista) << endl;
    remove(lista);
    print_list(lista);
    previous(lista);
    cout << currPos(lista) << endl;
    insert(lista,8);
    print_list(lista);
    moveToStart(lista);
    cout << currPos(lista) << endl;
    insert(lista,10);
    print_list(lista);

    clear(lista);
    print_list(lista);

    delete(lista);

    return 0;
}