/*Atividade: Calcular o produto de duas matrizes
Lê três inteiros positivos M N P no intervalo (2, 10)
Cria duas matrizes aleatórias A e B de dimensões MxN e NxP com valores no intervalo (-100, +100)
Calcula a matriz produto C = A*B de dimensões MxP
Imprime a matrizes A, B, C*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int M=0, N=0, P=0;

    while(M<2 || M>10){
        cin >> M;
    }

    while(N<2 || N>10){
        cin >> N;
    }

    while(P<2 || P>10){
        cin >> P;
    }

    int matrizA[M][N], matrizB[N][P];

    for (int i = 0 ; i < M ; i++){
        for (int j = 0 ; j < N ; j++){
            matrizA[i][j] = rand()%101;
        }
    }

    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < P ; j++){
            matrizB[i][j] = rand()%101;
        }
    }

    cout <<"Matriz A: " << endl;
    for (int i = 0 ; i < M ; i++){
        for (int j = 0 ; j < N ; j++){
            cout << matrizA[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;

    cout <<"Matriz B: " << endl;
    for (int i = 0 ; i < N ; i++){
        for (int j = 0 ; j < P ; j++){
            cout << matrizB[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}