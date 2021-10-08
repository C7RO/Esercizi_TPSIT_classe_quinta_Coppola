#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 300
#define DIM 100

typedef struct
{
    int num;
    char data[LUNG];
    char titolo[LUNG];
    char disp[LUNG];
    char genere[LUNG];
} film;

int main()
{

    FILE*fp;
    film tabella[DIM];
    char appoggio[LUNG];
    fp=fopen("tabella.txt","r");
    int k=0;
    while(fscanf(fp, "%d,",&tabella[k].num)!=EOF)
    {
        fgets(appoggio, 70,fp);
        modificaStringa(appoggio, &tabella[k]);
        k++;
    }
    for(int j=0; j<k; j++)
    {
        printf("Num: %2d, Tit:%s, gen: %s, data: %s, disp: %s\n",tabella[j].num, tabella[j].titolo,tabella[j].genere,tabella[j].data,tabella[j].disp);
    }
    fclose(fp);
    return 0;
}

void modificaStringa(char str[], film * x)
{
    int k=0;
    int j=0;
    char * p=strtok(str, ",");
    strcpy(x->titolo, p);
    p=strtok(NULL, ",");
    strcpy(x->genere, p);
    p=strtok(NULL, ",");
    strcpy(x->data, p);
    p=strtok(NULL, ",");
    strcpy(x->disp, p);
}
