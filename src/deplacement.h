/*!
 * \file deplacement.h
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief header des fonctions relatives aux déplacements d'un pion
 *
 *
 */

#ifndef __DEPLACEMENT_H__
#define __DEPLACEMENT_H__

// Inclusion des librairies
#include "tableau.h"


/**
 * \fn void deplacerPion(s_pion** tab, s_coord laCase1, int joueur, s_coord laCase2)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 24 avril 2020
 *
 * \brief permet de déplacer un pion
 *
 *
 * \param tab le plateau de jeu
 * \param laCase1 les coordonées actuelles du pion
 * \param joueur le joueur qui joue
 * \param laCase2 les futures coordonées du pion
 *
 */
void deplacerPion(s_pion** tab, s_coord laCase1, int joueur, s_coord laCase2);


/**
 * \fn int deplacementsPossiblesSimples(s_pion** tab, int n, s_coord laCase)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles simples
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimples(s_pion** tab, int n, s_coord laCase);


/**
 * \fn int deplacementPossiblesSaut(s_pion** tab, int n, s_coord laCase)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles avec saut
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementPossiblesSaut(s_pion** tab, int n, s_coord laCase);



/**
 * \fn int deplacementsPossiblesSimplesCarre(s_pion** tab, int n, s_coord laCase)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles simples pour un carré
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimplesCarre(s_pion** tab, int n, s_coord laCase);


/**
 * \fn int deplacementsPossiblesSimplesTriangle(s_pion** tab, int n, s_coord laCase)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles simples pour un triangle
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimplesTriangle(s_pion** tab, int n, s_coord laCase);


/**
 * \fn int deplacementsPossiblesSimplesLosange(s_pion** tab, int n, s_coord laCase)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles simples pour un losange
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimplesLosange(s_pion** tab, int n, s_coord laCase);


/**
 * \fn int deplacementsPossiblesSimplesCercle(s_pion** tab, int n, s_coord laCase)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles simples pour un cercle
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimplesCercle(s_pion** tab, int n, s_coord laCase);


/**
 * \fn int deplacementsPossiblesSautCarre(s_pion** tab, int n, s_coord laCase)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles avec saut pour un carré
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSautCarre(s_pion** tab, int n, s_coord laCase);


/**
 * \fn int deplacementsPossiblesSautTriangle(s_pion** tab, int n, s_coord laCase)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles avec saut pour un triangle
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSautTriangle(s_pion** tab, int n, s_coord laCase);


/**
 * \fn int deplacementsPossiblesSautLosange(s_pion** tab, int n, s_coord laCase)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles avec saut pour un losange
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSautLosange(s_pion** tab, int n, s_coord laCase);


/**
 * \fn int deplacementsPossiblesSautCercle(s_pion** tab, int n, s_coord laCase)
 *
 * \author Vincent Donney <donneyvinc@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de montrer aux joueurs les déplacements possibles avec saut pour un cercle
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param laCase les coordonnées du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSautCercle(s_pion** tab, int n, s_coord laCase);



#endif
