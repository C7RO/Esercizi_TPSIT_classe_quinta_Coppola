#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 30

/*Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse:
(,),[,],{,} e che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.*/

typedef struct nodo
{
    char c;
    struct nodo * next;
} Nodo;

Nodo* push(Nodo * l, char c)//si aggiunge un elemento in lista
{
    Nodo * n= (Nodo*)malloc(sizeof(Nodo));
    n->c=c;
    n->next=NULL;
    if(l!=NULL)
    {
        n->next=l;
    }
    return n;
}

Nodo* pop(Nodo * l)//si toglie l'ultimo elemento lista
{
    Nodo * n= (Nodo*)malloc(sizeof(Nodo));
    n=l;
    if(l==NULL)
    {
        printf("Non ci sono nodi nella lista!!\n");
    }
    else
    {
        n=n->next;
    }
    return n;
}

bool verificaParentesi(char s[])
{
    int k=0;
    bool ok=true;
    Nodo*head=NULL;
    while (k <  strlen(s) && ok== true)
    {
        if (s[k]== '(' || s[k] == '[' || s[k]== '{')// si verifica attraverso una successione di if la corretta apertura e chiusura delle parentesi
        {
            head=push(head, s[k]);
        }
        if (s[k]== ')' || s[k] == ']' || s[k]== '}')
        {
            if (head!=NULL)
            {
                if ((head->c + 1) != s[k] && (head->c + 2) != s[k])
                {
                    ok= false;
                }
                else
                {
                    head=pop(head);
                }
            }
            else
            {
                ok=false;
            }
        }
        k+=1;
    }
    if(head!=NULL)
    {
        ok=false;
    }
    return ok;
}

int main()
{
    char s[LUNG];
    printf("Dammi una stringa: ");
    scanf("%s", s);
    if(verificaParentesi(s))
    {
        printf("Parentesi corrette\n");
    }
    else
    {
        printf("Parentesi NON corrette\n");
    }
    return 0;
}
