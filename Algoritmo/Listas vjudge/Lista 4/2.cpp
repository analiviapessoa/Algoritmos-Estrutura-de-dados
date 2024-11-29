#include <iostream>
#include <vector>
using namespace std;

void HeapBottomUp (vector<int>& H){

    int n = H.size() - 1;

    for (int i = n/2 ; i>=1 ; i--){
        
        int k = i;
        int v = H[k];
        bool heap = false;

        while (!heap && 2*k <= n){
            int j = 2*k;

            if (j<n && H[j] > H[j+1]){
                j = j + 1;
            }
            if (v <= H[j]){
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

int deletionMIN (vector<int>& H){
    int n = H.size() - 1;

    if (n < 1){
        return -1;
    } 

    int minimo = H[1];
    H[1] = H.back();
    H.pop_back();
    n--;

    int k = 1;
    int v = H[k];
    bool heap = false;

    while (!heap && 2*k <= n){
        int j = 2*k;

        if (j<n){
            if (H[j] > H[j + 1]){
                j = j + 1;
            }
        }
        if (v <= H[j]){
            heap = true;
        }
        else{
            H[k] = H[j];
            k = j;
        }
    }

    if (n >= 1){
        H[k] = v;
    }

    return minimo;
}

void insert (vector<int>& H, int n){
    H.push_back(n);
    HeapBottomUp(H);
}

int main(){
    int n;

    while (cin >> n && n!=0){
        int v1,v2,soma;
        int custominimo = 0;

        if (n!=0){

            vector<int> H(n+1);

            for (int i = 1 ; i <= n ; i++){

               cin >> H[i]; 

            }

            HeapBottomUp(H);

            while (H.size() > 2){
                
                v1 = deletionMIN(H);
                v2 = deletionMIN(H);

                soma = v1 + v2;

                insert(H,soma);

                custominimo += soma;
            }

            cout << custominimo << endl;
        }
    }

    return 0;
}