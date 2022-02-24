#include <stdio.h>
#include <stdlib.h>

/*1)Crea un programma che:
a)immetta il numero dei nodi inserendo da tastiera i valori per ogni nodo
b)stampi la lista dei valori inseriti
c)stampi la stessa lista cancellando l’ultimo nodo*/

typedef struct nodo// struttura nodo
{
    int num;
    struct nodo * next;
} Nodo;

Nodo * formattaLista()
{
    int n;
    printf("Quanti numeri vuole inserire: ");//viene chiesta la dimensione della lista
    scanf("%d", &n);
    int num;
    Nodo * head=NULL;
    Nodo *r=(Nodo*)malloc(sizeof(Nodo));
    Nodo * cur=head;
    for(int k=0; k< n; k++)
    {
        printf("Dammi un numero: ");//vengono letti gli elementi e creata la lista
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
    printf("%d\n",l-> num);//viene stampata la lista sfruttando la ricorsione fino a ottenre null come ultimo puntatore
    if(l->next!=NULL)stampaLista(l->next);
}

void deletLastNodo(Nodo * l)
{
    if(l->next==NULL)
    {
        printf("Non ci sono nodi nella lista!!\n");//si verifica che la lista non sia vuota
    }
    else
    {
        Nodo * last=l->next;
        Nodo* r= l;
        while(last->next!=NULL)//si modifica il penultimo next inizializzandolo a NULL
        {
            r=last;
            last=last->next;
        }
        r->next=NULL;
    }
}

int main()
{
    Nodo * head;
    head= formattaLista();
    stampaLista(head);
    deletLastNodo(head);
    printf("Lista nuova: \n");
    stampaLista(head);
    return 0;
}
