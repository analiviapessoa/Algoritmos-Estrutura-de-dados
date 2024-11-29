#include <stdio.h>
#include <math.h>

int main() {

    int n, m, q, a[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n;i++){
        printf("%d",a[i]);
    }
    scanf("%d", &m);
    scanf("%d", &q);

    return 0;
}