#include <iostream>
#include <vector>
#include <list>
using namespace std;

//hash function
void h (vector<list<int>>& hashtable, int valor){//&: passagem por referência, modifica diretamente, + eficiente, não é uma cópia
    int indice = valor % 10;
    hashtable[indice].push_back(valor); 
}  

void printar_tabela (vector<list<int>> tabela, int tamanho){
    for (int i = 0 ; i < tamanho ; i++){
        cout << i << " ";         //chaves

        for (int j:tabela[i]){      
            cout << j << " ";    //valores
        }
        cout << endl;
    }
}

int main(){

    int n;
    cin >> n;

    vector<list<int>> tabela(10);   //inicializar tabela de tamanho 10

    for (int i = 0 ; i < n ; i++){
        int v;
        cin >> v;
        h(tabela,v);   
    }

    printar_tabela(tabela,10);

    return 0;
}