/*!
 * \file jeu.c
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief fonctions relatives au déroulement d'une partie
 *
 *
 */

// Inclusion des librairies
#include "jeu.h"

// Codes des fonctions


void partieJJ(void){
  /*s_pion*** jeu;*/ //l'ensembles des plateaux du jeu
  s_pion** plateau; //le plateau initial
  int tour;
  int n;
  n = 10;
  tour = 0;
  plateau = creerTab2D(n);
  initTab(plateau, n);
  do {
    system("clear");
    afficherTab(plateau,n);
    printf("\nC'est au tour du Joueur 1 (en haut) de jouer :\n\n");
    joueurJoue(plateau, n, 1);
    tour ++;
    if (!aGagne(plateau, n, tour)  &&  !matchNul(jeu, n, tour){
      system("clear");
      afficherTab(plateau,n);
      printf("\nC'est au tour du Joueur 2 (en bas) de jouer :\n\n");
      joueurJoue(plateau, n, 2);
      tour ++;
    }
  } while(aGagne(plateau, n, tour)  ||  matchNul(jeu, n, tour));
  free(plateau);
}


void joueurJoue(s_pion** tab, int n, int joueur){
  s_coord laCase;
  int estPossible; //variable booléenne qui indique si un déplacement est possible
  int aContinue; //variable bouléenne qui indique ou non si le joueur continue de chercher un pion jouable
  aContinue = 1;
  do {
    do {
      do {
        printf("Veuillez entrer la laCase du pion que vous voulez déplacer (laCase.ligne puis laCase.colonne) : \n");
        laCase.ligne = saisirEntier();
        laCase.colonne = saisirEntier();
        //la laCase doit exister sur le plateau
      } while((laCase.ligne < 0 || laCase.ligne >= n) || (laCase.colonne < 0 || laCase.colonne >= n));
      //la laCase doit contenir un pion du joueur
    } while(tab[laCase.ligne][laCase.colonne].joueur != joueur);
    //le pion doit pouvoir se déplacer
    estPossible = tourJoueur(tab, n, laCase, joueur);
    if(estPossible == 0){
      printf("Votre pion ne peut pas être déplacé...\nSi vous voulez en essayer un autre, écrivez 1. Sinon écrivez 0.\n");
      do {
        aContinue = saisirEntier();
      } while (aContinue != 1  &&  aContinue != 0);
    }
  } while(aContinue == 1);
}


int tourJoueur(s_pion** tab, int n, s_coord laCase, int joueur){
	int estDeplace; //variable booléenne qui indique si le pion est déplacé
  s_coord laCase2; //la future laCase du pion si il est déplacé
  int estSaut; //variable booléenne qui indique si un déplacement avec saut est possible
  int estSimple; //variable booléenne qui indique si un déplacement simple est possible
  int choix; //choix de l'utilisateur
  estSimple = deplacementsPossiblesSimples(tab, n, laCase);
  estSaut = deplacementPossiblesSaut(tab, n, laCase);
	estDeplace = 0;
  //on regarde si un déplacement est possible
	if ( estSimple || estSaut) {
    estDeplace = 1;
    system("clear");
    afficherTab(tab,n);
    laCase2 = choixCase(tab, n);
    deplacerPion(tab, laCase, joueur, laCase2);
    enleveCroix(tab, n);
    //dans le cas où le pion vient d'effectuer un déplacement avec saut
    if ( abs(laCase2.ligne - laCase.ligne) > 1 || abs(laCase2.colonne - laCase.colonne) >1){
      estSaut = deplacementPossiblesSaut(tab, n, laCase2);
      choix = 1;
  		while (estSaut &&  choix == 1){
        laCase = laCase2;
        system("clear");
        afficherTab(tab, n);
        //on demande à l'utilisateur quand il veut arrêter ses sauts successifs pour éviter un déplacement à l'infini
        printf("Vous avez la possibilité d'effectuer des sauts successifs\nSi vous voulez continuer, entrez 1. Sinon, entrez 0.\n");
        do {
          choix = saisirEntier();
        } while (choix != 1 && choix != 0);
        if (choix == 1){
          laCase2 = choixCase(tab, n);
          deplacerPion(tab, laCase, joueur, laCase2);
        }
        enleveCroix(tab, n);
        estSaut = deplacementPossiblesSaut(tab, n, laCase2);
      }
      enleveCroix(tab, n);
  	}
  }
	return(estDeplace);
}


s_coord choixCase(s_pion** tab, int n){
  s_coord laCase2; //la future laCase du pion si il est déplacé
  do {
    do {
      printf("Veuillez entrer la ligne puis la colonne de la case où vous voulez déplacer votre pion : \n");
      laCase2.ligne = saisirEntier();
      laCase2.colonne = saisirEntier();
      //la future laCase doit faire partie du plateau
    } while((laCase2.ligne < 0 || laCase2.ligne >= n) || (laCase2.colonne < 0 || laCase2.colonne >= n));
    //la future laCase doit être un déplacement possible
  } while(tab[laCase2.ligne][laCase2.colonne].valeur != -1);
  return(laCase2);
}


int aGagne(s_pion** tab, int n, int tour)
{
	int int_i;
	int gagne1 = 1;
	int gagne2 = 1;
	for (int_i = 0; int_i < n; int_i++)
	{
		if (tab[0][int_i].joueur != 2){
			gagne2 = 0;
		}
		if (tab[n-1][int_i].joueur != 1){
			gagne1 = 0;
		}

	}

	for (int_i = 0; int_i < n; int_i++)
	{
		if (tour>30 && tab[0][int_i].joueur == 1){
			gagne2 = 1;
		}
		if (tour>30 && tab[n-1][int_i].joueur == 2){
			gagne1 = 1;
		}

	}

	if (gagne1 == 1){
		printf("Le joueur 1 a gagné\n");
	}
	if (gagne2 == 1){
		printf("Le joueur 2 a gagné\n");
	}
  return(gagne1 || gagne2);
}


int matchNul(s_pion*** jeu, int n, int tour)
{
	int int_i;
	int int_j;
	int int_k;
	int int_l;
	s_pion **test;
	int identique;
	int plat_identique;
	int matchnul;
	matchnul = 0;
	test = creerTab2D(n);
	for (int_i = 0; int_i < tour; int_i++){
		for (int_j = 0; int_j < n; int_j++){
			for (int_k = 0; int_k < n; int_k++){
				test[int_j][int_k] = jeu[tour][int_j][int_k];
			}
		}
		plat_identique = 0;
		for (int_j = 0; int_j < tour; int_j++){
			identique = 1;
			for (int_k = 0; int_k < n; int_k++){
				for (int_l = 0; int_l < n; int_l++){
					if ( (test[int_k][int_l].valeur != jeu[tour][int_k][int_l].valeur)  || (test[int_k][int_l].joueur != jeu[tour][int_k][int_l].joueur)){
						identique = 0;
					}
				}
			}
			if (identique == 1){
				plat_identique++;
			}
		}
		if(plat_identique > 2){
			matchnul = 1;
		}
	}
	if(matchnul == 1){
		printf("Match nul, c'est la troisième fois que l'on a cette disposition de plateau\n");
	}
  return(matchnul);
}
