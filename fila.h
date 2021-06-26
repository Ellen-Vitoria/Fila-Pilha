#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

template <typename Tipo>

class Fila{
private:
    int fim, inicio;
    unsigned qtde;
    unsigned tamanho;
    Tipo *v;

public:
    //Função inicializadora
    Fila(unsigned tam){
        fim = -1;
        inicio = 0;
        qtde = 0;
        tamanho = tam;
        v = new Tipo[tamanho];
    }

    ~Fila(){
        delete []v;
    }

    //Inserir
    void inserir(Tipo x){
        fim++;
        //Quando posição de Fim chegar no valor do tamanho
        if(fim == tamanho) {
            fim = 0;
        }
        v[fim] = x;
        qtde++;
    }

    //Remover
    Tipo remover(){
        Tipo temp = v[inicio]; //Guardar valor inicial na variável temporária
        inicio++;
        //Quando posição de Início chegar no valor do tamanho
        if(inicio == tamanho){
            inicio = 0;
        }
        qtde--;
        return temp;
    }

    //Primeiro da Fila
    Tipo primeiro(){
        return v[inicio];
    }

    bool filaCheia(){
        return qtde == tamanho;
    }

    bool filaVazia(){
        return qtde == 0; //Se Fila estiver vazia, retornará 0
    }

    //Posição de Fim
    int getFim(){
        return fim;
    }

    //Posição de Início
    int getInicio(){
        return inicio;
    }

    //Quantidade
    int getQtde(){
        return qtde;
    }

    Tipo getValor(unsigned posicao){
        return v[posicao];
    }

    unsigned getTamanho(){
        return tamanho;
    }

};

#endif // FILA_H_INCLUDED
