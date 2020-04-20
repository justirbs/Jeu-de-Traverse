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

/*! \struct s_pion
 * Structure qui défini les pions par leur valeur et leur appartenance
 */
typedef struct{
	int valeur; /*!< la valeur du pion : rien si case vide, 1 si carré, 2 si triangle, 3 si losange, 4 si rond */
	int joueur; /*!< le joueur à qui appartient le pion : 0 si personne, 1 si joueur1, 2 si joueur2*/
} s_pion;

/**
 * \fn s_pion** creerTab2D(int n)
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
s_pion** creerTab2D(int n);


/**
 *\fn void initTab(s_pion** tab, int n)
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
void initTab(s_pion** tab, int n);

/**
 *\fn void initLigne(s_pion** tab, int n, int ligne, int joueur)
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
 *\param joueur la joueur à qui appartient les pions de cette ligne
 *
 */
void initLigne(s_pion** tab, int n, int ligne, int joueur);

/**
 *\fn void afficherTab(s_pion** tab, int n)
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
void afficherTab(s_pion** tab, int n);


#endif