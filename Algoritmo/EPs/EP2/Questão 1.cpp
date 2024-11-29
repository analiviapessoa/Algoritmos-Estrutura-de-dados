#include <iostream>
#include <string>

using namespace std;

struct Link{
    int element;
    Link *next;
};
typedef struct Link Link;

Link* create_header(Link* nextval){
    Link *n = (Link* )malloc(sizeof(Link));
    (n -> next) = nextval;
    return n;
}

Link* create_link(int it, Link* nextval){
    Link *n = (Link* )malloc(sizeof(Link));
    (n -> element) = it;
    (n -> next) = nextval;
    return n;
}

struct queue {
    Link* front;  
    Link* rear;     
    int size;      
};
typedef struct queue queue;

queue* create_queue(){
    queue *q = (queue* )malloc(sizeof(queue));

    (q -> front) = create_header(NULL); 
    (q -> rear) = (q -> front);        
    (q -> size) = 0;

    return q;
}

void add (queue *q, int it){
    (q -> rear) -> next = create_link (it, NULL);  
    (q -> rear) = (q -> rear) -> next;

    (q -> size)++;
}

int solve (queue *q){
    if ((q -> size) != 0){

        int it = ((q -> front) -> next) -> element; 
        Link* temp = ((q -> front) -> next); 

        (q -> front) -> next = ((q -> front) -> next) -> next;  

        if (((q -> front) -> next) == NULL){
            (q -> rear) = (q -> front);
        }

        (q -> size)--;
        free(temp);

        return it;  
    }
    else{
        return -1;
    }
}

void print (queue* q){
    Link* temp = (q -> front);

    while (temp -> next != NULL){
        if ((temp -> next -> element)!= (q -> rear)-> element){
            cout << (temp -> next -> element) << " ";
            temp = temp -> next;
        }
        else{
            cout << (temp -> next -> element);
            temp = temp -> next;
        }
    }
    cout << endl;
}

int main(){

    queue* fila = create_queue();

    string operacao;
    int resolvidas = 0;
    int faltam = 0;

    cin >> operacao;

    while(operacao != "end"){
        int numero;

        if (operacao == "add"){
            cin >> numero;
            add(fila, numero);
            faltam++;
        }
        else if (operacao == "solve"){
            if (solve(fila) != -1){
                resolvidas++;
                faltam--;
            }
        }
        else if (operacao == "print"){
            if (fila->size == 0){
                cout << "x" << endl;
            }
            else{
                print(fila);
            }
        }
        else if (operacao == "stats"){
            cout << resolvidas << " " << faltam << endl;
        }

        cin >> operacao;
    }

    return 0;
}