#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Scrivere un programma che permette all’utente di inizializzare un array unidimensionale
di float e ( facendo uso dell’aritmetica dei puntatori:


- individui gli elementi con valore ripetuti


-sommi i numeri rimasti*/

void leggiVett(float *v, int n)//Lettura array dinamico
{
    for(int k=0; k< n; k++)
    {
        printf("Dammi l'elemento v[%d]: ", k);
        scanf("%f", v+k);
    }
}

void stampaVett(float *v, int n)//stampa del vettore
{
    for(int k=0; k<n; k++)
    {
        printf("Elemento v[%d]: %f\n", k, *(v+k));
    }
}

void elementiRipetuti(float *v, int n)
{
    float *doppi=(float*)calloc(n, sizeof(float));
    int contd=0;
    float *scarti=(float*)calloc(n, sizeof(float));
    float sommaScarti=0;
    int contscar=0;
    bool tro=false;
    int y;
    for(int k=0; k< n; k++)//viene fatto scorrere l'array
    {
        tro=false;
        y=0;
        while (tro==false && y< n)
        {
            if(*(v+k)== *(v+y) && y != k)//si verifica la presenza di doppioni
            {
                tro=true;
                *(doppi+contd)=*(v+k);//contatore dei doppioni
                contd++;
            }
            y++;
        }
        if(tro==false)
        {
            *(scarti+contscar)=*(v+k);// si sommano gli elementi residui
            contscar++;
        }
    }
    for(int j=0; j< contd; j++)
    {
        printf("Doppione %.2f\n", *(doppi+j));
    }
    for(int j=0; j< contscar; j++)
    {
        sommaScarti+=*(scarti+j);
    }
    printf("Scarti %.2f\n", sommaScarti);
}

int main()
{
    int n;
    printf("Quanti numeri vuole inserire? ");
    scanf("%d", &n);
    float * v=(float*)malloc(n *sizeof(float));
    leggiVett(v, n);
    stampaVett(v, n);
    elementiRipetuti(v, n);
    return 0;
}
