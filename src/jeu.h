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
 * \fn int deplacement(s_pion** tab, int n, int ligne, int colone)
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
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacement(s_pion** tab, int n, int ligne, int colone);

/**
 * \fn int deplacementCarre(s_pion** tab, int n, int ligne, int colone)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion carré
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \return 1 si le déplacement est fait, 0 si il est impossible
 *
 */
int deplacementCarre(s_pion** tab, int n, int ligne, int colone);


/**
 * \fn void deplacementHaut(s_pion** tab, int ligne, int colone, int valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion vers le haut
 *
 *
 * \param tab le plateau de jeu
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param valeur la valeur du pion
 *
 */
void deplacementHaut(s_pion** tab, int ligne, int colone, int valeur);


/**
 * \fn void deplacementBas(s_pion** tab, int ligne, int colone, int valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion vers le bas
 *
 *
 * \param tab le plateau de jeu
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param valeur la valeur du pion
 *
 */
void deplacementBas(s_pion** tab, int ligne, int colone, int valeur);


/**
 * \fn void deplacementDroite(s_pion** tab, int ligne, int colone, int valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion vers la droite
 *
 *
 * \param tab le plateau de jeu
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param valeur la valeur du pion
 *
 */
void deplacementDroite(s_pion** tab, int ligne, int colone, int valeur);


/**
 * \fn void deplacementGauche(s_pion** tab, int ligne, int colone, int valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion vers la gauche
 *
 *
 * \param tab le plateau de jeu
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param valeur la valeur du pion
 *
 */
void deplacementGauche(s_pion** tab, int ligne, int colone, int valeur);

/**
 * \fn void deplacementHautD(s_pion** tab, int ligne, int colone, int valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion vers en haut à droite
 *
 *
 * \param tab le plateau de jeu
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param valeur la valeur du pion
 *
 */
void deplacementHautD(s_pion** tab, int ligne, int colone, int valeur);


/**
 * \fn void deplacementHautG(s_pion** tab, int ligne, int colone, int valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion vers en haut à gauche
 *
 *
 * \param tab le plateau de jeu
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param valeur la valeur du pion
 *
 */
void deplacementHautG(s_pion** tab, int ligne, int colone, int valeur);


/**
 * \fn void deplacementBasD(s_pion** tab, int ligne, int colone, int valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion vers en bas à droite
 *
 *
 * \param tab le plateau de jeu
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param valeur la valeur du pion
 *
 */
void deplacementBasD(s_pion** tab, int ligne, int colone, int valeur);


/**
 * \fn void deplacementBasG(s_pion** tab, int ligne, int colone, int valeur)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet de déplacer un pion vers en bas à gauche
 *
 *
 * \param tab le plateau de jeu
 * \param ligne la ligne de l'emplacement du pion
 * \param colone la colone de l'emplacement du pion
 * \param valeur la valeur du pion
 *
 */
void deplacementBasG(s_pion** tab, int ligne, int colone, int valeur);

#endif
