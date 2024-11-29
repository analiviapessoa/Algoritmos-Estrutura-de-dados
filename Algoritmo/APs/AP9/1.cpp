#include <iostream>
#include <vector>
using namespace std;

void print_heap (vector<int>& H){
    for (int i = 1 ; i < H.size() ; i++){
        cout << H[i] << " ";
    }
    cout << endl;
}

void print_Sort (vector<int>& H){
    for (int i = H.size() - 1 ; i >= 1 ; i--){
        cout << H[i] << " ";
    }
    cout << endl;
}

void HeapBottomUp (vector<int>& H){

    int n = H.size() - 1;

    for (int i = n/2 ; i>=1 ; i--){
        
        int k = i;
        int v = H[k];
        bool heap = false;;

        while (!heap && 2*k <= n){
            int j = 2*k;

            if (j<n){
                if (H[j] > H[j+1]){
                    j = j + 1;
                }
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

void deletionMIN (vector<int>& H){
    int n = H.size() - 1;

    if (n < 1) return;

    H[1] = H[n];
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

}

void HeapSort (vector<int>& H){

    int n = H.size() - 1;

    if (n < 1) return;

    while (n>1){
        swap(H[1],H[n]);
        n--;

        int k = 1;
        int v = H[k];
        bool heap = false;

        while (!heap && 2*k <= n){
            int j = 2*k;

            if (j<n && H[j] > H[j + 1]){
                j = j + 1;
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
    }
}

int main(){

    int c;
    cin >> c;

    for (int i = 0 ; i < c ; i++){
        int n;
        cin >> n;

        vector<int> Heap(n+1);

        for (int j = 1 ; j <= n ; j++){
            cin >> Heap[j];
        }

        vector<int> copia = Heap;

        HeapBottomUp(Heap);
        print_heap(Heap);

        for (int k = 1 ; k < n ; k++){
            deletionMIN(Heap);
            print_heap(Heap);
        }

        HeapBottomUp(copia);
        HeapSort(copia);
        print_Sort(copia);

    }

    return 0;
}