#include <stdio.h>
#define maxV 5
#define maxF 10

int main(void)
{
  int vetor1[maxV] = {0, 2, 4, 6, 8};
  int vetor2[maxV] = {1, 3, 5, 7, 9};
  int vetorF[maxF];
  
  int i = 0, j = 0;
  int k = 0;
  while(k < maxF)
  {
      if(vetor1[i] < vetor2[j])
      {
        vetorF[k] = vetor1[i];
        i++;
        k++;
      }
      else if (vetor2[j] < vetor1[i])
      {
        vetorF[k] = vetor2[j];
        j++;
        k++;
      }
    if(i == (maxV - 1))
    {
      vetorF[k] = vetor2[j];
      k++;
    }
    else if (j == (maxV -1))
    {
      vetorF[k] = vetor1[i];
      k++;
    }
  }

  for(int i = 0; i <  maxF; i++)
    {
      printf("vetor: %d, ", vetorF[i]);
    }
  

    
  
  return 0;
}
