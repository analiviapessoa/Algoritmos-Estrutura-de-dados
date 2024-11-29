#include <stdio.h>
#include <math.h>
 
int main() {
 
    double pi = 3.14159,raio,quadrado,area;
    
    scanf("%lf",&raio);
    quadrado = pow(raio,2);
    area = pi*quadrado;
    
    printf("A=%lf",area);
 
    return 0;
}