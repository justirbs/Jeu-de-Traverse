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

//Code de la fonction

int main(int argc, char const *argv[]) {
  int** plateau; //plateau de jeu
  plateau = creerTabEntier2D(10);
  initTab(plateau, 10);
  afficherTab(plateau, 10);
  return 0;
}
