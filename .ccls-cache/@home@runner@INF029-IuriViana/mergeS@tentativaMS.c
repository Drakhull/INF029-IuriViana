#include <stdio.h>

#define maxV 10
#define maxF (maxV * 2)

int main(void)
{
    int vetor1[maxV] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int vetor2[maxV] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int vetorF[maxF];

    for (int i = 0; i < maxF; i++)
    {
        vetorF[i] = -1;
    }

    int i = 0, j = 0, k = 0;

    while (k < maxF)
    {
        if (vetor1[i] < vetor2[j])
        {
            if (i < maxV)
            {
                vetorF[k] = vetor1[i];
                i++;
                k++;
            }
            
        }
        if (vetor1[i] > vetor2[j])
        {
            if (j < maxV)
            {
                vetorF[k] = vetor2[j];
                j++;
                k++;
            }
        }
        
        if (i == (maxV - 1) && j == maxV)
        {
            if (vetor1[maxV - 1] > vetor2[j])
            {
                vetorF[k] = vetor2[j - 1];
                k++;
            }
        }
        if (j == (maxV - 1) && i == maxV)
        {
            if (vetor1[maxV - 1] < vetor2[j])
            {
                vetorF[k] = vetor2[i - 1];
                k++;
            }
        }
    }
    
    for (int i = 0; i < maxF; i++)
    {
        printf("Posicao %d tem valor: %d\n", i, vetorF[i]);
    }
    

    return 0;
}