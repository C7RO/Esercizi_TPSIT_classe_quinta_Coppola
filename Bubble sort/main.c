#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 10

void scambiaInt(int *n1, int *n2)
{
    int k;
    k= *n1;
    *n1= *n2;
    *n2 = k;
}

void bubbleSort2(int *vett, int n)
{
//se non si fanno scambi in un giro il vettore è ordinato
    int k,sup;
    bool sca;

    sup=n-1;

    sca=true;
    while ((sup>0) && sca==true)
    {
        sca=false;
        for (k = 0; k < sup; k++)
        {
            if (*(vett+k) > *(vett+k+1))
            {
                scambiaInt( (vett+k),(vett+k+1));
                sca=true;
            }
        }
        sup--;
    }
}

void stampaVettInt(int vett[], int n)
{
    int k;
    for(k = 0; k < n; k++)
    {
        printf("v[%d]= %d\n", k, vett[k] );
    }

}

void leggiVettInt(int vett[], int n)
{
    int k;
    for(k= 0; k < n; k++)
    {
        printf("Elemento [%d]\t", k);
        scanf("%d", &vett[k]);
    }
}

int main()
{
    int v[DIM];
    leggiVettInt(v, 5);
    bubbleSort2(v, 5);
    stampaVettInt(v, 5);
    return 0;
}
