#include <stdio.h>
#include <stdlib.h>

/*una funzione per una matrice a due dimensioni date in input*/

float ** malloc2d(float **m, int n1, int n2)
{
    m=(float **) calloc(n1, sizeof(float*));//dichiarazione della matrice a [n1][n2]
    for(int k=0; k< n2; k++)
    {
        *(m+k) = calloc(n2, sizeof(float));
    }
    return m;
}

void stampaMat(float **m, int r, int c)//stampa utilizzando due cicli for annidati per righe e colonne
{
    for(int k=0; k< r; k++)
    {
        for(int y=0; y< c; y++)
        {
            printf("mat[%d][%d]= %.2f\n", k, y, m[k][y]);
        }
    }
}

int main()
{
    int r, c;
    printf("Dammi la prima dimensione: ");
    scanf("%d", &r);
    printf("Dammi la seconda dimensione: ");
    scanf("%d", &c);
    float **m;
    m=malloc2d(m, r, c);
    stampaMat(m, r, c);
    free(m);
    return 0;
}
