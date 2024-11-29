#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Entry {
    string chave;  
    bool ocupado;
    bool removido;

    Entry(): chave(""), ocupado(false), removido(false) {}
};
typedef struct Entry Entry;

struct dicionario{  
    int m;        
    int cnt;       
    Entry *H;        
};
typedef struct dicionario dicionario;

int hashfold(string &key) {
    int soma = 0;
    for (int i = 0 ; i < key.length() ; i++) {
        soma += key[i]* (i+1); 
    }
    return abs(19*soma) % 101;
}

dicionario *create_dict (int size){  
    dicionario *d = new dicionario;
    d -> m = size;
    d -> cnt = 0;
    d -> H = new Entry [size];
    
    return d;
}

int probing(int i, int j) {
    return (i + j * j + 23 * j) % 101;
}

int find (dicionario *d, string &k){
    int i = hashfold(k);

    for (int j = 0 ; j <= 19 ; j++){
        int index = probing(i,j);

        if (d->H[index].ocupado && !d->H[index].removido && d->H[index].chave == k){
            return index;
        }
        if (!d->H[index].ocupado && !d->H[index].removido){
            break;
        }
    }
    return -1;
}

void insert (dicionario *d, string &k){
    if (find(d,k) != -1) return;

    int i = hashfold(k);

    for (int j = 0 ; j <=19 ; j++){

        int index = probing(i,j);

        if (!d->H[index].ocupado || d->H[index].removido){
            d->H[index].chave = k;
            d->H[index].ocupado = true;
            d->H[index].removido = false;
            d->cnt++;
            return;
        }
    }
}

void remove (dicionario *d, string &k){
    int index = find(d,k);
    
    if (index != -1){
        d->H[index].ocupado = false;
        d->H[index].chave = "";
        d->H[index].removido = true;
        d->cnt--;
    }
}

int main(){

    int t;
    cin >> t;

    for (int i = 0 ; i < t ; i++){
        int n;
        cin >> n;

        dicionario *d = create_dict(101);

        for (int j = 0 ; j < n ; j++){
            string operacao, valor;
            cin >> operacao;
            valor = operacao.substr(4);

            if (operacao.substr(0,3) == "ADD"){
                insert(d,valor);
            }
            else if (operacao.substr(0,3)=="DEL"){
                remove(d,valor);
            }
        }

        cout << d->cnt << endl;

        for (int i = 0 ; i < d-> m ; i++){
            if (d->H[i].ocupado && !d->H[i].removido){
                cout << i << ":" << d->H[i].chave << endl;
            }
        }

        delete[] d->H;
        delete d;
    }

    return 0;
}