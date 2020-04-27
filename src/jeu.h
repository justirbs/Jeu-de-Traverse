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
#include "saisie.h"
#include "deplacement.h"


/**
 * \fn void partieJJ(void)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 24 avril 2020
 *
 * \brief permet de dérouler une partie entre deux joueurs
 *
 *
 */
void partieJJ(void);


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


/**
 * \fn s_coord choixCase(s_pion** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief permet de choisir une case dans laquelle déplacer son pion
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \return les coordonées de la nouvelle case
 *
 */
s_coord choixCase(s_pion** tab, int n);


/**
 * \fn int tourJoueur(s_pion** tab, int n, s_coord laCase, int joueur)
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de gérer les déplacements possibles d'un pion
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées de la laCase choisie
 * \param joueur le joueur qui joue
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int tourJoueur(s_pion** tab, int n, s_coord laCase, int joueur);


/**
 * \fn int aGagne(s_pion** tab, int n, int tour)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 26 avril 2020
 *
 * \brief permet de vérifier si un joueur a gagné
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param tour le numéro du tour en cours
 * \return 1 si un joueur a gagné, 0 sinon
 *
 */
int aGagne(s_pion **tab, int n, int tour);


/**
 * \fn int matchNul(s_pion*** jeu, int n, int tour)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 26 avril 2020
 *
 * \brief permet de vérifier si il y a match nul
 *
 *
 * \param jeu l'ensemble des plateaux de jeu depuis le début de la partie
 * \param n la taille du plateau
 * \param tour le numéro du tour en cours
 * \return 1 si il y a match nul, 0 sinon
 *
 */
int matchNul(s_pion*** jeu, int n, int tour);


#endif
