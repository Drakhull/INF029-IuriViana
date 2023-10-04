#include <stdio.h>
#include <stdlib.h>

#define MAX_INT sizeof(int)

void merge(int * A, int p, int q, int r)
{
  int n1 = q - p + -
  int n2 = r - q;
  
  int * L = malloc((n1 + 1) * sizeof(int));
  int * R = malloc((n2 + 1) *sizeof(int));
  
  int i = 0;
  int j = 0;

  for(i = 0; i < n1; i++)
    {
      L[i] = A[p + i];
    }
  for(j = 0; j < n2; j++)
    {
      R[j] = A[q + j + 1];
    }

  L[n1] = MAX_INT;
  R[n2] = MAX_INT;

  i = j = 0;

  for(int k = p; k <= r; k++)
    {
      if(L[i] < R[j])
      {
       A[k] = L[i];
        i++;
      }
      else 
      {
        A[k] = R[j];
        j++;
      }
    }
  free(L);
  free(R);
}

void merge_sort(int * A, int p, int r)
{
  if(p < r)
  {
    int q = (p+r)/2;
    merge_sort(A, p, r);
    merge_sort(A, q + 1, r);
    merge(A, q, r);
  }
}

int main(void)
{
  int A[] = {3, 3, 0, 5, 2, 1974, 1950, 50, -2000, 20, 30};
  printf("Antes\n");
}