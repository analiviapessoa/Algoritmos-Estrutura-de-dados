#include <iostream>
#include <string>
using namespace std;

//lista
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

//hash function
int h (string key){
    int sum = 0;
    for (int i = 0 ; i < key.size() ; i++){
        sum += 42 * key[i] * (i + 1);
    }
    return sum%200;
}

//fold: string é dividida em partes de tamanho fixo que são combinadas e a soma de seus valores formam um valor hash.
int hfold (string key, int m){       //m = tamanho da hash table
    int s = key.length();
    int soma = 0;

    for (int i = 0 ; i < s-1 ; i++){
        soma = soma + key[i];
    }

    return abs(soma)%m;
}

//sfold: variante da técnica de folding, usa deslocamento bit a bit (bitwise shifting). É mais eficiente.
int hsfold (string key, int m){
    int s = key.length()/4;
    int soma = 0;

    for (int i = 0 ; i < s-1 ; i++){
        string sub = key.substr (i*4, (i*4) + 4);
        int mult = 1;

        for (int j = 0 ; j < 3 ; j++){
            soma = soma + sub[j] * mult;
            mult = mult *256;
        }
    }

    string sub = key.substr(s*4);
    int mult = 1;
    int s = sub.length();

    for (int j = 0; j < s-1 ; j++) {
        soma = soma + sub[j] * mult;
        mult = mult * 256;
    }

    return abs(soma)%m;
} 