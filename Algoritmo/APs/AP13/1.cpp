#include <bits/stdc++.h>
using namespace std;

bool valid (int n, vector<vector<int>>& M, int l, int i){
    //verificando na vertical
    for (int j = 0 ; j < l ; j++){
        if (M[j][i] == 1){
            return false;
        }
    }
    //verificando a diagonal principal
    for (int j = 1 ; j <= min(l,i) ; j++){
        if (M[l-j][i-j] == 1){
            return false;
        }
    }    
    //verificando a diagonal secundária
    for (int j = 1 ; j <= min(l,n-i-1) ; j++){
        if (M[l-j][i+j] == 1){
            return false;
        }
    }  
    return true;
}

void qns (int n, int l, vector<vector<int>>& M, vector<vector<vector<int>>>& solutions){

    if (l == n){
        solutions.push_back(M);
    }

    else{
        for (int i = 0 ; i < n ; i++){

            if (valid(n,M,l,i)){

                M[l][i] = 1;
                qns(n,l+1,M,solutions);
                M[l][i] = 0;
            }
        }
    }
}

int main(){

    int N;
    cin >> N;

    vector<vector<int>> M(N, vector<int> (N,0));
    vector<vector<vector<int>>> solutions;

    qns(N,0,M,solutions);

    cout << solutions.size() << endl;
    for (int s = 0 ; s < solutions.size() ; s++) {
        cout << "Sol. " << s + 1 << ":" << endl; 
        for(int i = 0 ; i < N ; i++){
            for (int j = 0 ; j < N ; j++){
                cout << solutions[s][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}