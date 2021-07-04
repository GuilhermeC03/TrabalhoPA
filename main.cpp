#include <iostream>
#include <math.h>
#include <fstream>
#include "listaE.h"
using namespace std;


struct tInvestimentos{
  float cinValorInicial(){
    float vInicial;
    cout << "Digite o capital inicial: R$"; 
    cin >> vInicial;
    return (vInicial);
  }
  float cinTaxa(){
    float tax;
    cout << "Digite a taxa anual: "; 
    cin >> tax;
    tax = tax / 100; 
    return (tax);
  }
  float cinTempo(){
    float tempo;
    cout << "Digite o tempo de aplicacao em anos: "; 
    cin >> tempo;
    return (tempo);
  }
};

float Simples(float principal, float tax, float anos)
{ 
  return (principal * (1 + (tax * anos)));
}
float Composto(float principal, float tax, float anos)
{   
  return (principal * pow((1 + tax), anos));
}

int main() {
  
  char escolher, opmenu;
  int n=0;
  tInvestimentos valores;


  tLista* invest = new tLista;

  iniciarLista(invest);
  do{
    
    cout<<"* CALCULADORA DE JUROS "<< endl;
    cout<<" 1 para Gravar informacoes no arquivo"<< endl;
    cout<<" 2 para Ler informacoes do arquivo"<< endl;
    cout<<" 0 para SAIR"<< endl;
    cout<<"Digite uma opçao: " << endl;
    cin >> escolher;

    switch (escolher) {
      case '1': {
        system("clear");
        fflush(stdin);
        cout<<"* Inserir informações" <<endl;
        cout << " Quantos tInvestimentos deseja adicionar? "<< endl;
        cin >> n;

        for(int i=0; i<n; i++){
          
          float capital = valores.cinValorInicial();
          float taxa = valores.cinTaxa();
          float tempo = valores.cinTempo();
          float montanteS = Simples(capital, taxa, tempo);
          float montanteC = Composto(capital, taxa, tempo);

          incluirElemento(invest, capital);
          incluirElemento(invest, taxa);
          incluirElemento(invest, tempo);
          incluirElemento(invest, montanteS);
          incluirElemento(invest, montanteC);
        }

        gravarLista(invest);
        iniciarLista(invest);
        break;
      }
      case '2': {
      
        lerInformacoes(invest);
        imprimirLista(invest);
        iniciarLista(invest);
        break;
      }
      default: {
        cout<<"Encerrando o programa"<< endl;
        break;  
      }
    }
  }while (escolher!='0');
}
