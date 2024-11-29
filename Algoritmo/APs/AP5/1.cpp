#include <iostream>
#include <string>

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

int main(){

    stack* stack = create_stack();

    int c;
    cin >> c;

    for (int i = 0 ; i < c ; i++){
        cout << "Caso " << i+1 << ":" << endl;

        string operacao;
        int numero;

        while(operacao != "end"){

            cin >> operacao;

            if(operacao == "push"){
                cin >> numero;
                push(stack,numero);
            }
            else if (operacao == "pop"){
                cin >> numero;
                int soma = 0;

                for (int j = 0 ; j < numero ; j++){
                    soma += stack -> top -> element;
                    pop(stack);
                }
                cout << soma << endl;
            }
        }
    }
    return 0;
}