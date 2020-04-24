/*!
 * \file main.c
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief fonction princpale
 *
 *
 */

// Inclusion des librairies
#include "tableau.h"
#include "jeu.h"

//Code de la fonction

int main(int argc, char const *argv[]) {
  s_pion** plateau; //plateau de jeu
  int i;
  plateau = creerTab2D(10);
  initTab(plateau, 10);
  for(i=0; i<10; i++){
    partieJJ(plateau, 10);
  }
  free(plateau);
  return 0;
}
