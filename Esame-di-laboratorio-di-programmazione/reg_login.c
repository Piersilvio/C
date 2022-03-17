/*
 * reg_login.c
 *
 *  Created on: 14 mag 2021
 *      Author: Pierilvio Spicoli
 *      Author: Giulio Russo
 */

#include "reg_login.h"
#include "creatore.h"
#include "gui.h"
#include "strutture.h"
#include "utente.h"

void registrazione(FILE* user) //FATTO
{
	//var. locali
	int scelta = 0;
	char sessione[MAX_STRINGA];

	do
	{
		ui_menu_reg();
		scanf("%d", &scelta);

		if(scelta == 1)
		{
			//inserimento dati come creatore
			ui_info_reg();

			puts("Nome_> ");
			scanf("%s", ut.nome);
			puts("Cognome_> ");
			scanf("%s", ut.cognome);
			puts("Username_> ");
			scanf("%s", ut.username);

			/*
			 * controllo password
			 *  una pw deve essere da 10 caratteri e con almeno una maiuscola e un numero, nel caso non fosse, ripete l'input
			 */

			check_pw();

			strcat(ut.id, "CR");
			strcpy(sessione, ut.username); //attivazione sessione
			ut.n_vettoriale = 0;
			ut.n_icona = 0;
			ut.n_foto = 0;

			fseek(user, 0*sizeof(utenti), SEEK_END);
			fwrite(&ut, sizeof(utenti), 1, user);
			creatore(sessione);

		}
		else if(scelta == 2)
		{
			//inserimento dati come utilizzatore
			ui_info_reg();

			puts("Nome_> ");
			scanf("%s", ut.nome);
			puts("Cognome_> ");
			scanf("%s", ut.cognome);
			puts("Username_> ");
			scanf("%s", ut.username);

			/*
			 * controllo password
			 *  una pw deve essere da 10 caratteri e con almeno una maiuscola e un numero, nel caso non fosse, ripete l'input
			 */

			check_pw();

			strcpy(ut.id, "UT");
			strcpy(sessione, ut.username); //attivazione sessione

			fseek(user, 0*sizeof(utenti), SEEK_END);
			fwrite(&ut, sizeof(utenti), 1, user);
			utente(sessione);
		}
	}while(scelta < 1 || scelta > 2);
}

void login(FILE* user) //FATTO
{
	//var. locali
	char pw_input[MAX_STRINGA];
	char user_input[MAX_STRINGA];
	int flag = 0;
	int scelta = 0;
	char sessione[MAX_STRINGA];

	ui_menu_login();

	printf("inserire username_> ");
	scanf("%s", user_input);
	printf("inserire pw_> ");
	scanf("%s", pw_input);

	//leggiamo i dati dal file e controlliamo per ogni occorrenza se i dati in input sono corretti, altrimenti si stampi un msg di errore
	rewind(user);
	while(!feof(user))
	{
		fread(&ut, sizeof(utenti), 1, user);
		if((strcmp(user_input, ut.username) == 0) && (strcmp(pw_input, ut.pw) == 0))
		{
			if(strcmp(ut.id , "CR") == 0)
			{
				strcpy(sessione, ut.username); //attivazione sessione
				creatore(sessione);
				flag = 1;
			}
			else if(strcmp(ut.id, "UT") == 0)
			{
				strcpy(sessione, ut.username); //attivazione sessione
				utente(sessione);
				flag = 1;
			}
		}
	}

	if(flag == 0)
	{
		printf("username o password non corretti.\n");
		printf("ripetere il login? (1 - si) (2 - no)");
		scanf("%d", &scelta);

		if(scelta == 1)
		{ login(user); }
	}
}

void check_pw() //FATTO
{
	//var. locali
	int flag_up; //flag di controllo se esistono i numero
	int flag_num; //flag di controllo se esistono car maiuscoli
	int flag; //controllo di ripetizione una volta che la pw � stata sbaglieta
	int i;

	do{
		flag = 0;//inizializzo a zero

		puts("la pw deve contenere almeno un carattere maiuscolo e un numero (max. 10 caratteri)\n");
		puts("Password_> ");
		scanf("%s", ut.pw);

		if(strlen(ut.pw) <= MAX_CH_PW) //se la lunghezza non supera i 10 caratteri, allora effettuo i controlli
		{

			flag = 1;

			//inizializzo i flag ad ogni iterazione
			flag_up = 0;
			flag_num = 0;

			//ricerco i numeri e caratteri maiuscoli, qualora esistessero
			for(i = 0; i < MAX_CH_PW; i++)
			{
				flag_num += isdigit(ut.pw[i]);
				flag_up += isupper(ut.pw[i]);

				if(flag_num == 1 && flag_up == 1)
				{
					i = MAX_CH_PW;
				}
			}

			if((flag_num == 1) && (flag_up == 1))
			{
				puts("_> pw corretta!\n");
				puts("_> la pw e' ");
				puts(ut.pw);
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
}

