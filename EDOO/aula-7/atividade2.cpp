#include <bits/stdc++.h>
using namespace std;

int main(){

    int M, N, P;
    while (M <= 2 || M >= 100){
        cin >> M;
    }

    while (N <= 2 || N >= 100){
        cin >> N;
    }

    while (P <= 2 || P >= 100){
        cin >> P;
    }

    int matrizA[M][N];

    for (int i = 0 ; i < M ; i++){
        for (int j = 0 ; j < N ; j++){
            cin >> matrizA[i][j]; 
        }
    }


    int matrizB[N][P];

    return 0;
}

/*Atividade: Calcular o produto de duas matrizes
Lê três inteiros positivos M N P no intervalo (2, 10)
Cria duas matrizes aleatórias A e B de dimensões MxN e NxP com valores no intervalo (-100, +100)
Calcula a matriz produto C = A*B de dimensões MxP
Imprime a matrizes A, B, C*/