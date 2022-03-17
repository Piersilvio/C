/*
 * creatore.h
 *
 *  Created on: 14 mag 2021
 *      Author: Pierilvio Spicoli
 *      Author: Giulio Russo
 */

#include "strutture.h"

#ifndef CREATORE_H_
#define CREATORE_H_

//funzioni creatore
void creatore(char[]);
void ins_img(FILE*, FILE*, char[]);
void cancella_img(FILE*, char[]);
void modifica_img(FILE*, char[]);
void aggiornamento_stat(FILE*,  char[], char[]);
void cancella_account(FILE*, FILE*, char[]);
void modifica_account(FILE*, char[]);

#endif /* CREATORE_H_ */
