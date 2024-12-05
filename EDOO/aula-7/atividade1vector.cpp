/*Atividade: Reverter um vetor de inteiros
- Lê do teclado o tamanho do array (N <= 100)
- Cria um array aleatório em ordem crescente com valores entre 0 e 1000 (usar função rand())
- Imprime o array original
- Inverte o array
- Imprime o array invertido*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> arr(n);
    
    for (int i = 0 ; i < n ; i++){
        arr[i] = rand()%1001;
    }

    cout << "Array original: ";
    for (int j = 0 ; j < n ; j++){
        cout << arr[j] << " ";
    }
    cout << endl;

    cout << "Array invertido: ";
    for (int k = n-1 ; k >= 0 ; k--){
        cout << arr[k] << " ";
    } 
    cout << endl;   

    return 0;
}