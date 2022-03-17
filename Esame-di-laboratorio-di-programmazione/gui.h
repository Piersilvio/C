/*
 * gui.h
 *
 *  Created on: 27 mag 2021
 *      Author: Piersilvio Spicoli
 *      Author: Giulio Russo
 */

#ifndef GUI_H_
#define GUI_H_

//funzioni di visualizzazione delle interfaccie grafiche
void ui_menu_main();

//funzioni di visualizzazione delle interfaccie grafiche della sezione creatore
void ui_menu_creatore();
void ui_menu_insImg();
void ui_menu_cancellaImg();
void ui_menu_modificaImg();
void ui_mod_conferma();
void ui_cancella_account();

//funzioni di visualizzazione delle interfaccie grafiche della sezione utente
void ui_menu_utente();
void ui_menu_imgEv();
void ui_menu_stat();
void ui_menu_azioniUt();
void ui_mod_conferma();

//funzioni di visualizzazione delle interfaccie grafiche della sezione reg. e login
void ui_menu_reg();
void ui_info_reg();
void ui_menu_login();


#endif /* GUI_H_ */

