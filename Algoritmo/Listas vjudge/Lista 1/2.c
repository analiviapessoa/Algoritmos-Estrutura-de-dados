#include <stdio.h>
#include <stdlib.h>

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

int contagem(int a[],int n,int k){

    int cont=0,i=0,j=0;

    while (i<n){
        int diferenca = abs(a[i]-a[j]);
            if (diferenca == k){
                cont++;
                i++;
            }
            else if (diferenca > k){
                j++;
            }
            else{
                i++;
            }
    }
    return cont;
}

int main() {

    int n,k;

    scanf("%d %d",&n,&k);

    int array[n];

    for (int i = 0 ; i<n ; i++){
        scanf("%d",&array[i]);
    }

    quicksort(array,0,n-1);

    printf("%d",contagem(array,n,k));

    return 0;
}
