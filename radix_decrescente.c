//Codigo construido por Luiz Cunha
// Repositorio oficial: https://github.com/luizotcunha/Aula-/edit/master/radix_decrescente.c

// Para calcular apenas o tempo de execução do codigo de vetores muito grade, deve-se tirar os printf 

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void radixsort(int *vet, int n);

int main(){

  int tamVet = 0, *v = NULL,tamVet_aux;

  printf("Tamanho do vetor: ");
  scanf("%i", &tamVet);

  v = (int *)malloc(tamVet * sizeof(int));
  srand(time(NULL));

  tamVet_aux = tamVet;
  
  for (int i = 0; i < tamVet; i++)
  {
    v[i] = tamVet_aux;
    tamVet_aux--;
    printf("Valor  %i : %i" , i+1,  v[i]);
    printf("\n");
  }
  

  clock_t inicioc,fimc;
  
  inicioc = clock(); // começa a contar o tempo

  radixsort (v, tamVet); // apenas ordena

  fimc = clock();// para de contar o tempo
  
  for (int i = 0; i < tamVet; i++)
  {
    printf("Valor  %i ordenado : %i" , i+1,  v[i]);
    printf("\n");
  }

  printf("\nTempo de execução %ld ms\n",(fimc - inicioc));

  return 0; 
}



void radixsort(int *vet, int n) {
  int i, exp = 1, m = 0, bucket[n], temp[n];

  for(i = 0; i < n; i++) {
    if(vet[i] > m) {
      m = vet[i];
    }
  }

  while((m/exp) > 0) {
    for (i = 0; i < n; i++) {
      bucket[i] = 0;
    }
    for(i = 0; i < n; i++) {
      bucket[(vet[i] / exp) % 10]++;
    }
    for(i = 1; i < n; i++) {
      bucket[i] += bucket[i-1];
    }
    for(i = (n - 1); i >= 0; i--) {
      temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
    }
    for(i = 0; i < n; i++) {
      vet[i] = temp[i];
    }
    exp *= 10;
  }
}
