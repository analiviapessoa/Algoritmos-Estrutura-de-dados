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

void enqueue (queue *q, int it){
    (q -> rear) -> next = create_link (it, NULL);
    (q -> rear) = (q -> rear) -> next; 

    (q -> size)++;
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

    int t; 
    cin >> t;

    for (int i = 0 ; i < t ; i++){
        int n,segundo=0;  
        cin >> n;
        queue* fila = create_queue();

        for (int j = 0 ; j < n ; j++){
            int l, r;  
            cin >> l >> r;
            
            if (segundo < l){
                segundo = l;
                enqueue(fila,l);
            }
            else if (segundo < r){
                segundo++;
                enqueue(fila,segundo);
            }
            else{
                enqueue(fila,0);
            }
        }
        print_queue(fila);
    }

    return 0;
}