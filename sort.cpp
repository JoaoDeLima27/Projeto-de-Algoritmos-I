#include <iostream>
#include <cstdlib>
#include "sort.h"

using namespace std;

void Bolha (Item* v, int n, int& mov, int& comp){
  int i, j;
  Item aux;
  
  for( i = 0 ; i < n-1 ; i++ ){
    // Percorre o vetor comparando elementos adjacentes
    for( j = 1 ; j < n-i ; j++ ){
      comp++;
      // Se o elemento da direita é menor que o da esquerda, troca
      if ( v[j].Chave < v[j-1].Chave ){
        aux = v[j];
        // Move o elemento da esquerda para a direita
        v[j] = v[j-1];
        // Move o elemento da direita para a esquerda
        v[j-1] = aux;
        mov++;
      } 
    }
  }
}

void BolhaDecrescente (Item* v, int n){
  int i, j;
  Item aux;
  for( i = 0 ; i < n-1 ; i++ ){
    for( j = 1 ; j < n-i ; j++ ){
      if ( v[j].Chave > v[j-1].Chave ){
      aux = v[j];
      v[j] = v[j-1];
      v[j-1] = aux;
      } 
    }
  }
}

void QuickSort (Item* v, int esq, int dir, int& mov, int& comp){
  int i = esq, j = dir;
  Item pivo = v[(esq + dir) / 2];
  
  while (i <= j){
    //enquanto o elemento da esquerda for menor que o pivô, move o índice i para a direita
    while (v[i].Chave < pivo.Chave){
      i++;
      comp++;
    }
    //enquanto o elemento da direita for maior que o pivô, move o índice j para a esquerda
    while (v[j].Chave > pivo.Chave){
      j--;
      comp++;
    }
    //se o índice i for menor ou igual ao índice j, troca os elementos
    if (i <= j){
      Item aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
      mov++;
    }
  }
  //chama recursivamente o Quicksort para a metade esquerda do vetor
  if (esq < j)
    QuickSort(v, esq, j, mov, comp);
  //chama recursivamente o Quicksort para a metade direita do vetor
  if (i < dir)
    QuickSort(v, i, dir, mov, comp);
}

void CountSort (Item* v, int n, int k, int& mov, int& comp){
  int i, j;
  int* c = new int[k+1];
  Item* b = new Item[n];
  for (i = 0; i <= k; i++)
    c[i] = 0;
  for (j = 0; j < n; j++) // conta a frequência de cada chave no vetor v.
    c[v[j].Chave]++;
  for (i = 1; i <= k; i++) // calcula a posição de cada chave no vetor ordenado.
    c[i] = c[i] + c[i-1];
  for (j = n-1; j >= 0; j--){ // ordena o vetor v em ordem crescente de chave.
    comp++;
    b[c[v[j].Chave]-1] = v[j];
    c[v[j].Chave]--;
    mov++;
  }
  for (i = 0; i < n; i++) // copia o vetor ordenado b para o vetor original v.
    v[i] = b[i];
  delete[] c;
  delete[] b;
}

//função para impedir que o usuário escolha um valor que não está na lista
int valor_tam_vet(){
  int n;
  int bit_erro = 0;
  while (bit_erro == 0){
    cin >> n;
    if(n == 1){
      n = 10;
      bit_erro = 1;
    }
    if(n == 2){
      n = 100;
      bit_erro = 1;
    }
    if(n == 3){
      n = 1000;
      bit_erro = 1;
    }
    if(n == 4){
      n = 10000;
      bit_erro = 1;
    }
    if(bit_erro == 0){
      cout << "Erro: valor de n inválido. Escolha um valor válido" << endl;
    }
  }
  return n;
}

//função para impedir que o usuário escolha um valor que não está na lista
int valor_vet_dispo(){
  int n;
  int bit_erro = 0;
  while (bit_erro == 0){
    cin >> n;
    if(n == 1){
      bit_erro = 1;
    }
    if(n == 2){
      bit_erro = 1;
    }
    if(bit_erro == 0){
      cout << "Erro: valor inválido. Escolha um valor válido" << endl;
    }
  }
  return n;
}

//função para impedir que o usuário escolha um valor que não está na lista
int valor_sort(){
  int n;
  int bit_erro = 0;
  while (bit_erro == 0){
    cin >> n;
    if(n == 1){
      bit_erro = 1;
    }
    if(n == 2){
      bit_erro = 1;
    }
    if(n == 3){
      bit_erro = 1;
    }
    if(bit_erro == 0){
      cout << "Erro: valor inválido. Escolha um valor válido" << endl;
    }
  }
  return n;
}

//função para impedir que o usuário escolha um valor que não está na lista
int restart(){
  int n;
  int bit_erro = 0;
  while (bit_erro == 0){
    cin >> n;
    if(n == 1){
      bit_erro = 1;
    }
    if(n == 2){
      bit_erro = 1;
    }
    if(bit_erro == 0){
      cout << "Erro: valor inválido. Escolha um valor válido" << endl;
    }
  }
  return n;
}

