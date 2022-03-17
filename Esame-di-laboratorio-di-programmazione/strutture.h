/*
 * strutture.h
 *
 *  Created on: 14 mag 2021
 *      Author: Pierilvio Spicoli
 *      Author: Giulio Russo
 */

//direttive standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef STRUTTURE_H_
#define STRUTTURE_H_

#define MAX_STRINGA 20 //lunghezza massima delle stringhe - si consideri che l'input di stringhe non accetti spazi!!
#define MAX_CH_PW 10 //lunghezza massima della password

//dichiarazione dei nuovi tipi di funzione
//tabella degli utenti
typedef struct{

	char id[MAX_STRINGA];
	char nome[MAX_STRINGA];
	char cognome[MAX_STRINGA];
	char username[MAX_STRINGA];
	char pw[MAX_CH_PW];
	int n_vettoriale; //++
	int n_foto; //++
	int n_icona; //++

}utenti;

//tabella delle immagini
typedef struct{

	char creatore[MAX_STRINGA];
	char titolo[MAX_STRINGA];
	char tipo[MAX_STRINGA];
	char nome_file[MAX_STRINGA];

}immagine;

//tabella delle azioni
typedef struct{

	utenti username_ut; //sottostruttura che punta alla tabella utenti
	immagine titolo_ut; //sottostruttura che punta alla tabella immagine
	int val; //valore da 1 a 5
	int n_val; //++

}azioni_ut;

//variabili strutturate
utenti ut;
immagine img;
azioni_ut a_t;

//puntatori a file
FILE* user; //puntatore al file utenti
FILE* dati_img; //puntatore al file immagini
FILE* azioni; //puntatore al file statistiche utente

#endif /* STRUTTURE_H_ */

