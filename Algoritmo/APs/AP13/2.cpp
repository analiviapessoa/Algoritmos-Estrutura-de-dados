#include <bits/stdc++.h>
using namespace std;

void menorsubc (int n, int S, vector<int>& C){
    
    vector<vector<bool>> dp (n+1, vector<bool> (S+1,false));
    dp[0][0] = true;

    for (int i = 1 ; i <= n ; i++){
        for (int j = 0 ; j<= S ; j++){
            dp[i][j] = dp[i-1][j];

            if (j >= C[i-1] && dp[i-1][j-C[i-1]]){
                dp[i][j] = true;
            }
        }
    }

}

int main(){

    int n,S;        //elementos, soma
    cin >> n >> S;

    vector<int> C(n);
    for (int i = 0 ; i < n ; i++){
        int elementos;
        cin >> elementos;

        C[i] = elementos;
    }

    return 0;
}