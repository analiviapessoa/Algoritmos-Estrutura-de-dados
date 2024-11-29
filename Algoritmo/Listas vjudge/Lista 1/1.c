#include <stdio.h> 
  
int partition(long long int a[],int l,int r){
    long long int pivo=a[l];
    int i=l;
    int j=r+1;
    long long int temp;

    do{
        do{

            i++;

        }while (a[i]>pivo && i<r);

        do{
            j--;

        }while(a[j]<pivo);

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

void quicksort(long long int a[],int l,int r){

    if (l<r){
        int posicao_part = partition(a,l,r);
        quicksort(a,l,posicao_part-1);
        quicksort(a,posicao_part+1,r);
    }
}

long long int soma (long long int a[],long long int n){
    long long int soma = 0;

    for (int i = 0 ; i < n ; i++){
        soma += a[i];
    }
    return soma;
}

int main() 
{   
    long long int n;

    scanf("%lld",&n);

    long long int precos[n];

    for (int i = 0 ; i < n ; i++){
        scanf("%lld",&precos[i]);
    }

    quicksort(precos,0,n-1);
    long long int total = soma (precos,n);

    long long int m;

    scanf("%lld",&m);

    long long int quant[m];

    for (int i = 0 ; i < m ; i++){
        scanf("%lld",&quant[i]);
    }
    for (int i = 0 ; i < m ; i++){
        long long int valor=total;
        valor-=precos[quant[i]-1];
        printf("%lld\n",valor);
    }
}