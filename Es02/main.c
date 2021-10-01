#include <stdio.h>
#include <stdlib.h>
#define DIM 10

typedef struct
{
    int mate;
    int ita;
    int fisica;
} studente;

int main()
{
    int n;
    studente classe[DIM];
    printf("Quanti alunni ci sono? ");
    scanf("%d", &n);
    for(int k=0; k< n; k++)
    {
        printf("Dammi il voto di italiano del %d alunno: ", k+1);
        scanf("%d", &classe[k].ita);
        printf("Dammi il voto di mate del %d alunno: ", k+1);
        scanf("%d", &classe[k].mate);
        printf("Dammi il voto di fisica del %d alunno: ", k+1);
        scanf("%d", &classe[k].fisica);
    }
    int media1=0, media2=0, media3=0;
    for(int k=0; k< n; k++)
    {
        media1+=classe[k].ita;
        media2+=classe[k].mate;
        media3+=classe[k].fisica;
    }
    media1/=n;
    media2/=n;
    media3/=n;
    if(media1 > media2 && media1 > media3)
    {
        printf("Italiano ha la media dei voti piu' alta");
    }
    else
    {
        if(media2 > media3 && media2 > media1)
        {
            printf("Matematica ha la media dei voti piu' alta");
        }
        else
        {
            printf("Fisica ha la media dei voti piu' alta");
        }
    }

    return 0;
}
