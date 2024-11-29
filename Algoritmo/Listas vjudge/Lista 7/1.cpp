#include <bits/stdc++.h>
using namespace std;

void preencher_tabuleiro(int i, int skip, int adicionar, vector<vector<bool>>& tabuleiro) {
    for (int j = skip; j < skip + adicionar; j++) {
        tabuleiro[i][j] = true;
    }
}

const vector<pair<int, int>> movimentos = { 
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
};

bool checar_valido(int i, int j, const vector<vector<bool>>& tabuleiro) {
    return (i >= 0 && i < 10 && j >= 0 && j < 10 && tabuleiro[i][j] == true);
}

void cavalo(int x, int y, vector<vector<bool>>& tabuleiro, vector<vector<bool>>& visited, int& squares_visitados, int contador) {
    visited[x][y] = true;
    squares_visitados = max(squares_visitados, contador);
    
    for (int i = 0 ; i < movimentos.size() ; i++) { 
        int nx = x + movimentos[i].first;
        int ny = y + movimentos[i].second;
        if (checar_valido(nx, ny, tabuleiro) && !visited[nx][ny]) {
            cavalo(nx, ny, tabuleiro, visited, squares_visitados, contador + 1);
        }
    }
    
    visited[x][y] = false; 
}

int main() {

    int n_linhas, cont = 0;

    while (cin >> n_linhas) {

        if(n_linhas == 0){
            break;
        }

        cont++;
        vector<vector<bool>> tabuleiro(10, vector<bool>(10, false)); 
        int squares_totais = 0; 
        int squares_visitados = 0; 

        for (int i = 0; i < n_linhas; ++i) {
            int squares_skipped, squares_na_linha;
            cin >> squares_skipped >> squares_na_linha;
            
            preencher_tabuleiro(i, squares_skipped, squares_na_linha, tabuleiro);
            squares_totais += squares_na_linha;
        }

        vector<vector<bool>> visited(10, vector<bool>(10, false)); 

        if (tabuleiro[0][0]) { 
            cavalo(0, 0, tabuleiro, visited, squares_visitados, 1);
        }
        
        int n_squares = squares_totais - squares_visitados; 
        cout << "Case " << cont << ", " << n_squares;
        if (n_squares == 1) {
            cout << " square can not be reached." << endl;
        } else {
            cout << " squares can not be reached." << endl;
        }
    }
    
    return 0;
}
