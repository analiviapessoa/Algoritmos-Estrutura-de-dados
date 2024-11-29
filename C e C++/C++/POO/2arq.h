#ifndef ARQ_H_INCLUDED
#define ARQ_H_INCLUDED

class aviao{

    public:
        int velocidade_atual;
        int velocidade_maxima;
        std::string tipo;
        aviao (int tip);
        void printar();
};

aviao::aviao(int tip){
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

void aviao::printar(){
    std::cout << "tipo: " << tipo << std::endl;
    std::cout << "velocidade máxima: " << velocidade_maxima << std::endl;
    std::cout << "velocidade atual: " << velocidade_atual << std::endl;
}

#endif //ARQ_H_INCLUDED