#include <bits/stdc++.h>
using namespace std;

int Knapsack (int n, int w, vector<int>& weights, vector<int>& values){

    vector<vector<int>> F(n+1, vector<int>(w+1,0));
    
    for (int i = 0 ; i <= n ; i++){          
        for (int j = 0 ; j <= w ; j++){      
            if (i == 0 || j == 0){         
                F[i][j] = 0;
            }
            else if (weights[i-1] <= j){
                F[i][j] = max(F[i-1][j], values[i-1] + F[i-1][j-weights[i-1]]);
            }
            else{
                F[i][j] = F[i-1][j];
            }
        }
    }
    return F[n][w];
}

int main(){

    int S,N;        //capacity,items
    cin >> S >> N;

    vector<int> weights(N);
    vector<int> values(N);

    for (int i = 0 ; i < N ; i++){
        int size,value;
        cin >> size >> value;

        weights[i] = size;
        values[i] = value;
    }

    cout << Knapsack(N,S,weights,values);

    return 0;
}