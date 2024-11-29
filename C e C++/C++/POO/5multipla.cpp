#include <iostream>
#include "5multipla.h"

int main(){

    base1 *obj1 = new base1();
    base2 *obj2 = new base2();
    CFB *obj3 = new CFB();

    obj1 -> printBase1();
    obj2 -> printBase2();
    obj3 -> printBase1();
    obj3 -> printBase2();

    return 0;
}