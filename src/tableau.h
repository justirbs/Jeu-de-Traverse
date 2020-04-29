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

/*! \struct s_coord
 * Structure qui défini les coordonnées d'un pion selon sa ligne et sa colonne
 */
typedef struct{
	int ligne; /*!< le numéro de ligne du pion */
	int colonne; /*!< le numéro de colonne du pion */
} s_coord;

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
 * \fn s_pion*** creerTab3D(int tour, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief permet de créer un tableau à trois dimensions
 *
 *
 * \param tour le nombre de tour actuel
 * \param n la taille des deux dernières dimensions du tableau
 * \return tab l'adresse de la première case du tableau crée
 *
 */
s_pion*** creerTab3D(int tour, int n);


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


/**
 *\fn char pion(int valeur)
 *
 *\author Justine Ribas <ribasjusti@eisti.eu>
 *\version 0.1
 *\date 27 avril 2020
 *
 *\brief permet de donner le symbole d'un pion selon sa valeur
 *
 *
 *\param valeur la valeur du pion
 *
 */
char pion(int valeur);


/**
 * \fn void enleveCroix(s_pion** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 23 avril 2020
 *
 * \brief permet d'enlever les croix dans le plateau
 *
 *
 * \param tab le plateau de jeu
 * \param n la taille du plateau
 *
 */
void enleveCroix(s_pion** tab, int n);


/**
 * \fn s_pion** copieTab2D(s_pion** tab1, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief permet de copier un tableau en deux dimensions
 *
 *
 * \param tab le tableau à copier
 * \param n la taille du tableau
 * \return la copie du tableau
 *
 */
s_pion** copieTab2D(s_pion** tab1, int n);


/**
 * \fn s_pion*** copieTab3D(s_pion*** tab1, int n, int tour)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 29 avril 2020
 *
 * \brief permet de copier un tableau en trois dimensions
 *
 *
 * \param tab le tableau à copier
 * \param n la taille du tableau
 * \param tour le nombre de tours
 * \return la copie du tableau
 *
 */
s_pion*** copieTab3D(s_pion*** tab1, int n, int tour);


/**
 * \fn s_pion*** agrandiTab(s_pion*** tab1, int tour, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief permet d'agrandir un tableau
 *
 *
 * \param tab le tableau à agrandir
 * \param tour le nombre de tours
 * \param n la taille du tableau
 * \return le tableau agrandi
 *
 */
s_pion*** agrandiTab(s_pion*** tab1, int tour, int n);


/**
 * \fn void freeTab2D(s_pion** tab, int n)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 29 avril 2020
 *
 * \brief permet de free des tableaux à deux dimenssions
 *
 *
 * \param tab le tableau à supprimer
 * \param n la taille du tableau
 * \return le tableau agrandi
 *
 */
void freeTab2D(s_pion** tab, int n);


/**
 * \fn void freeTab3D(s_pion*** tab, int n, int tour)
 *
 * \author Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 29 avril 2020
 *
 * \brief permet de free des tableaux à trois dimenssions
 *
 *
 * \param tab le tableau à supprimer
 * \param n la taille du tableau
 * \param tour le nombre de tours
 * \return le tableau agrandi
 *
 */
void freeTab3D(s_pion*** tab, int n, int tour);

#endif
