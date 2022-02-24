#include <stdio.h>
#include <stdlib.h>

/*Scrivere un programma per leggere e stampare
array bidimensionale di interi. Il programma richiede all’utente il numero
di righe e di colonne dopo di che richiede ad uno ad uno gli elementi da inserire
nell'array. Il programma inoltre deve gestire dinamicamente l'allocazione
e la deallocazione della memoria.
*/

float ** malloc2d(float **m, int n1, int n2)
{
    m=(float **) calloc(n1, sizeof(float*));//dichiarazione matrice
    for(int k=0; k< n2; k++)
    {
        *(m+k) = (float*)calloc(n2, sizeof(float));
    }
    return m;
}

void leggiMat(float **m, int r, int c)//Letture degli elementi, colonne per riga
{
    for(int k=0; k< r; k++)
    {
        for(int y=0; y< c; y++)
        {
            printf("Dammi valore mat[%d][%d]: ", k, y);
            scanf("%f", &m[k][y]);
        }
    }
}

void stampaMat(float **m, int r, int c)//stampa matrice
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
    leggiMat(m, r,c);
    stampaMat(m, r, c);
    free(m);
    return 0;
}
