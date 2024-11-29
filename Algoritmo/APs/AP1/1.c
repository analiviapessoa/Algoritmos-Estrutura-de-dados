#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int tamanho, int l, int r) 
{ 
    int temp[tamanho];

    for (int i = l ; i <= r ; i++){

        temp [i] = arr [i];
    }
        
    int m = (l + r)/2;
    int i1 = l;
    int i2 = m + 1;

    for (int curr = l ; curr <= r ; curr++){
        if (i1 == m + 1){
            arr[curr] = temp [i2++];
        }
        else if (i2 > r){
            arr[curr] = temp [i1++];
        }
        else if (temp[i1] <= temp [i2]){
            arr[curr] = temp [i1++];
        }
        else{
            arr[curr] = temp [i2++];
        }
    }
} 

void mergeSort(int arr[], int tamanho, int l, int r) 
{ 
    if (l < r) { 

        int m = (l + r) / 2; 
   
        mergeSort(arr, tamanho, l, m); 
        mergeSort(arr, tamanho, m + 1, r); 
  
        merge(arr, tamanho, l, r); 
    } 
} 

int main(){

    int c;

    scanf ("%d",&c);

    int n;

    for (int i=0;i<c;i++){

        scanf ("%d",&n);

        int a[n];

        for (int i=0;i<n;i++){

            scanf("%d",&a[i]);

        }

        mergeSort(a,n,0,n-1);
        
        for (int i=0;i<n;i++){

            printf("%d ",a[i]);
        }
        printf("\n");
    }

    return 0;
}