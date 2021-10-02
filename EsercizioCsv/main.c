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
        strtok(appoggio, ",");
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
    while(str[k]!='\0')
    {
        x->titolo[j]=str[k];
        k++;
        j++;

    }
    x->titolo[j]='\0';
    j=0;
    k++;
    while(str[k]!=',')
    {

        x->genere[j]=str[k];
        k++;
        j++;
    }
    x->genere[j]='\0';
    j=0;
    k++;
    while(str[k]!=',')
    {
        x->data[j]=str[k];
        k++;
        j++;
    }
    x->data[j]='\0';
    j=0;
    k++;
    while(str[k]!='\0')
    {
        x->disp[j]=str[k];
        k++;
        j++;
    }
    x->disp[j]='\0';
    j=0;
}
