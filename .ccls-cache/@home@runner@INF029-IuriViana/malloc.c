#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p = malloc(sizeof(int));

  *p = 1005;
  printf("Antes do free(p)\n");
  printf("P: %d\n", *p);
  printf("P: %p\n", &p);
  printf("P: %p\n\n", p);

  free(p);

  free(&p);

  int *k = malloc(sizeof(int));

  *k = 555;
  *p = 444;
  printf("Depois do free(p)\n");
  printf("P: %d\n", *p);
  printf("P: %p\n", &p);
  printf("P: %p\n", p);
  printf("\n");
  printf("K: %d\n", *k);
  printf("K: %p\n", &k);
  printf("K: %p\n", k);

  return 0;
}