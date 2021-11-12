#include <stdio.h>
#include <stdlib.h>

/*dichiari una variabile come
puntatore a char;
dichiari una variabile come
puntatore a int;
allochi correttamente la
memoria per le due variabili e assegni loro un valore;
stampi il valore dei due
puntatori (indirizzo) e il contenuto delle celle di memoria da loro
puntate;*/

int main()
{

    int a;
    int * punta= &a;
    char car;
    char* puntcar= &car;
    printf("Dammi un numero: ");
    scanf("%d", punta);
    printf("Dammi un carattere:");
    scanf(" %c", puntcar);
    printf("Indirizzo: %d -> %d, indirizzo: %d -> %c", punta, *punta, puntcar, *puntcar);

    return 0;
}
