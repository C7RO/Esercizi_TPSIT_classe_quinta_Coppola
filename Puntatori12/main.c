#include <stdio.h>
#include <stdlib.h>

/*Crea un programma che:
a) immetta il numero dei nodi inserendo da tastiera i valori per ogni nodo
b) stampi la lista dei valori inseriti
c) inserisca un nuovo nodo all'inizio della lista*/

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
    printf("%d\n",l-> num);
    if(l->next!=NULL)stampaLista(l->next);
}

Nodo* aggiungiNodo(Nodo * l)
{
    int num;
    printf("Dammi un valore: ");
    scanf("%d", &num);

    Nodo * n= (Nodo*)malloc(sizeof(Nodo));
    n->num=num;
    n->next=l;
    return n;
}

int main()
{
    Nodo * head;
    head= formattaLista();
    stampaLista(head);
    head=aggiungiNodo(head);
    printf("Lista nuova: \n");
    stampaLista(head);
    return 0;
}
