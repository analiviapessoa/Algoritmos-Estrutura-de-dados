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

    vector<int> H = {0, 3, 4, 1, 5, 2};
    int n = H.size();

    cout << "Array before heapification: ";
    print_heap(H);

    cout << "Array after heapification: ";
    HeapBottomUp(H);
    print_heap(H);

    cout << "Heap after heapsort: ";
    HeapSort(H);
    print_Sort(H);

    cout << "Array after each deletionMIN: " << endl;
    for (int i = 1 ; i < n ; i++){
        deletionMIN(H);
        print_heap(H);
    }

    return 0;
}