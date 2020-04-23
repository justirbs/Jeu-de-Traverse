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

/**
 * \fn int deplacement(s_pion** tab, int n, int ligne, int colone, int joueur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param joueur le joueur qui joue
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacement(s_pion** tab, int n, int ligne, int colone, int joueur);


/**
 * \fn int deplacementsPossibles(s_pion** tab, int n, int ligne, int colone)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacementsPossibles(s_pion** tab, int n, int ligne, int colone);


/**
 * \fn int deplacementsPossiblesCarre(s_pion** tab, int n, int ligne, int colone)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles pour un carré
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacementsPossiblesCarre(s_pion** tab, int n, int ligne, int colone);


/**
 * \fn int deplacementsPossiblesTriangle(s_pion** tab, int n, int ligne, int colone)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles pour un triangle
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacementsPossiblesTriangle(s_pion** tab, int n, int ligne, int colone);


/**
 * \fn int deplacementsPossiblesLosange(s_pion** tab, int n, int ligne, int colone)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles pour un losange
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacementsPossiblesLosange(s_pion** tab, int n, int ligne, int colone);


/**
 * \fn int deplacementsPossiblesCercle(s_pion** tab, int n, int ligne, int colone)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles pour un cercle
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacementsPossiblesCercle(s_pion** tab, int n, int ligne, int colone);



#endif
