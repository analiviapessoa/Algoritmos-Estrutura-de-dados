#include <stdio.h>
#include <stdlib.h>

int binarysearch(int a[],int l,int r,int k){
    
    if (r>=l){

        int m=(r+l)/2;

        if (k==a[m]){
            return m;
        }
        else if (k<a[m]){
            return binarysearch(a,l,m-1,k);
        }
        else if (k>a[m]){
            return binarysearch(a,m+1,r,k);
        }
    }
    else{
        return printf("x");
    }
}

int main() {

    int n;

    scanf ("%d",&n);

    int a[n];

    for (int i = 0 ; i < n ; i++){
        scanf ("%d",&a[i]);
    }

    int m;

    scanf("%d",&m);

    for (int i = 0 ; i < m ; i++){
        
        int v;

        scanf ("%d",&v);

        printf("%d\n",binarysearch(a,0,n-1,v));
    }

    return 0;
}