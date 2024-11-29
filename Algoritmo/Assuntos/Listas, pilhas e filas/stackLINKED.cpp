#include <iostream>

using namespace std;

struct Link {
    int element;
    Link* next;
};

typedef struct Link Link;

Link* create_link (int it, Link* nextval){
    
    Link *n = (Link* ) malloc (sizeof(Link));

    (n -> element) = it;
    (n -> next) = nextval;

    return n;
}

struct stack{
    Link* top;  //Aponta para o primeiro elemento
    int size;   //Número de elementos
};

typedef struct stack stack;

stack* create_stack (){
    stack *s = (stack* )malloc(sizeof(stack));

    (s -> top) = NULL;
    (s -> size) = 0;

    return s;
}

void push (stack* s, int it){
    (s -> top) = create_link(it, (s -> top));   //cria um nó para o novo elemento, que aponta pro mesmo elemento que o topo aponta;
    //topo aponta para o novo elemento (topo vira o novo elemento)
    (s -> size)++;
}

int pop (stack* s){
    if ((s -> top) == NULL) {
        return -1;
    }

    int it = (s -> top) -> element;     //elemento no topo a ser retirado
    Link* temp = (s -> top); 

    (s -> top) = (s -> top) -> next;    //topo aponta para o segundo elemento
    (s -> size)--;
    
    free(temp);

    return it;
}

int topValue(stack *s){
    return (s -> top) -> element;
}

int length (stack *s){
    return (s -> size);
}

void clear(stack *s){
    Link* temp;

    while ((s -> top) != NULL){
        temp = (s -> top);
        (s -> top) = (s -> top) -> next;
        free(temp);
    }

    (s -> size) = 0;
}

void print_stack (stack* s){
    Link* temp = s -> top;

    while (temp != NULL){
        cout << temp->element << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    stack* stack = create_stack();

    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    print_stack(stack);
    pop(stack);
    print_stack(stack);
    cout << topValue(stack) << endl;
    cout << length(stack) << endl;
    clear(stack);
    print_stack(stack);

    return 0;
}