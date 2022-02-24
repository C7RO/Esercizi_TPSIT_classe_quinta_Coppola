#include <stdio.h>
#include <stdlib.h>

/*Scrivere un programma che chieda n valori
interi (massimo 100), li collochi in un vettore e inverta il vettore
(scambiando il primo elemento con l'ultimo, il secondo con il penultimo, etc.).
Si usi i puntatori.*/

void leggiVett(int *v, int n) //lettura di un vettore int
{
    for(int k=0; k< n; k++)
    {
        printf("Dammi un numero: ");
        scanf("%d", v+k);
    }
}

void invertiVett(int *v, int n)//Inversione dell'ordine degli elementi di un vettore int
{
    int t;
    for(int k=0; k< n/2; k++)
    {
        t=*(v+k);
        *(v+k)=*(v+n-1-k);
        *(v+n-1-k)=t;
    }
}

void stampaVett(int *v, int n)//Stampa di un vettore int, tramite puntatore
{
    for(int k=0; k< n; k++)
    {
        printf("%d: %d\n", k+1, *(v+k));
    }
}

int main()
{
    int n;
    printf("Quanti numeri vuole inserire? ");
    scanf("%d", &n);
    int *v=(int*)malloc(n*sizeof(int));
    leggiVett(v, n);
    invertiVett(v, n);
    stampaVett(v, n);
    return 0;
}
