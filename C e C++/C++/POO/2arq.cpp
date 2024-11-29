#include <iostream>
#include "2arq.h"
using namespace std;

int main(){

    aviao *av1 = new aviao(1);
    aviao *av2 = new aviao(2);
    aviao *av3 = new aviao(3);

    av1 -> printar();
    av2 -> printar();
    av3 -> printar();

    return 0;
}