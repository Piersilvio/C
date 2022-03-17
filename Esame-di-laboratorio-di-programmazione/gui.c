/*
 * gui.c
 *
 *  Created on: 27 mag 2021
 *      Author: Piersilvio Spicoli
 *      Author: Giulio Russo
 */

#include "gui.h"
#include "strutture.h"

void ui_menu_main()
{
	printf("_____________________________________\n");
	printf("+                                    \n");
	printf("+   Il nostro programma         	 \n");
	printf("+                                    \n");
	printf("+  (1) registrazione 		         \n");
	printf("+  (2) accesso                       \n");
	printf("+  (3) esci                          \n");
	printf("+                                    \n");
	printf("+  Spicoli Piersilvio                \n");
	printf("+  Russo Giulio             v2.0     \n");
	printf("_____________________________________\n");
}

void ui_menu_creatore()
{
	printf("__________________________________\n");
	printf("+                                 \n");
	printf("+    Il nostro programma       	  \n");
	printf("+                                 \n");
	printf("+   Menu Creatore:             	  \n");
	printf("+   1) cancellare una immagine 	  \n");
	printf("+   2) modificare una immagine 	  \n");
	printf("+   3) inserire una immagine	  \n");
	printf("+   4) cancella l'account    	  \n");
	printf("+   5) modifica l'account    	  \n");
	printf("+   6) esci                    	  \n");
	printf("+  				          v2.0    \n");
	printf("__________________________________\n");
}

void ui_cancella_account()
{
	printf("________________________________________________________\n");
	printf("+                                             			\n");
	printf("+                                            			\n");
	printf("+   Sicuro di voler cancellare il tuo account?          \n");
	printf("+   Confermando la tua scelta, cancellerai anche i      \n");
	printf("+  	dati realtivi alle tue azioni all'interno del       \n");
	printf("+   sistema                                         	\n");
	printf("+                                             			\n");
	printf("+   (1)si                                          		\n");
	printf("+   (2)no                                         	    \n");
	printf("________________________________________________________\n");
}

void ui_menu_insImg()
{
	printf("_____________________________________________\n");
	printf("                                             \n");
	printf("+   Il nostro programma         	   		 \n");
	printf("+                                            \n");
	printf("+   Inserimento immagine:              	     \n");
	printf("+   inseririsci la tua immagine creatore!    \n");
	printf("+  	                                         \n");
	printf("+                                            \n");
	printf("+  			                          v2.0   \n");
	printf("_____________________________________________\n");
}

void ui_menu_cancellaImg()
{
	printf("___________________________________________________________________________\n");
	printf("+                                            							   \n");
	printf("+ Ecco la lista delle immagini create da te!                               \n");
	printf("+ seleziona adesso il nome del file da cancellare tra questi qui!          \n");
	printf("+  			                        								  v2.0 \n");
	printf("___________________________________________________________________________\n");
	printf("\n\ttitolo \ttipologia \tnome file\n\n");
}

void ui_menu_modificaImg()
{
	printf("____________________________________________________________________________________________\n");
	printf("+                                            							   					\n");
	printf("+  Ecco la lista delle immagini create da te!											    \n");
	printf("+  seleziona adesso il nome del file da modificare tra questi qui!                          \n");
	printf("+  Ti consentiremo di modificare tutti i dati relativi all'immagine.                        \n");
	printf("+  Qualora tu non volessi modificare un campo, sii tranquillo, clicca invio!                \n");
	printf("+  			                        								             v2.0       \n");
	printf("____________________________________________________________________________________________\n");
	printf("\n\ttitolo \ttipologia \tnome file\n\n");
}

void ui_menu_utente()
{
	printf("_____________________________________________________________\n");
	printf("+                                            				 \n");
	printf("+   Il nostro programma         			                 \n");
	printf("+                                                            \n");
	printf("+   Menu Utente:             	                             \n");
	printf("+   1) Visualizzazione immagini in evidenza                  \n");
	printf("+   2) Ricerca immagine, valutazione e download              \n");
	printf("+   3) le mie azioni	                                     \n");
	printf("+   4) Visualizza statistiche dei creatori                   \n");
	printf("+   5) modifica account                                      \n");
	printf("+   6) cancella account                                      \n");
	printf("+   7) esci                                                  \n");
	printf("+  			                        			 v2.0        \n");
	printf("_____________________________________________________________\n");
}

void ui_menu_imgEv()
{
	printf("________________________________________________________________________\n");
	printf("+                                            				            \n");
	printf("+ Questa sezione consente di visualizzare le immagini in evidenza       \n");
	printf("+ piu scaricate e valutate dagli utenti!                                \n");
	printf("+ Buona navigazione                                                     \n");
	printf("+  			                        			v2.0                    \n");
	printf("________________________________________________________________________\n");
	printf("\n\tTitolo \tValutazione\n");
	printf("\t_______________________________\n");
	printf("                                 \n");
}

void ui_menu_stat()
{
	printf("___________________________________________________________________________________________________________\n");
	printf("+                                            				                                               \n");
	printf("+ Ecco le statistiche dei creatori correnti!                                                               \n");
	printf("+ Questa sezione consente di rappresentare per ogni creatore                                               \n");
	printf("+ il numero di immagini create per ogni tipologia.                                                         \n");
	printf("+ Il primo dato numerico rappresenta il numero di immagini vettoriali inserite, il secondo per le foto e   \n");
	printf("+ il terzo per le icone.                                                                                   \n");
	printf("+  			                        			                                 v2.0                      \n");
	printf("___________________________________________________________________________________________________________\n");
	puts("\n");
	printf("\tCreatori\tI. vettoriali\tI. foto\tI. icona\n");
	printf("\t________________________________________________________\n");
	printf("                                               \n");
}

void ui_menu_azioniUt()
{
	printf("___________________________________________________________________________\n");
	printf("+                                            				               \n");
	printf("+ Ecco le tue azioni recenti!                                              \n");
	printf("+ Questa sezione consente di visualizzare tutte le tue azioni              \n");
	printf("+  			                        			                   v2.0    \n");
	printf("___________________________________________________________________________\n");
	puts("\n");
	printf("\tImmagini scaricate\tvalutazione dell'immagine\n");
	printf("\t________________________________________________\n");
	printf("                                               \n");
}

void ui_menu_reg()
{
	printf("_________________________________________\n");
    printf("+                                        \n");
	printf("+   Il nostro programma         	     \n");
	printf("+                                        \n");
	printf("+   ciao! come desideri registrarti?    \n");
	printf("+   (1) Creatore 		       		     \n");
	printf("+   (2) Semplice utente                  \n");
	printf("+                                        \n");
	printf("+  Spicoli Piersilvio                    \n");
	printf("+  Russo Giulio                          \n");
	printf("+  			                     v2.0    \n");
    printf("_________________________________________\n");
}

void ui_info_reg()
{
	printf("_______________________________________\n");
    printf("+                                      \n");
	printf("+   Inserisci i dati qui sotto!        \n");
	printf("+   non ci vorrà molto...              \n");
	printf("+  			                     v2.0  \n");
	printf("_______________________________________\n");
}

void ui_menu_login()
{
	printf("______________________________________\n");
    printf("+                                     \n");
	printf("+   Il nostro programma         	  \n");
	printf("+                                     \n");
	printf("+   Login:              			  \n");
	printf("+   inseririsci le tue credenziali    \n");
	printf("+                                     \n");
	printf("+  Spicoli Piersilvio                 \n");
	printf("+  Russo Giulio                       \n");
	printf("+									  \n");
	printf("+  			                  v2.0    \n");
	printf("______________________________________\n");
}

void ui_mod_conferma()
{
	printf("____________________________________________________________________\n");
	printf("+                                     								\n");
	printf("+ Modifica adesso le tue credenziali!								\n");
	printf("+ Attenzione però, qualora dovessi modificare le tue credenziali    \n");
	printf("+ tutte le tue info verranno perse. 								\n");
	printf("+ Vuoi procedere? 													\n");
	printf("+ 1) si																\n");
	printf("+ 2) no																\n");
	printf("____________________________________________________________________\n");
}



