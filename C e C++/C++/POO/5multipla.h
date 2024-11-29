#ifndef MULTIPLA_H_INCLUDED
#define MULTIPLA_H_INCLUDED
#include <iostream>

class base1{
    public:
        void printBase1();
};

void base1::printBase1(){
    std::cout << "Imp classe base1" << std::endl;
}

class base2{
    public:
        void printBase2();
};

void base2::printBase2(){
    std::cout << "Imp classe base2" << std::endl;
}

class CFB:public base1, public base2{   //herda características das duas classes
};

#endif //MULTIPLA_H_INCLUDED