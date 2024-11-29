#include <stdio.h>
#include <math.h>

int main(){
    
    double pn,pa;
    pn = pow(10,5);
    pa = pow(10,9);

    int n,a[100],m,q[100];
    
    scanf("%d",&n);

    if (n>=2 && n<=3*pn){
        for (int i=0;i<n;i++){

            scanf("%d",&a[i]);    
        }
    }

    scanf("%d",&m);

    if (m>=1 && m<=n-1){
        for (int j=0;j<m;j++){

            scanf("%d",&q[j]);    
        }
    } 

    return 0;
}

//if (a>=1 && a<=pa){
//}
//if (q>=2 && q<=n){
//}