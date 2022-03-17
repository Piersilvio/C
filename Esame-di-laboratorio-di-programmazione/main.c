/*
 * main.c
 *
 *  Created on: 14 mag 2021
 *      Author: Pierilvio Spicoli
 *      Author: Giulio Russo
 */

#include "creatore.h"
#include "gui.h"
#include "reg_login.h"
#include "strutture.h"
#include "utente.h"

int main()
{
	setbuf(stdout, 0);

	//var. locali
	int scelta = 0;

	//apriamo i file ed effettuamo il controllo sulla loro esistenza
	user = fopen("user.dat", "rb+");
	dati_img = fopen("img.dat", "rb+");
	azioni = fopen("azioni.dat", "rb+");

	if(user == NULL || dati_img == NULL || azioni == NULL)
	{
		puts("impossibile aprire il file!!\n");
	}
	else
	{
		do
		{
			ui_menu_main();
			scanf("%d", &scelta);

			if(scelta == 1)
			{
				registrazione(user);
			}
			else if (scelta == 2)
			{
				login(user);
			}
			else if (scelta == 3)
			{
				return 0;
			}
		}while(scelta != 2 && scelta != 1);
	}

	fclose(user);
	fclose(dati_img);
	fclose(azioni);
}

