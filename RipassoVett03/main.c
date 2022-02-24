#include <stdio.h>
#include <stdlib.h>
#define DIM 10

/*Dato un vettore A di interi creare i vettori PARI e DISPARI formati rispettivamente
dagli elementi pari in posizioni dispari e dispari in posizioni pari presenti in A*/

float nonNegativo(char stringa[])
{
    float lato;
    do
    {
        printf("%s ",stringa);
        scanf("%f", &lato);
    }
    while(lato<=0);
    return lato;
}

int main()
{
    int v[DIM];
    int n;
    n=nonNegativo("Quanti numeri vuole darmi? ");
    for(int k=0; k<n; k++)
    {
        printf("Dammi un numero: ");
        scanf("%d", &v[k]);
    }
    int par[DIM], dispar[DIM];
    int npari=0, ndispari=0;
    pari(v,par, n, &npari);
    dispari(v, dispar, n, &ndispari);
    stampa(par, npari);
    stampa(dispar, ndispari);
    return 0;
}

void pari(int v[], int pari[],int n, int *np)
{
    for(int k=1; k< n; k+=2)
    {
        if(v[k]%2==0)
        {
            pari[*np]=v[k];
            *np+=1;
        }
    }
}

void dispari(int A[], int dis[], int n, int *nd)
{

    for(int k = 0; k < n; k+=2)
    {
        if(A[k] % 2 == 1)
        {
            dis[*nd] = A[k];
            *nd+=1;
        }
    }

}

void stampa(int v[], int n)
{
    for(int k = 0; k < n; k++)
    {
        printf("%d ", v[k]);
    }
    printf("\n");
}
