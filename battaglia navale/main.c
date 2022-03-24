
/*
    spicoli piersilvio

    regole del piccolo pier:
        # = barche dell'avversario
        . = zone della mappa vuota
        x = nave colpita
        @ = nave mancata

        la dimensione di una barca è di una casella
        l'utente ha 10 possibilità di azzeccare la posizione della barca!
        se le azzecca prima dei 10 tentativi, allora il gioco termina e stampa il msg di vittoria!
        altrimenti un msg di sconfitta!

        fornire un menu!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//costanti
#define m_col 6
#define n_rig 6

//matrice di gioco e variabili globali
char campo[n_rig][m_col] = {" 12345", "A.....", "B.....", "C.....", "D.....", "E....."}; //campo dove verranno generate le navi della cpu
char battaglia[n_rig][m_col] = {" 12345", "A.....", "B.....", "C.....", "D.....", "E....."}; //campo di inserimento da parte dell'utente
int tentativi = 2; //variabile che verrà decrementata ogni volta che l'utente manca la nave della cpu

//dichiarazione prototipi di funzione
void Print();
void gen_barche_cpu(int);
void attacco(int, int);
void Print_c();

int main(){

    //variabili locali
    int n_max_barche = 4; //numero di barche massimo da parte della cpu e dell'utente
    int attacco_ut = 0; //variabile che ricevere il risultato della funzione attacco()
    char coo1 = 0, coo2 = 0;

    srand(time(NULL));
    gen_barche_cpu(n_max_barche); //generiamo le barche in modo random!


        puts("\tBattaglia navale del piccolo Pier!\n");
        puts("regole di gioco: \n");
        puts("_> # = barche dell'avversario\n");
        puts("_> . = zone della mappa vuota\n");
        puts("_> x = nave colpita\n");
        puts("_> @ = nave mancata\n");
        puts("\n");

       while(tentativi > 0){

            Print();
            Print_c();
            puts("\n");
            puts("_> inserire le coordinate (es. a3 ecc): ");
            scanf("%c%c", &coo1, &coo2);

            coo1=toupper(coo1); //rendiamola maiuscola, qualora l'utente inserirsca una lettera minuscola

            attacco(coo1, coo2); //viene effettuato un attacco!

        };

        puts("\n_> Hai vinto! \n");

    return 0;
}

void attacco(int c1, int c2){

        //verifico se l'utente ha immesso la posizione sul campo di battaglia
        if(c1>='A' && c1<='E' && c2>='1' && c2<='5' && battaglia[c1-'A'+1][c2-'1'+1] == '.')
        {
            if(campo[c1-'A'+1][c2-'1'+1] == '#')
            {
                battaglia[c1 - 'A' + 1][c2 - '1' + 1] = '@'; //attacco mancato!
                tentativi = tentativi - 1;
                puts("_> nave mancata! riprova! \n");
                printf("_> tentativi rimanenti: %d", tentativi);

            }else
            {
                battaglia[c1 - 'A' + 1][c2 - '1' + 1] = 'x'; //attacco riuscito!
                tentativi = tentativi - 1;
                puts("_> nave colpita! continua cosi! \n");
                printf("_> tentativi rimanenti: %d", tentativi);
            }
        }
}

void Print(){

    //variabili locali
    int i, j;

    puts("\n");
    for(i = 0; i < n_rig; i++){
        for(j = 0; j < m_col; j++){
            printf("\t%c", battaglia[i][j]);
        }
        puts("\n");
    }
}

void Print_c(){

    //variabili locali
    int i, j;

    puts("\n");
    for(i = 0; i < n_rig; i++){
        for(j = 0; j < m_col; j++){
            printf("\t%c", campo[i][j]);
        }
        puts("\n");
    }
}

/*

    funzione di generazione delle barche.
    generiamo dei valori compresi da 0 a 6 sugli indici. Dopodichè, verifichiamo se la posizione
    generata non contenga la barca, se libera viene inserita la barca nella pos. corrente, altrimenti
    verrà generata una nuova posizione.

*/

void gen_barche_cpu(int n_barche){

    //variabili locali
    int cont = 0, i, j; //indice di iterazione

    while(cont < n_barche){

        //generiamo i valori delle posizioni
        i = rand()% n_rig;
        j = rand()% m_col;

        if(campo[i - 'A' + 1][j - '1' + 1] != '#'){
            cont += 1;
            campo[i - 'A' + 1][j - '1' + 1] = '#';
        }
    }
}
