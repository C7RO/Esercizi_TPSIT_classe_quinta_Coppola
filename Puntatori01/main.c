#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 50

/*Verificare se una stringa è palindroma*/

bool isPalindroma(char * s)
{
    bool ok=true;
    int n=strlen(s);
    int k=0;
    while(k< n/2 && ok == true)
    {
        if(*(s+k) != *(s+(n-1-k)))
            ok=false;
        k++;
    }
    return ok;
}

int main()
{
    char * stringa=(char *)malloc(LUNG *sizeof(char));
    printf("Dammi una stringa: ");
    scanf("%s", stringa);
    if(isPalindroma(stringa))
        printf("Stringa palindroma\n");
    else
        printf("Stringa NON palindroma\n");

    return 0;
}
