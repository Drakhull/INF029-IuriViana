#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Errors*/
  #define FAILURE 0
  #define SUCCESS 1
/*Errors*/

/*Allocations*/
  #define ch 100
  #define numMax 30
/*Allocations*/


#include <stdio.h>

// int main(void)
// {
//     char a[666];
//     printf("char        : %lu byte\n", sizeof(char));
//     printf("int         : %lu bytes\n", sizeof(int));
//     printf("float       : %lu bytes\n", sizeof(float));
//     printf("double      : %lu bytes\n", sizeof(double));
//     printf("long        : %lu bytes\n", sizeof(long));
//     printf("short       : %lu bytes\n", sizeof(short));
//     printf("short int   : %lu bytes\n", sizeof(short int));
//     printf("long int    : %lu bytes\n", sizeof(long int));
//     printf("long double : %lu bytes\n", sizeof(long double));
//     printf("Tam A       : %lu bytes\n", sizeof a);


//     return 0;
// }

int readf(char path[], FILE **file)
{
    *file = fopen(path, "r");
    if (!*file)
    {
        printf("The program couldn't open the input file.\n");
        return FAILURE;
    }
    else
    {
        printf("File is now open.\n");
        return SUCCESS;
    }
}

int main(void)
{
    FILE *file = NULL;

    if (!readf("L0Q2.in", &file))
    {
        printf("Closing...\n");
        return FAILURE;
    }

    char *line = (char *)malloc(ch * sizeof(char));
    if (line == NULL)
    {
        printf("Memory allocation error.\n");
        fclose(file);
        return FAILURE;
    }

    char *slice;
    const char *separator = "  , ()";
    float numbers[numMax];
    for (int i = 0; i < numMax; i++)
    {
        numbers[i] = 0;
    }

    printf("\n\nArchive text:\n");
    int i = 0;
    while (fgets(line, ch, file) != NULL)
    {

        slice = strtok(line, separator);
        while (slice != NULL)
        {

            if (atof(slice) != 0)
            {
                numbers[i] = atof(slice);
                i++;
            }

            printf("%s\n", slice);
            slice = strtok(NULL, separator);
        }
    }


    printf("\n\nArchive numbers: ");
    FILE *f_out = fopen("RL0Q2.out", "w");
    for (int i = 0; i < numMax; i++)
    {
        fprintf(f_out, "%g", numbers[i]);
        if (i < (numMax - 1))
        {
            fprintf(f_out, " ");
          
        }
    }

    printf("\nEverything ok\n");
}