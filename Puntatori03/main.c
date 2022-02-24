#include <stdio.h>
#include <stdlib.h>
#define LUNG 50
#include <stdbool.h>
#include <string.h>
#define PLUNG 10

/*Scrivere un programma che data una stringa in input dica se la stessa contiene almeno
una ‘A’ tra i primi 10 caratteri.*/

bool isA(char * s)
{
    bool ok=false;
    int n=strlen(s);
    int k=0;
    while(k< n && k< PLUNG && ok == false)//Si svolge un ciclo in cui viene controllato ogni carattere della stringa
    {
        if(*(s+k)== 'a' || *(s+k)=='A')
            ok=true;
        k++;
    }
    return ok;
}

int main()
{
    char * stringa=(char *)malloc(LUNG *sizeof(char));
    printf("Dammi una stringa: ");
    scanf("%s", stringa);
    if(isA(stringa))
        printf("C'e' una A/a tra i primi dieci caratteri\n");
    else
        printf("NON c'e' una A/a tra i primi dieci caratteri\n");

    return 0;
}
