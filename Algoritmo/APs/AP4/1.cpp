#include <iostream>
#include <string>

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
    
    delete(temp);

    (l -> cnt)--;

    return it;

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

int main(){

    List *lista = create_list();
    int c;
    cin >> c;

    for (int i = 0 ; i < c ; i++){
        int n;
        cin >> n;
        cout << "Caso " << i+1 << ":" << endl;

        for (int j = 0 ; j < n ; j++){
            string operacao;
            cin >> operacao;
            int numero;

            if (operacao == "insert"){
                cin >> numero;
                insert(lista,numero);
            }
            else if (operacao == "remove"){
                remove(lista);
            }
            else if (operacao == "count"){
                cin >> numero;
                count(lista,numero);
                cout << count(lista,numero) << endl;
            }
            else if (operacao == "prev"){
                previous(lista);
            }
            else if (operacao == "next"){
                next(lista);
            }
        }

    }

    delete(lista);

    return 0;
}