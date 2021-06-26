#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"
#include "fila.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    Pilha<int> p(20);
    Fila<int> f(20);
    int opc, num;

    do{
        cout<< "\n  -  Números Aleatórios com Pilha e Fila\n" <<endl;
        cout<< "           1  -  Carregar Fila com Nº entre 35 e 78" <<endl;
        cout<< "           2  -  Exibir Fila" <<endl;
        cout<< "           3  -  Passar elementos da Fila para a Pilha" <<endl;
        cout<< "           4  -  Exibir Pilha" <<endl;
        cout<< "           5  -  Sair" <<endl;
        cout<< "\n\n   Selecione: ";
        cin>> opc;

        system("cls");
        cout<< "\n  -  Números Aleatórios com Pilha e Fila\n" <<endl;

        switch(opc){
            //Carregar Fila
            case 1:

                while(!f.filaCheia()){
                    num = rand()%100; //Num recebe valor aleatório
                    if(num >= 35 && num <= 78){
                        f.inserir(num);
                    }
                }
                cout<< "\n     Fila Carregada!\n\n     ";
                break;

            //Exibir Fila
            case 2:

                if(f.filaVazia())
                {
                    cout << "\n     Fila está Vazia!....\n\n     ";
                }
                else{
                    cout << "\n     Fila:";

                    //Se a Posição de "Início" do Vetor é menor que a Posição de "Fim"
                    if(f.getInicio() < f.getFim())
                    {
                        for(int i=f.getInicio(); i<=f.getFim(); i++)
                        {
                            cout << "   " << f.getValor(i);
                        }
                    }
                    else{

                        for(int i=f.getInicio(); i<=19; i++)
                        {

                            cout << "   " << f.getValor(i);

                            //Se a Posição de "Início" é a última (tamanho-1) do Vetor
                            if(i == 19)
                            {
                                for(int x=0; x<=f.getFim(); x++)
                                {
                                    cout<< "   " << f.getValor(x);
                                }
                            }
                        }

                    }
                }
                cout << "\n\n     ";
                break;

            //Passar da Fila para a Pilha
            case 3:
                if(f.filaVazia())
                {
                    cout << "\n     Fila está Vazia!....\n\n     ";
                }
                else{

                    //Se a Pilha já tiver sido preenchida antes
                    if(p.pilhaCheia()){
                        for(int x=0; x<20; x++){
                            p.desempilha();
                        }
                    }
                    while(!f.filaVazia()){
                        num = f.remover();
                        p.empilha(num);
                    }
                    cout<< "\n     Elementos Passados!\n\n     ";

                }
                break;

            //Exibir Pilha
            case 4:
                cout<< "\n     Pilha:  ";

                if(p.pilhaVazia()){
                    cout << "\n     Pilha está Vazia!....\n\n     ";
                }
                else{
                    for(int i=0; i<=p.getTopo(); i++)
                    {
                        cout << p.getValor(i) << "   ";
                    }
                }

                cout << "\n\n     ";
                break;

            //Sair
            case 5:
                return 0;
                break;

            default:
                continue;
                break;
        }
        system("pause");
        system("cls");

    } while(opc != 5);
}
