//Codigo construido por Luiz Cunha
// Repositorio oficial: https://github.com/luizotcunha/Aula-/blob/master/merge_decrescente.c

// Para calcular apenas o tempo de execução do codigo de vetores muito grade, deve-se tirar os printf 

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);


int main(){

  int tamVet = 0, *v = NULL,tamVet_aux;

  printf("Tamanho do vetor: ");
  scanf("%i", &tamVet);

  v = (int *)malloc(tamVet * sizeof(int));
  srand(time(NULL));
  
  tamVet_aux=tamVet;

  for (int i = 0; i < tamVet; i++)
  {
    v[i] = tamVet_aux;
    tamVet_aux--;
    
  }


  clock_t inicioc,fimc;
  
  inicioc = clock();

  mergesort(v, tamVet);

  fimc = clock();
  
    printf("\n\nTempo de execução %ld ms\n",(fimc - inicioc));
  return 0; 
}


void mergesort(int *v, int n) {
  int *c = malloc( sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}


void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;
  sort(v, c, i, m);
  sort(v, c, m + 1, f);
  if (v[m] <= v[m + 1]) return;
  merge(v, c, i, m, f);
}


void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;
  for (z = i; z <= f; z++) c[z] = v[z];
  z = i;
  while (iv <= m && ic <= f) {
    if (c[iv] < c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}
