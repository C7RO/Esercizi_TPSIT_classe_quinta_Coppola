#include <stdio.h>
#include <stdlib.h>

/*Si scriva la funzione che stampa a terminale i valori contenuti nella lista inordine inverso rispetto a
quello della lista stessa (leggendoli dalla lista,non dal vettore)*/

typedef struct nodo
{
    int num;
    struct nodo * next;
} Nodo;

Nodo * formattaLista()
{
    int n;
    printf("Quanti numeri vuole inserire: ");
    scanf("%d", &n);
    int num;
    Nodo * head=NULL;
    Nodo *r=(Nodo*)malloc(sizeof(Nodo));
    Nodo * cur=head;
    for(int k=0; k< n; k++)
    {
        printf("Dammi un numero: ");
        scanf("%d", &num);
        if(r==NULL)r=(Nodo*)malloc(sizeof(Nodo));
        r->num=num;
        if(head==NULL)
        {
            head= r;
            cur=r;
        }
        cur->next=r;
        cur=r;
        cur->next=NULL;
        r=NULL;
    }
    return head;
}

void stampaLista(Nodo*l)
{
    if(l->next!=NULL)stampaLista(l->next);
    if(l!=NULL)printf("%d\n",l-> num);
}

int main()
{
    Nodo * head=NULL;
    head= formattaLista();
    stampaLista(head);
    return 0;
}
