#include <iostream>
#include <cstdlib>

using namespace std;

typedef int ChaveTipo;
typedef struct{
  ChaveTipo Chave;
} Item;

void Bolha (Item* v, int n, int& mov, int& comp);
void QuickSort (Item* v, int esq, int dir, int& mov, int& comp);
void CountSort (Item* v, int n, int k, int& mov, int& comp);
void BolhaDecrescente (Item* v, int n);
int valor_tam_vet();
int valor_vet_dispo();
int valor_sort();
int restart();