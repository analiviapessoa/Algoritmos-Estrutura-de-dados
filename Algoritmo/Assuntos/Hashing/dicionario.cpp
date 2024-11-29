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

int hashfold(string &key, int m) {
    int soma = 0;
    for (char ch : key) {
        soma += ch; 
    }
    return abs(soma) % m;
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

int find (dicionario *d, string &k, int array[], int size){
    int i = hashfold(k, d->m);
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

void insert (dicionario *d, string &k, int array[], int size){
    
    int i = hashfold(k, d->m);
    int p = 1;
    
    if (find(d,k,array,size) == -1){
        if (!d->H[i].ocupado){
            d->H[i].chave = k;
            d->H[i].ocupado = true;
            d->cnt++;
        }
        else{
            while (p < size + 1){
                int novaposicao = probing(array, p);
                int index = (i + novaposicao) % (d->m);
                if (!d -> H[index].ocupado){
                    d->H[index].chave = k;
                    d->H[index].ocupado = true;
                    d->cnt++;
                    break;
                }
                p++;
            }
        }
        
    }
}

void remove (dicionario *d, string &k, int array[], int size){
    int index = find(d,k,array,size);
    if (index != -1){
        d->H[index].ocupado = false;
        d->cnt--;
    }
}

int main() {

    int m;
    cin >> m;
    
    dicionario* dict = create_dict(m);

    string comando, str;

    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    while (cin >> comando && comando != "fim") {
        cin >> str;
        if (comando == "add") {
            insert(dict, str, array, size);
        } else if (comando == "rmv") {
            remove(dict, str, array, size);
        } else if (comando == "sch") {
            int index = find(dict, str, array, size);
            if (index != -1) {
                cout << str << " " << index << endl;
            } else {
                cout << str << " -1" << endl;
            }
        }
    }

    delete[] dict->H;
    delete dict;

    return 0;
}