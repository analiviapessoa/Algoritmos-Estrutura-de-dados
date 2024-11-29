#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Entry {
    string chave;  
    bool ocupado;

    Entry(): chave(""), ocupado(false) {}
};
typedef struct Entry Entry;

struct dicionario{  
    int m;        
    int cnt;       
    Entry *H;        
};
typedef struct dicionario dicionario;

int h (int chave, int mod){
    return chave%mod;
}

dicionario *create_dict (int size){  
    dicionario *d = new dicionario;
    d -> m = size;
    d -> cnt = 0;
    d -> H = new Entry [size];
    
    return d;
}

int probing (int array[], int p){
    return array[p-1];
}

int find (dicionario *d, int k, int array[], int size){
    int i = h(k, d->m);
    int p = 1;

    if (d->H[i].ocupado && d -> H[i].chave == k){
        return i;
    }
    else{
        while (p < size + 1){
            int novaposicao = probing(array, p);
            int index = (i + novaposicao) % (d -> m);
            if (d->H[index].ocupado && d -> H[index].chave == k){
                return index;
            }
            p++;
        }
    }
    return -1;
}

void insert (dicionario *d, int k, int e, int array[], int size){
    
    int i = h(k, d->m);
    int p = 1;
    
    if (find(d,k,array,size) == -1){
        if (!d->H[i].ocupado){
            d->H[i].chave = k;
            d->H[i].valor = e;
            d->H[i].ocupado = true;
            d->cnt++;
        }
        else{
            while (p < size + 1){
                int novaposicao = probing(array, p);
                int index = (i + novaposicao) % (d->m);
                if (!d -> H[index].ocupado){
                    d->H[index].chave = k;
                    d->H[index].valor = e;
                    d->H[index].ocupado = true;
                    d->cnt++;
                    break;
                }
                p++;
            }
        }
        
    }
}

void remove (dicionario *d, int k, int array[], int size){
    int index = find(d,k,array,size);
    if (index != -1){
        d->H[index].ocupado = false;
        d->cnt--;
    }
}

int main() {

    return 0;
}