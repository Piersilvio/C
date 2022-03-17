	/*
 * creatore.c
 *
 *  Created on: 14 mag 2021
 *      Author: Pierilvio Spicoli
 *      Author: Giulio Russo
 */

#include "creatore.h"
#include "gui.h"
#include "strutture.h"

void creatore(char sessione[]) //FATTO
{
	//var. locali
	int scelta = 0;

	do{
		ui_menu_creatore();
		scanf("%d", &scelta);

		switch(scelta)
		{
		case 1:
			cancella_img(dati_img, sessione);
			break;
		case 2:
			modifica_img(dati_img, sessione);
			break;
		case 3:
			ins_img(dati_img, user, sessione); //deve rest. 1 se l'inserimento � avvenuto, altrimenti 0
			break;
		case 4:
			cancella_account(user, dati_img, sessione);
			break;
		case 5:
			modifica_account(user, sessione);
			break;
		case 6:
			exit(0);
			break;
		}

	}while(scelta < 1 || scelta > 6);
}

void aggiornamento_stat(FILE* user, char sessione[], char tipo[])
{
	//var. locali
	int posizione = -1;
	int i = 0;
	utenti tmp;

	//ricerchiamo il record da aggiornare
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
		//aggiorniamo i dati riguardanti alle tipologie
		fseek(user, (sizeof(utenti) * (posizione)), SEEK_SET);
		if(strcmp(tipo, "vettoriale") == 0)
		{
			tmp.n_vettoriale++;
		}
		else if(strcmp(tipo, "foto") == 0)
		{
			tmp.n_foto++;
		}
		else if(strcmp(tipo, "icona") == 0)
		{
			tmp.n_icona++;
		}

		fwrite(&tmp, sizeof(utenti), 1, user);
	}
}

void ins_img(FILE* dati_img, FILE* user, char sessione[])
{
	//var. locali
	int scelta_tip_input = 0;
	int scelta = 0;

	ui_menu_insImg();

	printf("Titolo_> ");
	scanf("%s", img.titolo);
	printf("nome del file (inserisci solo il nome del file)");
	scanf("%s", img.nome_file);
	do{

		printf("Tipologia della foto (scegli fra le tre qui sotto)_> \n");
		printf("1) vettoriale \t 2) icona \t 3)foto ");
		scanf("%d", &scelta_tip_input);
		if(scelta_tip_input == 1)
		{
			strcpy(img.tipo, "vettoriale");
			strcat(img.nome_file, ".svg");
			ut.n_vettoriale++;
		}
		else if(scelta_tip_input == 2)
		{
			strcpy(img.tipo, "icona");
			strcat(img.nome_file, ".png");
			ut.n_icona++;
		}
		else if(scelta_tip_input == 3)
		{
			strcpy(img.tipo, "foto");
			strcat(img.nome_file, ".jpg");
			ut.n_foto++;
		}

	}while(scelta_tip_input < 1 || scelta_tip_input > 3);

	strcpy(img.creatore, sessione);

	fseek(dati_img, sizeof(immagine), SEEK_END);
	fwrite(&img, sizeof(img), 1, dati_img); //scrivi su img.dat

	aggiornamento_stat(user, sessione, img.tipo); //richiamiamo la procedura ogni volta che avviene l'input dell'img

	puts("inserimento avvenuto!\n");
	do
    {
        printf("premi 1 per tornare al menu creatore_> ");
        scanf("%d", &scelta);
        if(scelta == 1)
            creatore(sessione);
    }while(scelta != 1);
}

void cancella_img(FILE* dati_img, char sessione[])
{
	//var. locali
	char n_file_input[MAX_STRINGA];
	int scelta;
	int flag = 0;
	FILE* pt_tmp;

	pt_tmp = fopen("tmp.dat", "wb");
	ui_menu_cancellaImg();

	//visualizzo tutte le immagini caricate dal creatore corrente
	rewind(dati_img);
	while(!feof(dati_img))
	{
		if(fread(&img, sizeof(immagine), 1, dati_img) != 0)
		{
			if(strcmp(sessione, img.creatore) == 0)
			{
				printf("\t%s\t%s\t%s\n", img.titolo, img.tipo, img.nome_file);
			}
		}
	}

	puts("\nInserire il nome del file da cancellare_> ");
	scanf("%s", n_file_input);

	/*
	 * per cancellare su file, isoliamo il record che vogliamo cancellare
	 * per poi scrivere tutte le occorrenze eccetto quella cercata su un file temporaneo
	 * da rinominare in quello originale e cancellare l'originale
	 */

	rewind(pt_tmp);
	rewind(dati_img);
	while(fread(&img, sizeof(immagine), 1, dati_img) != 0)
	{
		if(strcmp(n_file_input, img.nome_file) == 0)
		{
			flag = 1;
			puts("Cancellazione effettuata!\n");
		}
		else
		{
			fwrite(&img, sizeof(immagine), 1, pt_tmp);
		}
	}

	if(!flag)
	{
		puts("Nome del file dell'immagine inesistente!\n");
	}

	fclose(pt_tmp);
	fclose(dati_img);
	remove("img.dat");
	rename("tmp.dat", "img.dat");

	dati_img = fopen("img.dat", "rb+");

	do
    {
        printf("premi 1 per tornare al menu creatore_> ");
        scanf("%d", &scelta);
        if(scelta == 1)
            creatore(sessione);
    }while(scelta != 1);
}

void modifica_account(FILE* user, char sessione[])
{
	//var. locali
	int i = 0;
	int posizione_ut = -1;
	utenti tmp_ut;
	int flag_up;
	int flag_num;
	int flag;
	int scelta = 0;

	ui_mod_conferma();
	scanf("%d", &scelta);

	if(scelta == 1)
	{
		//ricerchiamo l'utente da modifcare nel file
		rewind(user);
		while(fread(&ut, sizeof(utenti), 1, user) != 0)
		{
			if(strcmp(sessione, ut.username) == 0)
			{
				posizione_ut = i;
				tmp_ut = ut;
			}
			i++;
		}

		if(posizione_ut != -1)
		{
			fseek(user, (sizeof(utenti) * (posizione_ut)), SEEK_SET);

			//inseriamo i nuovi dati dell'utente creatore
			puts("Nome_> ");
			scanf("%s", tmp_ut.nome);
			puts("Cognome_> ");
			scanf("%s", tmp_ut.cognome);
			puts("Username_> ");
			scanf("%s", tmp_ut.username);

			//controllo password inserita in input
			do{
				flag = 0;

				puts("la pw deve contenere almeno un carattere maiuscolo e un numero (max. 10 caratteri)\n");
				puts("Password_> ");
				scanf("%s", tmp_ut.pw);

				if(strlen(tmp_ut.pw) <= MAX_CH_PW)
				{
					flag = 1;
					flag_up = 0;
					flag_num = 0;

					for(i = 0; i < MAX_CH_PW; i++)
					{
						flag_num += isdigit(tmp_ut.pw[i]);
						flag_up += isupper(tmp_ut.pw[i]);

						//blocca il ciclo nel caso in cui sono stati trovati il carr. maiuscolo e il numero
						if(flag_num == 1 && flag_up == 1){
							i = MAX_CH_PW;
						}
					}

					if((flag_num == 1)&&(flag_up == 1))
					{
						puts("_> pw corretta!\n");
						puts("_> la pw e' ");
						puts(tmp_ut.pw);
					}
					else if(flag_num == 0)
					{
						flag = 0;
						puts("_> non contiene un numero!\n");

					}else if(flag_up == 0){

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

			fwrite(&tmp_ut, sizeof(utenti), 1, user);

			printf("Modifica delle credenziali Riuscite!\n");
			printf("Adesso verr� terminato il programma per applicare le modifiche!\n");
			system("pause");
			exit(0);
		}
	}
	else
	{
		creatore(sessione);
	}
}

void modifica_img(FILE* dati_img, char sessione[])
{
	//var. locali
	char n_file_input[MAX_STRINGA];
	int scelta_tip_input = 0;
	int scelta;
	int i = 0;
	int posizione = -1;
	immagine tmp;

	ui_menu_modificaImg();

	//visualizziamo tutte le immagine caricate dal creatore corrente
	rewind(dati_img);
	while(!feof(dati_img))
	{
		fread(&img, sizeof(immagine), 1, dati_img);
		if (!feof(dati_img))
		{
			if(strcmp(sessione, img.creatore) == 0)
			{
				printf("\t%s\t%s\t%s\n", img.titolo, img.tipo, img.nome_file);
			}
		}
	}

	puts("\nInserire il nome del file da modificare_> ");
	scanf("%s", n_file_input);

	//ricerchiamo la posizione del record da modificare
	rewind(dati_img);
	while(fread(&img, sizeof(immagine), 1, dati_img) != 0)
	{
		if(strcmp(n_file_input, img.nome_file) == 0)
		{
			posizione = i;
			tmp = img;
		}
		i++;
	}

	if(posizione != -1)
	{
		fseek(dati_img, (sizeof(immagine) * (posizione)), SEEK_SET);

		//aggiorniamo i dati dell'immagine corrente
		printf("Bene! Adesso procedi con l'inserire i nuovi dati:\n");
		printf("Titolo_> ");
		scanf("%s", tmp.titolo);
		printf("nome del file (inserisci solo il nome del file)");
		scanf("%s", tmp.nome_file);
		do{
			printf("Tipologia della foto (scegli fra le tre qui sotto)_> \n");
			printf("1) vettoriale \t 2) icona \t 3)foto ");
			scanf("%d", &scelta_tip_input);
			if(scelta_tip_input == 1)
			{
				strcpy(tmp.tipo, "vettoriale");
				strcat(tmp.nome_file, ".svg");
			}
			else if(scelta_tip_input == 2)
			{
				strcpy(tmp.tipo, "icona");
				strcat(tmp.nome_file, ".png");
			}
			else if(scelta_tip_input == 3)
			{
				strcpy(tmp.tipo, "foto");
				strcat(tmp.nome_file, ".jpg");
			}
		}while(scelta_tip_input < 1 || scelta_tip_input > 3);

		fwrite(&tmp, sizeof(immagine), 1, dati_img);

		puts("Modifica Riuscita!\n");
		do
        {
            printf("premi 1 per tornare al menu creatore_> ");
            scanf("%d", &scelta);
            if(scelta == 1)
                creatore(sessione);
        }while(scelta != 1);
	}
	else
	{
		puts("Nome del file inesistente!\n");
		creatore(sessione);
	}
}

void cancella_account(FILE* user, FILE* dati_img, char sessione[])
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
			//cancellazione immagini caricate del creatore corrente
			pt_tmp1 = fopen("tmp.dat", "wb");

			rewind(pt_tmp1);
			rewind(dati_img);
			while(fread(&img, sizeof(immagine), 1, dati_img) != 0)
			{
				if(strcmp(sessione, img.creatore) != 0)
				{
					fwrite(&img, sizeof(immagine), 1, dati_img);
				}
			}

			fclose(pt_tmp1);
			fclose(dati_img);
			remove("img.dat");
			rename("tmp.dat", "img.dat");

			dati_img = fopen("img.dat", "rb+");

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
			creatore(sessione);
		}

	}while(scelta < 1 || scelta > 2);

}
