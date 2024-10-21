// alunos:
// João Pedro Vasconcelos de Lima
// Virgilio Cardoso Dantas Neto


#include <iostream>
#include <cstdlib>
#include "sort.h"
#include <chrono> // Utilização da biblioteca chrono para medir o tempo de execução

using namespace std;
using namespace chrono;

int main(){
  // criando variáveis 
  int tam_vet;
  int num_vet;
  int vet_dispo;
  int sort;
  int mov, comp = 0;
  int bit_restart = 1;

  //inicio do menu
  //usamos o do while para que o menu seja repetido até o usuário escolher sair
  while (bit_restart == 1){
    cout << "olá! Escolha o tamanho do vetor:" << endl;
    cout << "1 -> 10" << endl;
    cout << "2 -> 100"<< endl;
    cout << "3 -> 1000" << endl;
    cout << "4 -> 10000" << endl;
    cout << " " << endl;
    
    //funçao para escolher o tamanho do vetor
    tam_vet = valor_tam_vet();
    
    cout << "Como deseja que o vetor esteja disposto?" << endl;
    cout << "1 -> decrescente" << endl;
    cout << "2 -> aleatório" << endl;
    cout << " " << endl;
    
    //funçao para escolher a disposição de elementos do vetor
    vet_dispo = valor_vet_dispo();
    
    //escolher o maior número do vetor
    cout << "Escolha o limite de números do vetor:" << endl;
    cin >> num_vet;
    cout << endl;

    //cria o vetor
    Item *v = new Item[tam_vet];

    //preenche o vetor com números
    for(int i = 0; i < tam_vet; i++)
      v[i].Chave = rand() % num_vet;

    //rearranja o vetor caso tenha sido escolhida a disposição decrescente
    if (vet_dispo == 1){
      BolhaDecrescente(v, tam_vet);
    }
    
    cout << "Gostaria de ver o vetor antes da ordenação?" << endl;
    cout << "1 -> sim" << endl;
    cout << "2 -> não" << endl;
    cout << " " << endl;
    
    //funçao para escolher se o vetor deve ser exibido
    if (valor_vet_dispo() == 1)
      for(int i = 0; i < tam_vet; i++)
        cout << v[i].Chave << " ";
    cout << endl;

    //escolher o tipo de ordenação(sort)
    cout << "Como deseja ordenar o vetor?" << endl;
    cout << "1 -> Bublesort" << endl;
    cout << "2 -> Quicksort" << endl;
    cout << "3 -> Countsort" << endl;
    cout << " " << endl;
    sort = valor_sort();

    //bublesort
    if (sort == 1){
      steady_clock::time_point tempo1 = steady_clock::now(); // inicio do tempo
      
      Bolha(v, tam_vet, mov, comp);
      
      steady_clock::time_point tempo2 = steady_clock::now(); // fim do tempo
      duration<float, std::milli> tempo_execucao = duration_cast<duration<float, std::milli>> (tempo2 - tempo1); // calcula o tempo de execução

      //apresenta os resultados
      cout << "Tempo de execução: " << tempo_execucao.count() << " milissegundos" << endl;
      cout << "Número de movimentações: " << abs(mov) << endl;
      cout << "Número de comparações: " << comp << endl;
      
    }

    //quicksort
    if (sort == 2){
      steady_clock::time_point tempo1 = steady_clock::now(); // inicio do tempo
      
      QuickSort(v, 0, tam_vet, mov, comp);

      steady_clock::time_point tempo2 = steady_clock::now(); // fim do tempo
      duration<float, std::milli> tempo_execucao = duration_cast<duration<float, std::milli>> (tempo2 - tempo1); // calcula o tempo de execução

      //apresenta os resultados
      cout << "Tempo de execução: " << tempo_execucao.count() << " milissegundos" << endl;
      cout << "Número de movimentações: " << abs(mov) << endl;
      cout << "Número de comparações: " << comp << endl;
    }

    //countsort
    if (sort == 3){
      steady_clock::time_point tempo1 = steady_clock::now(); // inicio do tempo
      
      CountSort(v, tam_vet, num_vet, mov, comp);

      steady_clock::time_point tempo2 = steady_clock::now(); // fim do tempo
      duration<float, std::milli> tempo_execucao = duration_cast<duration<float, std::milli>> (tempo2 - tempo1); // calcula o tempo de execução

      //apresenta os resultados
      cout << "Tempo de execução: " << tempo_execucao.count() << " milissegundos" << endl;
      cout << "Número de movimentações: " << abs(mov) << endl;
      cout << "Número de comparações: " << comp << endl;
    }
    cout << endl;

    //mostra o vetor ordenado
    for(int i = 0; i < tam_vet; i++)
      cout << v[i].Chave << " ";
    cout << endl;

    //reseta as variáveis
    mov = 0;
    comp = 0;

    
    cout << "Gostaria de reiniciar o programa?" << endl;
    cout << "1 -> sim" << endl;
    cout << "2 -> não" << endl;
    cout << " " << endl;

    //função pra recomeçar o programa
    bit_restart = restart();
  }
  cout << "Obrigado por usar o programa!" << endl;
}