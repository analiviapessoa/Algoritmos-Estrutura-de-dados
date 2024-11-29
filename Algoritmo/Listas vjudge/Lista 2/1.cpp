#include <iostream>

using namespace std;

struct Link {
    char element;
    Link* next;
};
typedef struct Link Link;

Link* create_header (Link* nextval){ 

    Link *n = (Link* ) malloc (sizeof(Link));

    (n -> next) = nextval;

    return n;
}

Link* create_link (char it, Link* nextval){
    
    Link *n = (Link* ) malloc (sizeof(Link));

    (n -> element) = it;
    (n -> next) = nextval;

    return n;
}

struct List {
    Link *head; 
    Link *tail;  
    Link *curr;  
    int size;    
};
typedef struct List List;

List* create_list (){

    List *l = (List* ) malloc (sizeof(List));

    (l -> head) = create_header(NULL);   
    (l -> tail) = l -> head;   
    (l -> curr) = l -> head;   
    (l -> size) = 0;

    return l;
}

void insert (List* l, char it){  

    ((l -> curr)-> next) = create_link (it, (l -> curr) -> next);

    if ((l -> tail) == (l -> curr)){ 

        (l -> tail) = (l -> curr) -> next;  
    }
    (l -> curr) = ((l -> curr) -> next);
    (l -> size)++;

}

void moveToStart (List *l){    
    (l -> curr) = (l -> head);  
}

void moveToEnd (List *l){     
    (l -> curr) = (l -> tail);
}

void print_list (List* l) {
    
    Link* temp = (l->head)->next; 
    
    while (temp != NULL) {

        cout << (temp->element);

        temp = (temp->next);
    }
    
    cout << endl;
}

int main(){

    int tamanhomax = 100001;
    char texto[tamanhomax];

    while(cin >> texto){

        List* lista = create_list();
    
        for (int i = 0; texto[i]!= '\0'; i++){
            if (texto[i] == '['){
                moveToStart(lista);
            }
            else if (texto[i] == ']'){
                moveToEnd(lista);
            }
            else{
                insert(lista,texto[i]);
            }
        }
        print_list(lista);
    }
    return 0;
}