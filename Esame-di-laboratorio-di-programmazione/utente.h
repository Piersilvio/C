/*
 * utente.h
 *
 *  Created on: 14 mag 2021
 *      Author: Pierilvio Spicoli
 *      Author: Giulio Russo
 */

#include "strutture.h"

#ifndef UTENTE_H_
#define UTENTE_H_

//funzioni utente
void utente(char[]);
void img_evidenza(FILE*, char[]);
void stat(FILE*, char[]);
void ricerca_img(FILE*, FILE*, char[]);
void azioni_utente(FILE*, char[]);
void sorting(azioni_ut array[], int size);
void modifica_account_ute(FILE*, char[]);
void cancella_account_ute(FILE*, FILE*, char[]);

#endif /* UTENTE_H_ */

