/*!
 * \file jeu.c
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief fonctions relatives au déroulement d'une partie
 *
 *
 */

// Inclusion des librairies
#include "jeu.h"
#include "saisie.h"

// Codes des fonctions

void joueurJoue(s_pion** tab, int n, int joueur){
  int ligne; //la ligne du pion à déplacer
  int colone; //la colonne du pion à déplacer
  do {
    do {
      printf("Veuillez entrer la case du pion que vous voulez déplacer (ligne puis colonne) : \n");
      ligne = saisirEntier();
      colone = saisirEntier();
    } while((ligne < 0 || ligne >= n) || (colone < 0 || colone >= n));
    printf("ok ligne colone\n");
  } while(tab[ligne][colone].joueur != joueur);
  printf("ok\n");
}
