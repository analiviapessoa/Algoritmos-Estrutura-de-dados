#include <iostream>
#include "4heranca.h"
using namespace std;

int main(){

    moto *v1 = new moto();
    v1 -> printar();

    cout << "\n";

    carro *v2 = new carro ();
    v2 -> printar();

    cout << "\n";

    tanque *v3 = new tanque ();
    v3 -> printar();

    return 0;
}