#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_heap (vector<char>& H){
    for (int i = 1 ; i < H.size() ; i++){
        cout << H[i] << " ";
    }
    cout << endl;
}

void TopDown (vector<char>& H){
    int n = H.size() - 1;

    for (int i = n/2 ; i>=1 ; i--){
        
        int k = i;
        int v = H[k];
        bool heap = false;

        while (!heap && 2*k <= n){
            int j = 2*k;

            if (j<n && H[j] < H[j+1]){
                j = j + 1;
            }
            if (v >= H[j]){
                heap = true;
            }
            else{
                H[k] = H[j];
                k=j;
            }
        }

        H[k] = v;
    }
}

void insert (vector<char>& H, char valor, int n){

    if (H.size() >= n){
        cout << "Tamanho maximo atingido!" << endl;
    }
    else{
        H.push_back(valor);
        TopDown(H);
    }
}

void remove (vector<char>& H){
    if (H.size()<=1){
        cout << "Heap vazia." << endl;
    }
    else{
        H.erase(H.begin());
        TopDown(H);
    }
}

void max (vector<char>& H){
    if (H.size()<=1){
        cout << "Nao ha elemento no topo." << endl;
    }
    else{
        cout << H[1] << endl;
    }
}

int main(){

    int n,m;
    cin >> n >> m;

    vector<char> H = {NULL};

    for (int i = 0 ; i < m ; i++){

        string operacao;
        char valor;
        cin >> operacao;

        if (operacao == "insert"){
            cin >> valor;
            insert(H,valor,n);
        }
        else if (operacao == "remove"){
            remove(H);
        }
        else if (operacao == "max"){
            max(H);
        }

    }

    return 0;
}