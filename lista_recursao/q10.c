#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ocorrencias(int num, int num_buscado){
  if(num == num_buscado){
    return true;
  }
  else return false;
}

int separar_numeros(int num, int num_buscado, int qtd){
  int num_copia;
  int ocorre;
  if(num != 0){
    ocorre = ocorrencias(num%10, num_buscado);
  
    if(ocorre){
      qtd++;
    }
    qtd = separar_numeros(num/10, num_buscado, qtd);
  }
  return qtd;
}

int main(void){
  int num = -100001;
  int num_buscado = -1;
  int ocorrencias = 0;
  ocorrencias = separar_numeros(num, num_buscado, 0);
  printf("\nO numero %d aparece %d vezes no numero %d.\n", num_buscado, ocorrencias, num);

  return EXIT_SUCCESS;
}
