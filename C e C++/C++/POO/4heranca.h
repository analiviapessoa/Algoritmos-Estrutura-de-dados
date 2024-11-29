#ifndef HERANCA_H_INCLUDED
#define HERANCA_H_INCLUDED

class veiculo{
    public:
        int vel;
        int blind;
        int rodas;
        void setTipo (int tip);
        void setVelMax (int vm);
        void setArma (bool ar);
        void printar();
    private:
        int tipo;
        int velMax;
        bool arma;
};

void veiculo::setTipo(int tip){
    tipo = tip;
}

void veiculo::setVelMax(int vm){
    velMax = vm;
}

void veiculo::setArma(bool ar){
    arma = ar;
}

void veiculo::printar(){
    std::cout <<"Tipo: " << tipo << std::endl;
    std::cout <<"Velocidade máxima: " << velMax << std::endl;
    std::cout <<"Rodas: " << rodas << std::endl;
    std::cout <<"Blindagem: " << blind << std::endl;
    std::cout <<"Armamento: " << arma << std::endl;
}

class moto:public veiculo{     //classe que herda todos os elementos da classe veículo
    public:
        moto();                //método construtor
};

moto::moto(){
    vel = 0;
    blind = 0;
    rodas = 2;
    setTipo(1);
    setVelMax(120);
    setArma(false);
}

class carro:public veiculo{
    public:
        carro();
};

carro::carro(){
    vel = 0;
    blind = 0;
    rodas = 4;
    setTipo(2);
    setVelMax(180);
    setArma(false);
}

class tanque:public veiculo{
    public:
        tanque();
};

tanque::tanque(){
    vel = 0;
    blind = 1;
    rodas = 8;
    setTipo(4);
    setVelMax(200);
    setArma(true);
}

#endif //HERANCA_H_INCLUDED