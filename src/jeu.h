/*!
 * \file jeu.h
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief header des fonctions relatives au déroulement d'une partie de jeu
 *
 *
 */

#ifndef __JEU_H__
#define __JEU_H__

// Inclusion des librairies
#include "tableau.h"

/**
 * \fn void joueurJoue(s_pion** tab, int n, int joueur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief permet de faire jouer le joueur
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param joueur le joueur qui joue
 *
 */
void joueurJoue(s_pion** tab, int n, int joueur);


#endif
