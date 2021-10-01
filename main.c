#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <wincon.h>
#include "Utility.h"
#define LUNG 300
#define DIM 100
#define SU 72
#define SIN 75
#define DES 77
#define GIU 80
#define INVIO 13
#define ESC 27
#define PLAY 0
#define CONTINUE 1
#define OPTION 2
#define TUTORIAL 3
#define DIFFICOLTA 0
#define TEMA 1
#define REASY 9
#define CEASY 9
#define MEASY 15
#define RMED 18
#define CMED 18
#define MMED 45
#define RHARD 36
#define CHARD 36
#define MHARD 180
#define CAR 223
#define MINA 207
#define VUOTO 176
#define CARICAMENTO 205
#define TEMA0 6
#define TEMA1 240
#define TEMA2 95

typedef struct
{
    int r;      //Utilizzo una struct per lo spostamento del cursore nel campo di gioco
    int c;
} spostamento;

int main()
{
    int menu=0, menup=0, a;
    bool esci=false;
    impostaschermoMenu();
    caricamentoGoliardico();        //Loading.. per fare scena
    cursor_hide();
    stampaMenu(menu);
    while (!esci)
    {

        if (kbhit() == true)
        {
            cursor_hide();
            menup=menu; //ho creato una variabile menup per risolvere un bug con la rientranza del menu
            a = getch();
            switch(a)
            {
            case SU:
                menu--;
                if(menu<PLAY)//Per facilitare lo scorrimento nel menu
                {
                    menu=TUTORIAL;
                }
                break;
            case GIU:
                menu++;
                if(menu>TUTORIAL)//Per facilitare lo scorrimento nel menu
                {
                    menu=PLAY;
                }
                break;
            case INVIO:
                selezioneMenu(menu);
                menup=-1;
                break;
            case ESC:
                esci=true;
                break;
            default:
                break;
            }
            if(menu!=menup)
            {
                clrscr();
                stampaMenu(menu);
            }
        }
    }
    clrscr();
    thanks();
    return 0;
}

void thanks()   //Titoli di Coda
{
    printf("\n\n\n  T");
    delay(100);
    printf("h");
    delay(100);
    printf("a");
    delay(100);
    printf("n");
    delay(100);
    printf("k");
    delay(100);
    printf(" y");
    delay(100);
    printf("o");
    delay(100);
    printf("u");
    delay(100);
    printf(" f");
    delay(100);
    printf("o");
    delay(100);
    printf("r");
    delay(100);
    printf(" p");
    delay(100);
    printf("l");
    delay(100);
    printf("a");
    delay(100);
    printf("y");
    delay(100);
    printf("i");
    delay(100);
    printf("n");
    delay(100);
    printf("g");
    delay(100);
    printf("\n\n  Produced by COPPOLA");
    delay(2000);
    clrscr();
}

void caricamentoGoliardico()
{
    cursor_hide();
    printf("\n\n     PRATO FIORITO");
    gotoxy(5, 4);
    printf("Loading..  10%c", 37);
    printf("\n    %c%c", CARICAMENTO, CARICAMENTO);
    delay(200);
    gotoxy(5, 4);
    printf("Loading..  55%c", 37);
    printf("\n    %c%c%c%c%c%c%c%c", CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO);
    delay(800);
    gotoxy(5, 4);
    printf("Loading..  99%c", 37);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO);
    delay(2000);
    gotoxy(5, 4);
    printf("Loading..  101%c", 37);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO, CARICAMENTO);
    delay(1000);
    clrscr();
}

void stampaMenu(int n)//A seconda di n viene fatto scorrere il menu iniziale attraverso delle PRINTF
{
    switch(n)
    {
    case PLAY:
        clrscr();
        menu0();
        break;
    case CONTINUE:
        menu1();
        break;
    case OPTION:
        menu2();
        break;
    case TUTORIAL:
        menu3();
        break;
    default:
        break;

    }
}

void menu0()
{
    printf("\n\t********\n\n      ->NEW GAME<-\n\tCONTINUE\n\t OPTION\n\tTUTORIAL\n\n\t********");
}

void menu1()
{
    printf("\n\t********\n\n        NEW GAME\n      ->CONTINUE<-\n\t OPTION\n\tTUTORIAL\n\n\t********");
}

void menu2()
{
    printf("\n\t********\n\n        NEW GAME\n\tCONTINUE\n       ->OPTION<-\n\tTUTORIAL\n\n\t********");
}

void menu3()
{
    printf("\n\t********\n\n        NEW GAME\n\tCONTINUE\n\t OPTION\n      ->TUTORIAL<-\n\n\t********");
}

void selezioneMenu(int n)//Funzione richiamata dopo aver premuto invio nel menu
{
    int campo[DIM][DIM];
    int campoMostrato[DIM][DIM];
    switch(n)
    {
    case PLAY:      //A seconda della posizione del cursore vengono effettuate diverse azioni
        play(campo, campoMostrato,0,0,false, 0);//NEW GAME
        cursor_hide();
        impostaschermoMenu();
        break;
    case CONTINUE:  //CONTINUE in cui si carica la partita dal salvataggio precedente
        loadGame(campo, campoMostrato);
        cursor_hide();
        impostaschermoMenu();
        break;
    case OPTION://OPTION in cui ci si posiziona in un "sotto menu"
        menuOption();
        break;
    case TUTORIAL:
        tutorial();
        break;
    default:
        break;
    }
}

void tutorial()
{
    clrscr();
    delay(400);
    printf("\n\n\n      r        t        \n        v        l ");
    delay(50);
    clrscr();
    printf("\n\n\n  T   r   s    t    g   \n     r  v    s   l ");
    delay(50);
    clrscr();
    printf("\n\n\n  T e r l s o  t i  g m \n     re v r  s m l ");
    delay(50);
    clrscr();
    printf("\n\n\n  The rules of this game\n    are very simple");
    delay(3000);
    clrscr();
    printf("\n\n\n  T e r l s o  t i  g m \n     re v r  s m l ");
    delay(50);
    clrscr();
    printf("\n\n\n  T   r   s    t    g   \n     r  v    s   l ");
    delay(50);
    clrscr();
    printf("\n\n\n      r        t        \n        v        l ");
    delay(50);
    clrscr();
    delay(400);
    printf("\n\n\n      s         t       d\n         u        a     ");
    delay(50);
    clrscr();
    printf("\n\n\n E    s   r     t   f   d\n   a     u   r    a    e");
    delay(50);
    clrscr();
    printf("\n\n\n E c  s u r  o  t e f e d\n   a  a  u b r  r a  i e");
    delay(50);
    clrscr();
    printf("\n\n\n Each square of the field\n  has a number or a mine");
    delay(3000);
    clrscr();
    printf("\n\n\n E c  s u r  o  t e f e d\n   a  a  u b r  r a  i e");
    delay(50);
    clrscr();
    printf("\n\n\n E    s   r     t   f   d\n   a     u   r    a    e");
    delay(50);
    clrscr();
    printf("\n\n\n      s         t       d\n         u        a     ");
    delay(50);
    clrscr();
    delay(400);
    printf("\n\n\n      u        d      \n        b         e      \n         a        ");
    delay(50);
    clrscr();
    printf("\n\n\n T    u   r    d   t  \n  h     b    f    e    a \n    c    a     a  ");
    delay(50);
    clrscr();
    printf("\n\n\n T e  u b r  i d c t s\n  h   u b r  f  i e  t a \n  o c  t a   q a e");
    delay(50);
    clrscr();
    printf("\n\n\n The numbers indicates\n the number of mines that\n touch that square");
    delay(3000);
    clrscr();
    printf("\n\n\n T e  u b r  i d c t s\n  h   u b r  f  i e  t a \n  o c  t a   q a e");
    delay(50);
    clrscr();
    printf("\n\n\n T    u   r    d   t  \n  h     b    f    e    a \n    c    a     a  ");
    delay(50);
    clrscr();
    printf("\n\n\n      u        d      \n        b         e      \n         a        ");
    delay(50);
    clrscr();
    delay(400);
    printf("\n\n\n      o          e   t\n          o          r \n        e ");
    delay(50);
    clrscr();
    printf("\n\n\n T    o    s     e   t\n  l       o     h    r \n  o     e ");
    delay(50);
    clrscr();
    printf("\n\n\n T e  o l  s  o  e e t\n  l   h   o e   ha   r \n  o   i e ");
    delay(50);
    clrscr();
    printf("\n\n\n The Goal is to select\n all the boxes that are\n not mines");
    delay(3000);
    clrscr();
    printf("\n\n\n T e  o l  s  o  e e t\n  l   h   o e   ha   r \n  o   i e ");
    delay(50);
    clrscr();
    printf("\n\n\n T    o    s     e   t\n  l       o     h    r \n  o     e ");
    delay(50);
    clrscr();
    printf("\n\n\n      o          e   t\n          o          r \n        e ");
    delay(50);
    clrscr();
    delay(400);
    printf("\n\n\n\t  o     ");
    delay(50);
    printf("\n\n\n\t  o     k");
    delay(50);
    clrscr();
    printf("\n\n\n\tG o   u k");
    delay(50);
    clrscr();
    printf("\n\n\n\tGood Luck");
    delay(3000);
    clrscr();
    printf("\n\n\n\tG o   u k");
    delay(50);
    clrscr();
    printf("\n\n\n\t  o     k");
    delay(50);
    clrscr();
    printf("\n\n\n\t  o     ");
    delay(50);
}

void play(int campo[][DIM], int campoMostrato[][DIM], int dif, int tema, bool load, int conta)
{
    clrscr();
    spostamento x;
    int colonne=0;
    int righe=0;
    int mine=0, a;
    bool esci=false;
    FILE*fp;
    if(load==false)//A seconda se si deve caricare una partita vecchia o crearne una nuova
    {
        fp=fopen("option.txt","r");
        fscanf(fp, "difficolta <%d>", &dif); //vengono lette le impostazioni scelte in OPTION
        fscanf(fp, "\ntema <%d>", &tema);
        fclose(fp);
    }
    switch (dif)//Vengono assegnate le diverse caratteristiche del gioco secondo la difficolta'
    {
    case 0:
        righe=REASY;
        colonne=CEASY;
        mine=MEASY;
        impostaschermoEasy();
        break;
    case 1:
        righe=RMED;
        colonne=CMED;
        mine=MMED;
        impostaschermoMed();
        break;
    case 2:
        righe=RHARD;
        colonne=CHARD;
        mine=MHARD;
        impostaschermoHard();
        break;
    }
    switch (tema)//Vengono assegnate le diverse caratteristiche del gioco a seconda del tema
    {
    case 0:
        setTextColor(TEMA0);
        break;
    case 1:
        setTextColor(TEMA1);
        break;
    case 2:
        setTextColor(TEMA2);
        break;
    }
    if(load==false)//Se viene creata una nuova partita viene formattato il campo
    {
        for(int k=0; k< righe; k++)
        {
            for(int j=0; j< colonne; j++)
            {
                campoMostrato[k][j]=0;
            }
        }

        stampaCampoMinato(righe, colonne, mine, campo);
    }
    else//Se la partita deve essere caricata il campo viene letto da file e poi stampato
    {
        for(int k=0; k<righe; k++)
        {
            for(int j=0; j<colonne; j++)
            {
                if(campoMostrato[k][j]==0)
                {
                    printf("%c",CAR);
                }
                else
                {
                    if(campo[k][j]==0)
                    {
                        printf("%c", VUOTO);
                    }
                    else
                    {
                        printf("%d",campo[k][j]);
                    }
                }
                if(j<colonne-1)
                {
                    printf(" ");
                }
            }
            if(k<righe-1)
            {
                printf("\n");
            }
        }
    }
    x.c=0;
    x.r=0;
    while (!esci)
    {
        cursor_show();
        gotoxy(x.c, x.r);
        if (kbhit() == true)
        {

            a = getch();
            switch(a) //Vengono gestiti i movimenti del cursore nel campo
            {
            case SU:
                if(x.r>0)
                {
                    x.r--;
                }
                break;
            case GIU:
                if(x.r<righe-1) //Attraverso queste IF ci si assicura che il cursore non esca fuori dal campo creando errori
                {
                    x.r++;
                }
                break;
            case SIN:
                if(x.c>0)
                {
                    x.c-=2;
                }
                break;
            case DES:
                if(x.c<colonne*2-2)
                {
                    x.c+=2;
                }
                break;
            case INVIO:
                selezioneCampoMinato(campo[x.r][x.c/2], x.c, x.r, campo, righe, colonne, campoMostrato, &conta);
                if(campo[x.r][x.c/2]==MINA)//Se è stata beccata una mina si esce dal ciclo
                {
                    esci=true;
                }
                else
                {
                    if(conta>=righe*colonne-mine)//Se non si ha beccato una mina si verifica se il campo è stato vuotato completamente
                    {
                        for(int k=0; k< righe; k++)
                        {
                            for(int j=0; j< colonne; j++)
                            {
                                if(campo[k][j]==MINA)
                                {
                                    gotoxy(j*2, k);
                                    printf("%c ",MINA);//Si stampano visibilmente le mine su il campo
                                }
                            }
                        }
                        cursor_hide();
                        delay(3000);
                        clrscr();
                        impostaschermoMenu();
                        printf("\n\n\n\tThe End");//Si comunica al giocatore di aver vinto
                        delay(2000);
                        esci=true;
                    }

                }
                break;
            case ESC://Se si esce dal gioco si salvano prima i dati della partita su un file DATA.TXT
                fp=fopen("data.txt","w");
                fprintf(fp,"difficolta <%d>\ntema <%d>\n", dif, tema);
                fprintf(fp,"conta <%d>\n", conta);
                for(int k=0; k< righe; k++)
                {
                    for(int j=0; j< colonne; j++)
                    {
                        fprintf(fp,"%d ",campo[k][j]);
                    }
                    fprintf(fp,"\n");
                }
                for(int k=0; k< righe; k++)
                {
                    for(int j=0; j< colonne; j++)
                    {
                        fprintf(fp,"%d ",campoMostrato[k][j]);
                    }
                    fprintf(fp,"\n");
                }
                fclose(fp);
                esci=true;
                break;
            default:
                break;
            }

        }
    }
    setTextColor(7);
}

void selezioneCampoMinato(int n, int x, int y, int campo[][DIM], int r, int c, int campoMostrato[][DIM], int *conta)
{
    if(n==MINA)         //In questa funzione a seconda del tipo di casella scelta nel campo vengono effetuate diverse operazioni
    {
        printf("%c", MINA);
        hoPerso();
    }
    else
    {
        if(n>0 && campoMostrato[y][x/2]==0)//Si controlla sempre che la casella scelta non sia già stata scelta precedentemente
        {
            printf("%d", n);
            *conta+=1;//Viene tenuto il conto delle caselle liberate per segnare successivamente la vittoria
            campoMostrato[y][x/2]=1;
        }
        else
        {
            liberaCampo(x, y, campo, r, c, campoMostrato, conta);
        }
    }
}

void liberaCampo(int x, int y, int campo[][DIM], int r, int c, int campoMostrato[][DIM], int * conta)//Piccola Funzione ricorsiva
{
    if(campo[y][x/2]==0 && campoMostrato[y][x/2]!=1)//Questa funzione entra in gioco quando viene selezionata una casella vuota(con lo zero)
    {
        //In questo caso tutte le caselle adiacenti vengono controllate e svuotate a loro volta in caso di 0 o numeri maggiori di esso(escluse mine)
        gotoxy(x, y);
        printf("%c", VUOTO);
        *conta+=1;
        campoMostrato[y][x/2]=1;
        if(y>0)//Vengono effettuati diversi contolli per non uscire dallo schermo e andare in errore
        {
            liberaCampo(x, y-1, campo, r, c, campoMostrato, conta);
            if(x>0)
            {
                liberaCampo(x-2, y, campo, r, c, campoMostrato, conta);
                liberaCampo(x-2, y-1, campo, r, c, campoMostrato, conta);
            }
            if(x<c*2-2)
            {
                liberaCampo(x+2, y, campo, r, c, campoMostrato, conta);
                liberaCampo(x+2, y-1, campo, r, c, campoMostrato, conta);
            }
        }
        if(y< r-1)
        {
            liberaCampo(x, y+1, campo, r, c, campoMostrato, conta);
            if(x>0)
            {
                liberaCampo(x-2, y, campo, r, c, campoMostrato, conta);
                liberaCampo(x-2, y+1, campo, r, c, campoMostrato, conta);
            }
            if(x<c*2-2)
            {
                liberaCampo(x+2, y, campo, r, c, campoMostrato, conta);
                liberaCampo(x+2, y+1, campo, r, c, campoMostrato, conta);
            }
        }
    }
    if(campo[y][x/2]!=MINA && campo[y][x/2]>0 && campoMostrato[y][x/2]==0)
    {
        gotoxy(x, y);
        printf("%d", campo[y][x/2]);
        *conta+=1;
        campoMostrato[y][x/2]=1;
    }
}

void hoPerso()
{
    delay(2000);//Una semplice funzione che comunica di aver perso prima di tornare al menu
    clrscr();
    impostaschermoMenu();
    printf("\n\n\n\tGAME OVER");
    cursor_hide();
    delay(2000);
}

void stampaCampoMinato(int r, int c, int mine, int campo[][DIM])
{
    int posizionec=0;   //In questa funzione oltre ad essere stampato il campo vengono anche posizionate N mine che vengono poi salvate su una matrice CAMPO[][]
    int posizioner=0;
    int nmine=0;
    bool ok=false;
    srand(time(NULL));
    for(int k=0; k< r; k++)
    {
        for(int j=0; j< c; j++)
        {
            campo[k][j]=0;//La matrice viene prima formattata
        }
    }
    clrscr();
    for(int k=0; k<r; k++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%c",CAR);
            if(j<c-1)
            {
                printf(" ");
            }
        }
        if(k<r-1)
        {
            printf("\n");
        }
    }
    for(int q=0; q< mine; q++)
    {
        do
        {

            ok=false;
            posizionec=rand()% c;//Vengono scelte randomicamente le mine e salvate in matrice
            posizioner=rand()% r;
            if(campo[posizioner][posizionec]==0)//Si verifica che non ci siano ripetizioni
            {
                campo[posizioner][posizionec]=MINA;
                ok=true;
            }
        }
        while(ok==false);

    }
    for(int k=0; k< r; k++)
    {
        for(int j=0; j< c; j++)
        {
            if(campo[k][j]!=MINA)//Un lungo ciclo che per ogni casella non contenente una mina viene contato il numero di mine adiacenti ad essa,
            {
                //questo numero viene poi assegnato alla casella

                nmine=0;
                if(j>0)
                {
                    if(campo[k][j-1]==MINA)
                    {
                        nmine++;
                    }
                    if(k>0)
                    {
                        if(campo[k-1][j-1]==MINA)
                        {
                            nmine++;
                        }
                    }
                }
                if(k>0)
                {
                    if(campo[k-1][j]==MINA)
                    {
                        nmine++;
                    }
                    if(j<c-1)
                    {
                        if(campo[k-1][j+1]==MINA)
                        {
                            nmine++;
                        }
                    }
                }
                if(j<c-1)
                {
                    if(campo[k][j+1]==MINA)
                    {
                        nmine++;
                    }
                    if(k<r-1)
                    {
                        if(campo[k+1][j+1]==MINA)
                        {
                            nmine++;
                        }
                    }
                }
                if(k<r-1)
                {
                    if(campo[k+1][j]==MINA)
                    {
                        nmine++;
                    }
                    if(j>0)
                    {
                        if(campo[k+1][j-1]==MINA)
                        {
                            nmine++;
                        }
                    }
                }
                campo[k][j]=nmine;
            }

        }

    }
}

void impostaschermoMenu()
{
    clrscr();
    system("mode con: cols=25 lines=10");
}

void impostaschermoEasy()
{
    clrscr();
    system("mode con: cols=17 lines=9");
}

void impostaschermoMed()
{
    clrscr();
    system("mode con: cols=35 lines=18");
}

void impostaschermoHard()
{
    clrscr();
    system("mode con: cols=71 lines=36");
}

void loadGame(int campo[][DIM], int campoMostrato[][DIM])//Funzione che in alcuni casi precede quella di Play()
{
    FILE* fp;
    int dif, tema;
    int conta=0;
    int righe, colonne;
    if(fp=fopen("data.txt","r")==NULL)
    {
        clrscr();
        printf("\n\n\n\tError\n There is no saved data");//Error nel caso non ci siano partite salvate e pertanto il file DATA.TXT
        delay(2000);
    }
    else
    {
        fclose(fp);
        fp=fopen("data.txt","r");
        fscanf(fp,"difficolta <%d>", &dif);//Vengono letti tutti i dati da file
        fscanf(fp,"\ntema <%d>", &tema);
        fscanf(fp,"\nconta <%d>", &conta);
        switch (dif)
        {
        case 0:
            righe=REASY;
            colonne=CEASY;
            impostaschermoEasy();//Vengono assegnate le varie impostazioni della partita
            break;
        case 1:
            righe=RMED;
            colonne=CMED;
            impostaschermoMed();
            break;
        case 2:
            righe=RHARD;
            colonne=CHARD;
            impostaschermoHard();
            break;
        }
        switch (tema)
        {
        case 0:
            setTextColor(TEMA0);
            break;
        case 1:
            setTextColor(TEMA1);
            break;
        case 2:
            setTextColor(TEMA2);
            break;
        }
        for(int k=0; k<righe; k++)
        {
            for(int j=0; j<colonne; j++)
            {
                fscanf(fp, "%d",&campo[k][j]);//Viene caricato il campo da gioco
            }
        }
        for(int k=0; k<righe; k++)
        {
            for(int j=0; j<colonne; j++)
            {
                fscanf(fp, "%d",&campoMostrato[k][j]);
            }
        }
        fclose(fp);
        play(campo, campoMostrato, dif, tema, true, conta);
    }

}

void menuOption()//Un 'sotto menu' per modificare alcune impostazioni di gioco(difficolta e tema)
{
    bool esci=false;
    int menu=0, menup=0, a;
    int dif=0;
    int tema=0;
    FILE*fp;
    fp=fopen("option.txt","r");
    fscanf(fp, "difficolta <%d>", &dif);
    fscanf(fp, "\ntema <%d>", &tema);
    fclose(fp);
    stampaOption(menu, dif, tema);
    while (!esci)
    {

        if (kbhit() == true)
        {
            cursor_hide();
            menup=menu;
            a = getch();
            switch(a)
            {
            case SU:
                menu--;
                if(menu<DIFFICOLTA)
                {
                    menu=TEMA;
                }
                break;
            case GIU:
                menu++;
                if(menu>TEMA)
                {
                    menu=DIFFICOLTA;
                }
                break;
            case DES:
                if(menu==DIFFICOLTA)
                {
                    dif++;
                    if(dif>2)
                    {
                        dif=0;
                    }
                }
                if(menu==TEMA)
                {
                    tema++;
                    if(tema>2)
                    {
                        tema=0;
                    }
                }
                menup=-1;
                break;
            case SIN:
                if(menu==DIFFICOLTA)
                {
                    dif--;
                    if(dif<0)
                    {
                        dif=2;
                    }
                }
                if(menu==TEMA)
                {
                    tema--;
                    if(tema<0)
                    {
                        tema=2;
                    }
                }
                menup=-1;
                break;
            case INVIO:
                break;
            case ESC:
                esci=true;
                break;
            default:
                break;
            }
            if(menu!=menup)
            {
                clrscr();
                stampaOption(menu, dif, tema);
            }
        }
    }
    fp=fopen("option.txt","w");
    fprintf(fp,"difficolta <%d>\n", dif);//Vengono salvate le impostazioni scelte in un file OPTION.TXT
    fprintf(fp,"tema <%d>", tema);
    fclose(fp);
}

void stampaOption(int n, int dif, int tema)//Un susseguire di funzioni(stampaOption-> SelezioneDifficolta/SelezioneTema) che hanno una semplice funzione grafica tramite PRINTF
{
    switch(n)
    {
    case DIFFICOLTA:
        clrscr();
        selezioneDifficolta(dif);
        break;
    case TEMA:
        clrscr();
        selezioneTema(tema);
        break;
    default:
        break;

    }
}

void selezioneDifficolta(int n)
{
    switch (n)
    {
    case 0:
        clrscr();
        option00();
        break;
    case 1:
        clrscr();
        option01();
        break;
    case 2:
        clrscr();
        option02();
        break;
    default:
        break;
    }
}

void selezioneTema(int n)
{
    switch (n)
    {
    case 0:
        clrscr();
        option10();
        break;
    case 1:
        clrscr();
        option11();
        break;
    case 2:
        clrscr();
        option12();
        break;
    default:
        break;
    }
}

void option00()
{
    printf("\n\t********\n\n     ->DIFFICOLTA' <Easy>\n\n\t TEMA\n\n\t********");
}

void option01()
{
    printf("\n\t********\n\n     ->DIFFICOLTA' <Med>\n\n\t TEMA\n\n\t********");
}

void option02()
{
    printf("\n\t********\n\n     ->DIFFICOLTA' <Hard>\n\n\t TEMA\n\n\t********");
}

void option10()
{
    printf("\n\t********\n\n       DIFFICOLTA'\n\n       ->TEMA <Retro>\n\n\t********");
}

void option11()
{
    printf("\n\t********\n\n       DIFFICOLTA'\n\n       ->TEMA <ForzaJuve>\n\n\t********");
}

void option12()
{
    printf("\n\t********\n\n       DIFFICOLTA'\n\n       ->TEMA <Cicamala>\n\n\t********");
}
