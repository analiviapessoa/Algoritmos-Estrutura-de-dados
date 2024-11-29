#include <stdio.h> 
  
int partition(int a[],int l,int r){
    int pivo=a[l];
    int i=l;
    int j=r+1;
    int temp;

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
  
void quicksort(int a[],int l,int r){

    if (l<r){
        int posicao_part = partition(a,l,r);
        quicksort(a,l,posicao_part-1);
        quicksort(a,posicao_part+1,r);
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

        quicksort(a,0,n-1);
        
        for (int i=0;i<n;i++){

            printf("%d ",a[i]);
        }
        printf("\n");
    }

    return 0;
}