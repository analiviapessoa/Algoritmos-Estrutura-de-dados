#ifndef GET_SET_H_INCLUDED
#define GET_SET_H_INCLUDED

class veiculo{
    public:                     //pode ser alterado em outro arquivo
        int velocidade_atual;
        veiculo(int tip);       //método construtor: chamado ao instanciar um novo objeto na classe
        int getVelMax();        //permite acessar um valor privado
        bool getLigado();
        void setLigado(int l);

    private:                    //só permite alterar dentro da classe
        std::string nome;
        int velocidade_maxima;
        bool ligado;
        void setVelMax(int vm); //permite alterar um objeto
};

void veiculo::setLigado(int l){
    if (l == 1){
        ligado = true;
    }
    else if (l == 0){
        ligado = false;
    }
}

bool veiculo::getLigado(){
    return ligado;
}

int veiculo::getVelMax(){       
    return velocidade_maxima;
}

void veiculo::setVelMax(int vm){
    velocidade_maxima = vm;
}

veiculo::veiculo(int tip){
    if (tip == 1){
        nome = "carro";
        setVelMax (200);
    }
    else if (tip == 2){
        nome = "aviao";
        setVelMax (800);
    }
    else if (tip == 3){
        nome = "navio";
        setVelMax (120);
    }
    setLigado(0);

}

#endif //GET_SET_H_INCLUDED