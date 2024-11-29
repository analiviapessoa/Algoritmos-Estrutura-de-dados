#include <stdio.h> 
  
int partition(int a[],int l,int r){
    int pivo=a[l];
    int i=l;
    int j=r+1;
    int temp;

    do{
        do{

            i++;

        }while (a[i]<pivo && i<r);

        do{
            j--;

        }while(a[j]>pivo);

        temp=a[i];
        a[i]=a[j];
        a[j]=temp;

    }while (i<j);

    temp=a[i];
    a[i]=a[j];
    a[j]=temp;

    temp=a[l];
    a[l]=a[j];
    a[j]=temp;

    return j;
}
  
void quicksort(int a[],int l,int r){

    if (l<r){
        int posicao_part = partition(a,l,r);
        quicksort(a,l,posicao_part-1);
        quicksort(a,posicao_part+1,r);
    }
}

int main() 
{ 
    int arr[] = { 19, 17, 15, 12, 16, 18, 4, 11, 13 }; 
    int tamanho = sizeof(arr) / sizeof(arr[0]); 

    quicksort(arr, 0, tamanho - 1); 
  
    printf("\nSorted array: "); 
    for (int i = 0; i < tamanho; i++) { 
        printf("%d ", arr[i]); 
    } 
  
    return 0; 
}