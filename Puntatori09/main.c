#include <stdio.h>
#include <stdlib.h>
#define DIM 100

void leggiVettInt(int vett[], int n)//Si legge un vettore di int
{
    int k;
    for(k= 0; k < n; k++)
    {
        printf("Elemento [%d]\t", k);
        scanf("%d", &vett[k]);
    }
}

typedef struct nodo //struttura dei nodi della lista
{
    int num;
    struct nodo * next;
} Nodo;

Nodo * formattaLista( int* v, int n)//viene passato un vettore che diventerà una lista
{
    Nodo * head=NULL;
    Nodo *r=(Nodo*)malloc(sizeof(Nodo));
    Nodo * cur=head;
    for(int k=0; k< n; k++)
    {
        if(r==NULL)r=(Nodo*)malloc(sizeof(Nodo));
        r->num=*(v+k);
        if(head==NULL)
        {
            head= r;
            cur=r;
        }
        cur->next=r;
        cur=r;
        r=NULL;
    }
    return head;
}

void stampaLista(Nodo*l, int n)
{
    for(int k=0; k< n; k++)//stampa della lista
    {
        printf("%d\n",l->num);
        l=l->next;
    }
}

int main()
{
    int n;
    printf("Quanti numeri vuole inserire: ");
    scanf("%d", &n);
    int vett=(int*)malloc(n*sizeof(int));
    leggiVettInt(vett, n);
    Nodo * head;
    head= formattaLista(vett, n);
    stampaLista(head, n);
    return 0;
}
