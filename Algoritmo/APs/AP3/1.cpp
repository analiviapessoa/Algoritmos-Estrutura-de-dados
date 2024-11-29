#include <iostream>
#include <string>

using namespace std;

struct List {
    int maxSize;        
    int listSize;       
    int curr;          
    int* listArray;   
};

typedef struct List List; 

List* create_list (int size){  

    List *lista = (List* ) malloc (sizeof(List));
    
    lista -> maxSize = size;
    lista -> listSize = 0;      
    lista -> curr = 0;          
    lista -> listArray = (int*) malloc (size * sizeof(int));

    return lista; 
}

void previous (List *lista){ 
    if ((lista -> curr) != 0){
        (lista -> curr)--;
    }
}

void next (List *lista){   
    if ((lista -> curr) < (lista -> listSize)){
        (lista -> curr)++;
    } 
}

void insert_list (List *lista,int numero){  
    
    if (lista -> listSize >= lista -> maxSize){ 
        exit(1);
    }

    int i = lista -> listSize;

    while (i > lista -> curr){
        lista -> listArray[i] = lista -> listArray[i-1]; 
        i--;
    }

    lista -> listArray[lista -> curr] = numero;
    lista -> listSize++;
}

int remove_list (List *lista){  
    if ((lista -> curr) < 0 || (lista -> curr) >= (lista -> listSize)){
        return -1;
    }
    
    int numero = (lista -> listArray) [(lista -> curr)]; 
    int i = (lista -> curr);

    while (i < (lista -> listSize) - 1){
        (lista -> listArray)[i] = (lista -> listArray)[i+1]; 
        i++;
    }

    (lista -> listSize)--;

    return numero;
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

int main(){

    List *novalista = create_list(5);

    int c;
    cin >> c;

    for (int i = 0 ; i < c ; i++){

        cout << "Caso " << i+1 << ":\n";
        
        int n;
        cin >> n;

        for (int j = 0 ; j < n ; j++){

            string operacao;
            int numero;

            cin >> operacao;

            if (operacao == "insert"){
                cin >> numero;
                insert_list(novalista,numero);
            }
            else if (operacao == "remove"){
                remove_list(novalista);
            }
            else if (operacao == "prev"){
                previous(novalista);
            }
            else if (operacao == "next"){
                next(novalista);
            }
            else if (operacao == "count"){
                cin >> numero;
                cout << count (novalista,numero) << endl;
            }
        }

    }
    
    delete(novalista->listArray);
    delete(novalista);

    return 0;
}