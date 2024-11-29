#include <bits/stdc++.h>
using namespace std;

int frog (int N, int K, vector<int>& heights){
    vector<int> dp (N, INT_MAX);
    dp[0] = 0;

    for (int i = 0 ; i < N ; i++){          
        for (int j = 1 ; j <= K ; j++){      
            if (i + j < N){         
                int custo = abs(heights[i] - heights[i+j]);
                dp[i+j] = min(dp[i+j], dp[i] + custo);
            }
        }
    }
    return dp[N-1];

}

int main(){

    int N,K;    //stones
    cin >> N >> K;

    vector<int> heights(N);

    for (int i = 0 ; i < N ; i++){
        int height;
        cin >> height;

        heights[i] = height;
    }

    cout << frog(N,K,heights);

    return 0;
}