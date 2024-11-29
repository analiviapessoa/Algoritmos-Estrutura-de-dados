#include <iostream>
#include <vector>
using namespace std;

void print_heap (vector<int>& H){
    for (int i = 1 ; i < H.size() ; i++){
        cout << H[i] << " ";
    }
    cout << endl;
}

void TopDown (vector<int>& H){
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

void insert (vector<int>& H, int valor){

    H.push_back(valor);

    TopDown(H);

}

void remove (vector<int>& H){

    H.erase(H.begin());
    TopDown(H);

}

int min (vector<int>& H){

    return H[1];

}

int main(){

    vector<int> H = {0};

    insert(H,2);
    insert(H,9);
    insert(H,7);
    insert(H,6);
    insert(H,5);
    insert(H,8);
    insert(H,10);
    print_heap(H);

    remove(H);
    remove(H);
    print_heap(H);

    cout << min(H);

    return 0;
}