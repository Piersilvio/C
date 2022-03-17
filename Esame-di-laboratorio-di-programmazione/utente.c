/*
 * utente.c
 *
 *  Created on: 14 mag 2021
 *      Author: Spicoli Piersilvio
 *      Author: Russo Giulio
 */

#include "utente.h"
#include "gui.h"
#include "strutture.h"

void utente(char sessione[]) //FATTO
{
	//var. locali
	int scelta = 0;

	do{
		ui_menu_utente();

		scanf("%d", &scelta);

		switch(scelta)
		{
		case 1:
			img_evidenza(azioni, sessione);
			break;
		case 2:
			ricerca_img(dati_img, azioni, sessione);
			break;
		case 3:
			azioni_utente(azioni, sessione);
			break;
		case 4:
			stat(user, sessione);
			break;
		case 5:
			modifica_account_ute(user, sessione);
			break;
		case 6:
			cancella_account_ute(user, azioni, sessione);
			break;
		case 7:
			exit(0);
			break;
		}

	}while(scelta < 1 || scelta > 7);
}

void sorting(azioni_ut array[], int dim){

	//var. locali
    azioni_ut tmp;
    int j, k;

    /*
     * applicazione dell'algoritmo di ordinamento
     * Selection Sort
     * caso peggiore/ottimale/medio nel tempo: O(n^2) lineare
     *
     * funzionamento:
     * L'algoritmo seleziona di volta in volta il numero minore nella sequenza di partenza e lo sposta nella sequenza ordinata.
     * Dovendo ordinare un array A di lunghezza n, si fa scorrere l'indice i da 1 a n-1 ripetendo i seguenti passi:
	 * si cerca il più piccolo elemento della sottosequenza A[i..n];
	 * si scambia questo elemento con l'elemento i-esimo.
	 *
	 * Applicazione:
	 * Abbiamo deciso di applicare questo algoritmo per stampare in ordine Decrescente in base alla valutazione corrente scritta su file
	 * al numero di valutazioni ricevute, che corrisponde, per scelte progettuali, al numero di download, poichè per valutare una immagine
	 * l'utilizzatore la deve scaricare.
	 *
     */

    for(j = 0; j < dim-1; j++)
    {
        for(k = j + 1; k < dim; k++)
        {
            if((array[j].val < array[k].val) && (array[j].n_val < array[k].n_val))
            {
                tmp = array[j];
                array[j] = array[k];
                array[k] = tmp;
            }
        }
    }
}

void img_evidenza(FILE* azioni, char sessione[])
{
	//var. locali
	azioni_ut array[100];
	azioni_ut tmp;
	int scelta = 0;
	int i = 0, j = 0;

	azioni = fopen("azioni.dat", "rb+");

	//conto gli elementi all'interno del file
	if(azioni != NULL) {
		rewind(azioni);
		while(!feof(azioni)) {

			fread(&array[i], sizeof(azioni_ut), 1, azioni);
			if(!feof(azioni)) {
				i++;
			}
		}

		//ordino i primi elementi
		sorting(array, i);

		//ordino e assegno all'array temporaneo ogni record letto e l'ordino un'altra volta
		while(!feof(azioni))
		{
			fread(&tmp, sizeof(azioni_ut), 1, azioni);
			if(!feof(azioni))
			{
				if((tmp.val < array[i-1].val) && (tmp.n_val < array[i-1].n_val))
				{
					array[i-1] = tmp;
					sorting(array, i);
				}
			}
		}
	}

	ui_menu_imgEv();

	//visualizzo i record ordinati, stampando le loro val. correnti e i titoli
	for (j = 0; j < i; j++)
	{
		printf("\t%s \t%d \n", array[j].titolo_ut.titolo, array[j].val);
	}
	fclose(azioni);

	do
    {
        printf("\npremi 1 per tornare al menu creatore_> ");
        scanf("%d", &scelta);
        if(scelta == 1)
        {
            utente(sessione);
        }
    }while(scelta != 1);

	fclose(azioni);
}

void stat(FILE* user, char sessione[])
{
	//var. locali
	int scelta = 0;

	ui_menu_stat();

	//visualizzo tutte le statistiche dei creatori, scorrendo il file ad ogni iterazione
	rewind(user);
	while(fread(&ut, sizeof(utenti), 1, user))
	{
		if(!feof(user))
		{
			if(strcmp(ut.id, "CR") == 0)
			{
				printf("\t%s \t\t%d   \t\t%d        \t%d\n", ut.username, ut.n_vettoriale, ut.n_foto, ut.n_icona);
			}
		}
	}

	do
    {
        printf("\npremi 1 per tornare al menu creatore_> ");
        scanf("%d", &scelta);
        if(scelta == 1)
        {
            utente(sessione);
        }
    }while(scelta != 1);
}

void ricerca_img(FILE* dati_img, FILE* azioni, char sessione[])
{
	//var. locali
	char tit_input[MAX_STRINGA];
	int scelta = 0;
	int flag = 0;

	azioni = fopen("azioni.dat", "rb+");

	puts("Ricerca la tua immagine mediante il titolo_> ");
	scanf("%s", tit_input);

	//ricerca per titolo
	printf("risultati ricerca:");
	rewind(dati_img);
	while(!feof(dati_img))
	{
		fread(&img, sizeof(immagine), 1, dati_img);
		if(strncmp(tit_input, img.titolo, strlen(tit_input)) == 0)
		{
			flag = 1;
			printf("\n%s %s %s \n\n", img.titolo, img.tipo, img.nome_file); //salvo e visualizzo il record ricercato
			do
			{
				do
				{
					printf("Per valutare l'immagine, devi prima scaricarla.\n");
					printf("vuoi procedere? (1 - si) (2 - no)_> ");
					scanf("%d", &scelta);
				}while(scelta < 1 || scelta > 2);

				if(scelta == 1)
				{
					strcpy(a_t.username_ut.username, sessione); //1
					strcpy(a_t.titolo_ut.titolo, tit_input); //2
					do
					{
						printf("inserisci una valutazione (da 1 a 5)_> ");
						scanf("%d", &a_t.val); //3
					}while(a_t.val < 1 || a_t.val > 5);

					a_t.n_val++;

					//scriviamo su azioni.dat
					fseek(azioni, 0*sizeof(azioni_ut), SEEK_END);
					fwrite(&a_t, sizeof(a_t), 1, azioni);

					puts("Grazie per il tuo contributo!\n");
					printf("premi 1 per tornare al menu utente_>");
					scanf("%d", &scelta);
					utente(sessione);
				}
				else
				{
					utente(sessione);
				}

			}while(scelta < 1 || scelta > 2);
		}
	}

	if(flag == 0)
	{
		puts("Titolo non trovato!\n");
		do
        {
            printf("premi 1 per tornare al menu creatore_> ");
            scanf("%d", &scelta);
            if(scelta == 1)
                utente(sessione);
        }while(scelta != 1);
	}

	fclose(azioni);
}

void azioni_utente(FILE* azioni, char sessione[])
{
	//var. locali
	int scelta = 0;

	azioni = fopen("azioni.dat", "rb+");
	ui_menu_azioniUt();

	//visualizzo tutte le immagini scaricate e la loro val. corrente del utilizzatore corrente
	rewind(azioni);
	while(fread(&a_t, sizeof(azioni_ut), 1, azioni))
	{
		if(!feof(azioni))
		{
			if((strcmp(a_t.username_ut.username, sessione) == 0))
			{
				printf("\t%s\t\t\t%d \n", a_t.titolo_ut.titolo, a_t.val);
			}
		}
	}

	do
    {
        printf("\npremi 1 per tornare al menu creatore_> ");
        scanf("%d", &scelta);
        if(scelta == 1)
            utente(sessione);
    }while(scelta != 1);

	fclose(azioni);
}

void cancella_account_ute(FILE* user, FILE* azioni, char sessione[])
{
	//var. locali
	int scelta = 0;
	FILE* pt_tmp1; //per la cancellazione delle img del creatore
	FILE* pt_tmp2; //per la cancellazione delle credenziale del creatore

	do
	{
		ui_cancella_account();
		scanf("%d", &scelta);

		if(scelta == 1)
		{
			//cancellazione immagini scaricate del utilizzatore corrente
			pt_tmp1 = fopen("tmp.dat", "wb");

			rewind(pt_tmp1);
			rewind(azioni);
			while(fread(&a_t, sizeof(azioni_ut), 1, azioni) != 0)
			{
				if(strcmp(sessione, a_t.username_ut.username) != 0)
				{
					fwrite(&a_t, sizeof(azioni_ut), 1, pt_tmp1);
				}
			}

			fclose(pt_tmp1);
			fclose(azioni);
			remove("azioni.dat");
			rename("tmp.dat", "azioni.dat");

			azioni = fopen("azioni.dat", "rb+");

			//cancellazione account del utilizzatore corrente
			pt_tmp2 = fopen("tmp.dat", "wb");

			rewind(pt_tmp2);
			rewind(user);
			while(fread(&ut, sizeof(utenti), 1, user) != 0)
			{
				if(strcmp(sessione, ut.username) != 0)
				{
					fwrite(&ut, sizeof(utenti), 1, pt_tmp2);
				}
			}

			fclose(pt_tmp2);
			fclose(user);
			remove("user.dat");
			rename("tmp.dat", "user.dat");

			user = fopen("user.dat", "rb+");

			printf("Arrivederci %s! e' stato un piacere! \n", sessione);
			exit(0);
		}
		else
		{
			utente(sessione);
		}

	}while(scelta < 1 || scelta > 2);

}

void modifica_account_ute(FILE* user, char sessione[])
{
	//var. locali
	int i = 0;
	int posizione = -1;
	utenti tmp;
	int flag_up;
	int flag_num;
	int flag;
	int scelta = 0;

	ui_mod_conferma();
	scanf("%d", &scelta);

	if(scelta == 1)
	{
		printf("Modifica adesso le tue credenziali!\n");

		//ricerco il record da modificare
		rewind(user);
		while(fread(&ut, sizeof(utenti), 1, user) != 0)
		{
			if(strcmp(sessione, ut.username) == 0)
			{
				posizione = i;
				tmp = ut;
			}
			i++;
		}

		if(posizione != -1)
		{
			fseek(user, (sizeof(utenti) * (posizione)), SEEK_SET);

			puts("Nome_> ");
			scanf("%s", tmp.nome);
			puts("Cognome_> ");
			scanf("%s", tmp.cognome);
			puts("Username_> ");
			scanf("%s", tmp.username);

			//controllo pw inserita in input
			do{
				flag = 0;

				puts("la pw deve contenere almeno un carattere maiuscolo e un numero (max. 10 caratteri)\n");
				puts("Password_> ");
				scanf("%s", tmp.pw);

				if(strlen(tmp.pw) <= MAX_CH_PW)
				{
					flag = 1;
					flag_up = 0;
					flag_num = 0;

					for(i = 0; i < MAX_CH_PW; i++)
					{
						flag_num += isdigit(tmp.pw[i]);
						flag_up += isupper(tmp.pw[i]);

						//blocca il ciclo nel caso in cui sono stati trovati il carr. maiuscolo e il numero
						if(flag_num == 1 && flag_up == 1)
						{
							i = MAX_CH_PW;
						}
					}

					if((flag_num == 1)&&(flag_up == 1))
					{
						puts("_> pw corretta!\n");
						puts("_> la pw e' ");
						puts(tmp.pw);
					}
					else if(flag_num == 0)
					{
						flag = 0;
						puts("_> non contiene un numero!\n");
					}
					else if(flag_up == 0)
					{
						flag = 0;
						puts("_> non contiene un carattere maiuscolo!\n");
					}
				}
				else
				{
					flag = 0;
					puts("_> la lunghezza e' maggiore dei 10 caratteri\n");
				}

			}while(flag == 0);

			fwrite(&tmp, sizeof(utenti), 1, user);

			printf("Modifica delle credenziali Riuscite!\n");
			printf("Adesso verrà terminato il programma per applicare le modifiche!\n");
			system("pause");
			exit(0);
		}
	}
	else
	{
		utente(sessione);
	}
}
