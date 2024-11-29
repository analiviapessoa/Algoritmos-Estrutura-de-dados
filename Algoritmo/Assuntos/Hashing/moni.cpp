#include <iostream>
#include <string>
using namespace std;

//hash function
int h (string key){
    int sum = 0;
    for (int i = 0 ; i < key.size() ; i++){
        sum += 42 * key[i] * (i + 1);
    }
    return sum%200;
}

//hash table
typedef struct{
    int m;                 //quantidade máxima de elementos na hashtable
    int cnt;               //quantidade atual de elementos na hashtable
    Hashtable *table;             //hashtable
    int *perm;             //vetor da colisão
    int *ocupado;     //vetor ocupado ou não (int ou bool)
}Hashtable;

//alocar um vetor com todas as posições preenchidas com zero
int *ptr = (int *)calloc(4,sizeof(int));
int *ptr = new int [4]();
//ambos alocam um vetor de quatro elementos de int 