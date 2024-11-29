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

struct queue {
    Link* front;    //início da fila
    Link* rear;     //final da fila
    int size;       //tamanho da fila
};

typedef struct queue queue;

queue* create_queue(){
    queue *q = (queue* )malloc(sizeof(queue));

    (q -> front) = create_header(NULL);  //início aponta para o header
    (q -> rear) = (q -> front);         //final aponta pra o header
    (q -> size) = 0;

    return q;
}

void enqueue (queue *q, int it){
    (q -> rear) -> next = create_link (it, NULL);  //cria um novo nó apontando para NULL
    //o nó para quem o rear está apontando passa a apontar para o novo nó
    (q -> rear) = (q -> rear) -> next;  //o rear começa a apontar pro novo nó

    (q -> size)++;
}

int dequeue (queue *q){
    if ((q -> size) == 0){
        return -1;
    }

    int it = ((q -> front) -> next) -> element; //elemento apontado pelo front (primeiro)
    Link* temp = ((q -> front) -> next); 

    (q -> front) -> next = ((q -> front) -> next) -> next;  //front começa a apontar para o segundo elemento

    if (((q -> front) -> next) == NULL){
        (q -> rear) = (q -> front);
    }

    (q -> size)--;
    free(temp);

    return it;  //retorna o elemento removido
}

int frontValue(queue *q){
    if ((q -> size) == 0){
        return -1;
    }
    return (((q -> front)->next) -> element);
}

int length (queue *q){
    return (q -> size);
}

void clear(queue *q){
    Link* temp;

    while ((q -> front) -> next != NULL){
        temp = (q -> front) -> next;
        (q -> front) = (q -> front) -> next;
        free(temp);
    }
    (q -> front) -> next = NULL;
    q -> rear = q -> front;
    (q -> size) = 0;
}

void print_queue(queue* q){
    Link* temp = (q -> front)-> next;

    while (temp != NULL){
        cout << (temp -> element) << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    queue* queue = create_queue();

    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    enqueue(queue,4);
    enqueue(queue,5);
    print_queue(queue);

    dequeue(queue);
    print_queue(queue);

    cout << frontValue(queue) << endl;

    cout << length(queue) << endl;

    clear(queue);
    print_queue(queue);

    return 0;
}