#include <iostream>
#include <string>
using namespace std;

class aviao{

    public:
        int velocidade_atual = 0;
        int velocidade_maxima;
        string tipo;
        void ini (int tip);

    private:

};

void aviao::ini(int tip){
    if (tip == 1){
        this -> velocidade_maxima = 800;
        this -> tipo = "jato";
    }
    else if (tip == 2){
        this -> velocidade_maxima = 350;
        this -> tipo = "Monomotor";
    }
    else if (tip == 3){
        this -> velocidade_maxima = 180;
        this -> tipo = "planador";
    }

}

int main(){

    aviao *av1 = new aviao();
    aviao *av2 = new aviao();

    av1 -> ini(1);
    av2 -> ini(2);

    cout << av1 -> velocidade_maxima << endl;
    cout << av2 -> velocidade_maxima << endl;

    return 0;
}