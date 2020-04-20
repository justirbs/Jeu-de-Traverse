/*!
 * \file tableau.h
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief header des fonctions relatives tableaux
 *
 *
 */



#ifndef __TABLEAU_H__
#define __TABLEAU_H__

// Inclusion des entêtes de librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * \fn int** creerTabEntier2D(int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief permet de créer un tableau à deux dimensions
 *
 *
 * \param n la taille du tableau
 * \return tab l'adresse de la première case du tableau crée
 *
 */
int** creerTabEntier2D(int n);


/**
 *\fn void initTab(int** tab, int n)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 20 avril 2020
 *
 *\brief permet d'initialiser le plateau de jeu
 *
 *
 *\param tab le plateau de jeu
 *\param n la taille du plateau
 *
 */
void initTab(int** tab, int n);

/**
 *\fn void initLigne(int** tab, int n, int ligne)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 20 avril 2020
 *
 *\brief permet de placer les pions sur la ligne de départ
 *
 *
 *\param tab le plateau de jeu
 *\param n la taille du plateau
 *\param ligne la ligne sur laquelle on place les pions
 *
 */
void initLigne(int** tab, int n, int ligne);

/**
 *\fn void afficherTab(int** tab, int n)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 20 avril 2020
 *
 *\brief permet d'afficher un tableau à une dimension
 *
 *
 *\param tab le tableau à afficher
 *\param n la taille du tableau
 *
 */
void afficherTab(int** tab, int n);


#endif
