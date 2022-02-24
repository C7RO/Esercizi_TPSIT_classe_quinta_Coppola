#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 50
#include <math.h>
/*Verificare se una stringa è palindroma*/


int main()
{
    int mat[100][100][100];
    int i,j,k,count=0,a=2;
    for(i=0; i<100; i++)
    {
        for(j=0; j<100; j++)
        {
            for(k=0; k<100; k++)
            {
                if ((i<45) || (i>54))
                    mat[i][j][k]=0;
                else
                {
                    count=i-45+1;
                    mat[i][j][k]=pow(a,count);
                }
            }
        }
    }
    printf("N = %d",mat[54][99][99]);
    return 0;
}
