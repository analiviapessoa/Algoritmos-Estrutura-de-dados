#include <iostream>
#include "3get_set.h"
using namespace std;

int main(){

    veiculo *v1 = new veiculo(1);    //1º veículo é a classe, 2º veículo é o construtor
    veiculo *v2 = new veiculo(2);
    veiculo *v3 = new veiculo(3);

    v1 -> setLigado(1);

    cout << v1 -> getVelMax() << endl;
    cout << v2 -> getVelMax() << endl;
    cout << v3 -> getVelMax() << endl;

    if (v1 -> getLigado()){
        cout << "Veículo 1 está ligado" << endl;
    }else{
        cout << "Veículo 1 está desligado" << endl;
    }

    if (v2 -> getLigado()){
        cout << "Veículo 2 está ligado" << endl;
    }else{
        cout << "Veículo 2 está desligado" << endl;
    }

    if (v3 -> getLigado()){
        cout << "Veículo 3 está ligado" << endl;
    }else{
        cout << "Veículo 3 está desligado" << endl;
    }

    return 0;
}