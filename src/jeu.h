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
 * \fn void partieJJ(s_pion** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 24 avril 2020
 *
 * \brief permet de dérouler une partie entre deux joueurs
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 *
 */
void partieJJ(s_pion** tab, int n);


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
 * \fn int deplacement(s_pion** tab, int n, int ligne, int colonne, int joueur)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \param joueur le joueur qui joue
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacement(s_pion** tab, int n, int ligne, int colonne, int joueur);


/**
 * \fn void deplacerPion(s_pion** tab, int ligne1, int colonne1, int joueur, int ligne2, int colonne2)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 24 avril 2020
 *
 * \brief permet de déplacer un pion
 *
 *
 * \param tab le plateau de jeu
 * \param ligne1 la ligne de l'emplacement actuel du pion
 * \param colonne1 la colonne de l'emplacement actuel du pion
 * \param joueur le joueur qui joue
 * \param ligne2 la ligne de l'emplacement futur du pion
 * \param colonne2 la colonne de l'emplacement futur du pion
 *
 */
void deplacerPion(s_pion** tab, int ligne1, int colonne1, int joueur, int ligne2, int colonne2);


/**
 * \fn int deplacementsPossiblesSimples(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimples(s_pion** tab, int n, int ligne, int colonne);


/**
 * \fn int deplacementPossiblesSaut(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementPossiblesSaut(s_pion** tab, int n, int ligne, int colonne);



/**
 * \fn int deplacementsPossiblesSimplesCarre(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimplesCarre(s_pion** tab, int n, int ligne, int colonne);


/**
 * \fn int deplacementsPossiblesSimplesTriangle(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimplesTriangle(s_pion** tab, int n, int ligne, int colonne);


/**
 * \fn int deplacementsPossiblesSimplesLosange(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimplesLosange(s_pion** tab, int n, int ligne, int colonne);


/**
 * \fn int deplacementsPossiblesSimplesCercle(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSimplesCercle(s_pion** tab, int n, int ligne, int colonne);


/**
 * \fn int deplacementsPossiblesSautCarre(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSautCarre(s_pion** tab, int n, int ligne, int colonne);


/**
 * \fn int deplacementsPossiblesSautTriangle(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSautTriangle(s_pion** tab, int n, int ligne, int colonne);


/**
 * \fn int deplacementsPossiblesSautLosange(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSautLosange(s_pion** tab, int n, int ligne, int colonne);


/**
 * \fn int deplacementsPossiblesSautCercle(s_pion** tab, int n, int ligne, int colonne)
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
 * \param ligne la ligne de l'emplacement du pion
 * \param colonne la colonne de l'emplacement du pion
 * \return 1 si le déplacement est possible, 0 si il est impossible
 *
 */
int deplacementsPossiblesSautCercle(s_pion** tab, int n, int ligne, int colonne);


#endif
