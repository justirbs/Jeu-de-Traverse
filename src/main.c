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
  plateau = creerTab2D(10);
  printf("ok création\n");
  initTab(plateau, 10);
  printf("ok initialisation\n");
  afficherTab(plateau, 10);
  joueurJoue(plateau, 10, 1);
  return 0;
}
