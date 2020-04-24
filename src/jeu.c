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
#include "saisie.h"

// Codes des fonctions

void joueurJoue(s_pion** tab, int n, int joueur){
  int ligne; //la ligne du pion à déplacer
  int colonne; //la colonne du pion à déplacer
  do {
    do {
      do {
        printf("Veuillez entrer la case du pion que vous voulez déplacer (ligne puis colonne) : \n");
        ligne = saisirEntier();
        colonne = saisirEntier();
        //la case doit exister sur le plateau
      } while((ligne < 0 || ligne >= n) || (colonne < 0 || colonne >= n));
      //la case doit contenir un pion du joueur
    } while(tab[ligne][colonne].joueur != joueur);
    //le pion doit pouvoir se déplacer
  } while(!deplacement(tab, n, ligne, colonne, joueur));
}


int deplacement(s_pion** tab, int n, int ligne, int colonne, int joueur){
	int estDeplace; //variable booléenne qui indique si le pion est déplacé
	int ligne2;
	int colonne2;
  int estSaut;
  int estSimple;
  int choix;
  int aContinue;
  aContinue = 1;
  estSimple = deplacementsPossiblesSimples(tab, n, ligne, colonne);
  estSaut = deplacementPossiblesSaut(tab, n, ligne, colonne);
	estDeplace = 0;
	if ( estSimple || estSaut) {
    estDeplace = 1;
    afficherTab(tab,n);
		do {
			do {
				printf("Veuillez entrer la ligne puis la colonne de la case où vous voulez déplacer votre pion : \n");
				ligne2 = saisirEntier();
				colonne2 = saisirEntier();
			} while((ligne2 < 0 || ligne2 >= n) || (colonne2 < 0 || colonne2 >= n));
		} while(tab[ligne2][colonne2].valeur != -1);
    tab[ligne2][colonne2].valeur = tab[ligne][colonne].valeur;
    tab[ligne2][colonne2].joueur = joueur;
    tab[ligne][colonne].valeur = 0;
    tab[ligne][colonne].joueur = 0;
    enleveCroix(tab, n);
    if ( abs(ligne2 - ligne) > 1 || abs(colonne2 - colonne) >1){
  		while (deplacementPossiblesSaut(tab, n, ligne2, colonne2)  &&  aContinue == 1){
        ligne = ligne2;
        colonne = colonne2;
        afficherTab(tab, n);
        printf("Vous avez la possibilité d'effectuer des sauts successifs\nSi vous voulez continuer, entrez 1. Sinon, entrez 0.\n");
        do {
          choix = saisirEntier();
        } while (choix != 1 && choix != 0);
        if(choix == 1){
          do {
            do {
              printf("Veuillez entrer la ligne puis la colonne de la case où vous voulez déplacer votre pion : \n");
              ligne2 = saisirEntier();
              colonne2 = saisirEntier();
            } while((ligne2 < 0 || ligne2 >= n) || (colonne2 < 0 || colonne2 >= n));
          } while(tab[ligne2][colonne2].valeur != -1);
          tab[ligne2][colonne2].valeur = tab[ligne][colonne].valeur;
          tab[ligne2][colonne2].joueur = joueur;
          tab[ligne][colonne].valeur = 0;
          tab[ligne][colonne].joueur = 0;
          enleveCroix(tab, n);
        } else aContinue = 0;
      }
  	}
  }
	return(estDeplace);
}


int deplacementsPossiblesSimples(s_pion** tab, int n, int ligne, int colonne){
	int estPossible;
	estPossible = 0;
	switch (tab[ligne][colonne].valeur) {
	case 1 :
		if (deplacementsPossiblesSimplesCarre(tab, n, ligne, colonne)){
			estPossible = 1;
		}
		break;
	case 2 :
		if (deplacementsPossiblesSimplesTriangle(tab, n, ligne, colonne)){
			estPossible = 1;
		}
		break;
	case 3 :
		if (deplacementsPossiblesSimplesLosange(tab, n, ligne, colonne)){
			estPossible = 1;
		}
		break;
	case 4 :
		if (deplacementsPossiblesSimplesCercle(tab, n, ligne, colonne)){
			estPossible = 1;
		}
		break;
	default :
		break;
	}
	return(estPossible);
}


int deplacementPossiblesSaut(s_pion** tab, int n, int ligne, int colonne){
  int estPossible;
	estPossible = 0;
	switch (tab[ligne][colonne].valeur) {
	case 1 :
		if (deplacementsPossiblesSautCarre(tab, n, ligne, colonne)){
			estPossible = 1;
		}
		break;
	case 2 :
		if (deplacementsPossiblesSautTriangle(tab, n, ligne, colonne)){
			estPossible = 1;
		}
		break;
	case 3 :
		if (deplacementsPossiblesSautLosange(tab, n, ligne, colonne)){
			estPossible = 1;
		}
		break;
	case 4 :
		if (deplacementsPossiblesSautCercle(tab, n, ligne, colonne)){
			estPossible = 1;
		}
		break;
	default :
		break;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesCarre(s_pion** tab, int n, int ligne, int colonne){
	int estPossible;
	estPossible = 0;
	//déplacement en haut
	if (ligne > 0  &&  tab[ligne-1][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne-1][colonne].valeur = -1;
	}
	//déplacement en bas
	if (ligne < n-1	 &&  tab[ligne+1][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne+1][colonne].valeur = -1;
	}
	//déplacement à droite
	if (colonne < n-2  &&  tab[ligne][colonne+1].valeur == 0){
		estPossible = 1;
		tab[ligne][colonne+1].valeur = -1;
	}
	//déplacement à gauche
	if (colonne > 1	&&  tab[ligne][colonne-1].valeur == 0){
		estPossible = 1;
		tab[ligne][colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesTriangle(s_pion** tab, int n, int ligne, int colonne){
	int estPossible;
	estPossible = 0;
	//déplacement en bas
	if (ligne < n-1	 &&  tab[ligne+1][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne+1][colonne].valeur = -1;
	}
	//déplacement en haut à droite
	if (ligne > 0  &&  colonne < n-2	 &&  tab[ligne-1][colonne+1].valeur == 0){
		estPossible = 1;
		tab[ligne-1][colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (ligne > 0  &&  colonne > 1 &&  tab[ligne-1][colonne-1].valeur == 0){
		estPossible = 1;
		tab[ligne-1][colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesLosange(s_pion** tab, int n, int ligne, int colonne){
	int estPossible;
	estPossible = 0;
	//déplacement en haut à droite
	if (ligne > 0  &&  colonne < n-2	 &&  tab[ligne-1][colonne+1].valeur == 0){
		estPossible = 1;
		tab[ligne-1][colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (ligne > 0  &&  colonne > 1 &&  tab[ligne-1][colonne-1].valeur == 0){
		estPossible = 1;
		tab[ligne-1][colonne-1].valeur = -1;
	}
	//déplacement en bas à droite
	if (ligne < n-1	 &&  colonne < n-2  &&	tab[ligne+1][colonne+1].valeur == 0){
		estPossible = 1;
		tab[ligne+1][colonne+1].valeur = -1;
	}
	//déplacement en bas à gauche
	if (ligne < n-1	 &&  colonne > 1 &&  tab[ligne+1][colonne-1].valeur == 0){
		estPossible = 1;
		tab[ligne+1][colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesCercle(s_pion** tab, int n, int ligne, int colonne){
	int estPossible;
	estPossible = 0;
	//déplacement en haut
	if (ligne > 0  &&  tab[ligne-1][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne-1][colonne].valeur = -1;
	}
	//déplacement en bas
	if (ligne < n-1	 &&  tab[ligne+1][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne+1][colonne].valeur = -1;
	}
	//déplacement à droite
	if (colonne < n-2  &&  tab[ligne][colonne+1].valeur == 0){
		estPossible = 1;
		tab[ligne][colonne+1].valeur = -1;
	}
	//déplacement à gauche
	if (colonne > 1	&&  tab[ligne][colonne-1].valeur == 0){
		estPossible = 1;
		tab[ligne][colonne-1].valeur = -1;
	}
	//déplacement en haut à droite
	if (ligne > 0  &&  colonne < n-2	 &&  tab[ligne-1][colonne+1].valeur == 0){
		estPossible = 1;
		tab[ligne-1][colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (ligne > 0  &&  colonne > 1 &&  tab[ligne-1][colonne-1].valeur == 0){
		estPossible = 1;
		tab[ligne-1][colonne-1].valeur = -1;
	}
	//déplacement en bas à droite
	if (ligne < n-1	 &&  colonne < n-2  &&	tab[ligne+1][colonne+1].valeur == 0){
		estPossible = 1;
		tab[ligne+1][colonne+1].valeur = -1;
	}
	//déplacement en bas à gauche
	if (ligne < n-1	 &&  colonne > 1 &&  tab[ligne+1][colonne-1].valeur == 0){
		estPossible = 1;
		tab[ligne+1][colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSautCarre(s_pion** tab, int n, int ligne, int colonne){
  int estPossible;
  estPossible = 0;
  //saut en haut
	if (ligne > 1  &&  tab[ligne-1][colonne].valeur != 0 && tab[ligne-1][colonne].valeur != -1 && tab[ligne-2][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne-2][colonne].valeur = -1;
	}
	//saut en bas
	if (ligne < n-2	 &&  tab[ligne+1][colonne].valeur != 0 && tab[ligne+1][colonne].valeur != -1 && tab[ligne+2][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne+2][colonne].valeur = -1;
	}
	//saut à droite
	if (colonne < n-3  &&  tab[ligne][colonne+1].valeur != 0 && tab[ligne][colonne+1].valeur != -1 && tab[ligne][colonne+2].valeur == 0){
		estPossible = 1;
		tab[ligne][colonne+2].valeur = -1;
	}
	//saut à gauche
	if (colonne > 2 &&  tab[ligne][colonne-1].valeur != 0 && tab[ligne][colonne-1].valeur != -1 && tab[ligne][colonne-2].valeur == 0){
		estPossible = 1;
		tab[ligne][colonne-2].valeur = -1;
	}
  return(estPossible);
}


int deplacementsPossiblesSautTriangle(s_pion** tab, int n, int ligne, int colonne){
  int estPossible;
  estPossible = 0;
  //saut en bas
	if (ligne < n-2	 &&  tab[ligne+1][colonne].valeur != 0 && tab[ligne+1][colonne].valeur != -1 && tab[ligne+2][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne+2][colonne].valeur = -1;
	}

	//saut en haut à droite
	if (ligne > 1  &&  colonne < n-3	 &&  tab[ligne-1][colonne+1].valeur != 0	 &&  tab[ligne-1][colonne+1].valeur != -1  &&  tab[ligne-2][colonne+2].valeur == 0){
		estPossible = 1;
		tab[ligne-2][colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (ligne > 1  &&  colonne > 1	&&  tab[ligne-1][colonne-1].valeur != 0	 &&  tab[ligne-1][colonne-1].valeur != -1	&&  tab[ligne-2][colonne-2].valeur == 0){
		estPossible = 1;
		tab[ligne-2][colonne-2].valeur = -1;
	}
  return(estPossible);
}


int deplacementsPossiblesSautLosange(s_pion** tab, int n, int ligne, int colonne){
  int estPossible;
  estPossible = 0;
  //saut en haut à droite
	if (ligne > 1  &&  colonne < n-3	 &&  tab[ligne-1][colonne+1].valeur != 0	 &&  tab[ligne-1][colonne+1].valeur != -1  &&  tab[ligne-2][colonne+2].valeur == 0){
		estPossible = 1;
		tab[ligne-2][colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (ligne > 1  &&  colonne > 1	&&  tab[ligne-1][colonne-1].valeur != 0	 &&  tab[ligne-1][colonne-1].valeur != -1	&&  tab[ligne-2][colonne-2].valeur == 0){
		estPossible = 1;
		tab[ligne-2][colonne-2].valeur = -1;
	}
	//saut en bas à droite
	if (ligne < n-2	 &&  colonne < n-3  &&	tab[ligne+1][colonne+1].valeur != 0  &&	 tab[ligne+1][colonne+1].valeur != -1  &&	tab[ligne+2][colonne+2].valeur == 0){
		estPossible = 1;
		tab[ligne+2][colonne+2].valeur = -1;
	}
	//saut en bas à gauche
	if (ligne < n-2	 &&  colonne > 1	 &&  tab[ligne+1][colonne-1].valeur != 0	 &&  tab[ligne+1][colonne-1].valeur != -1  &&  tab[ligne+2][colonne-2].valeur == 0){
		estPossible = 1;
		tab[ligne+2][colonne-2].valeur = -1;
	}
  return(estPossible);
}


int deplacementsPossiblesSautCercle(s_pion** tab, int n, int ligne, int colonne){
  int estPossible;
  estPossible = 0;
  //saut en haut
	if (ligne > 1  &&  tab[ligne-1][colonne].valeur != 0 && tab[ligne-1][colonne].valeur != -1 && tab[ligne-2][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne-2][colonne].valeur = -1;
	}
	//saut en bas
	if (ligne < n-2	 &&  tab[ligne+1][colonne].valeur != 0 && tab[ligne+1][colonne].valeur != -1 && tab[ligne+2][colonne].valeur == 0){
		estPossible = 1;
		tab[ligne+2][colonne].valeur = -1;
	}
	//saut à droite
	if (colonne < n-3  &&  tab[ligne][colonne+1].valeur != 0 && tab[ligne][colonne+1].valeur != -1 && tab[ligne][colonne+2].valeur == 0){
		estPossible = 1;
		tab[ligne][colonne+2].valeur = -1;
	}
	//saut à gauche
	if (colonne > 2 &&  tab[ligne][colonne-1].valeur != 0 && tab[ligne][colonne-1].valeur != -1 && tab[ligne][colonne-2].valeur == 0){
		estPossible = 1;
		tab[ligne][colonne-2].valeur = -1;
	}
	//saut en haut à droite
	if (ligne > 1  &&  colonne < n-3	 &&  tab[ligne-1][colonne+1].valeur != 0	 &&  tab[ligne-1][colonne+1].valeur != -1  &&  tab[ligne-2][colonne+2].valeur == 0){
		estPossible = 1;
		tab[ligne-2][colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (ligne > 1  &&  colonne > 1	&&  tab[ligne-1][colonne-1].valeur != 0	 &&  tab[ligne-1][colonne-1].valeur != -1	&&  tab[ligne-2][colonne-2].valeur == 0){
		estPossible = 1;
		tab[ligne-2][colonne-2].valeur = -1;
	}
	//saut en bas à droite
	if (ligne < n-2	 &&  colonne < n-3  &&	tab[ligne+1][colonne+1].valeur != 0  &&	 tab[ligne+1][colonne+1].valeur != -1  &&	tab[ligne+2][colonne+2].valeur == 0){
		estPossible = 1;
		tab[ligne+2][colonne+2].valeur = -1;
	}
	//saut en bas à gauche
	if (ligne < n-2	 &&  colonne > 1	 &&  tab[ligne+1][colonne-1].valeur != 0	 &&  tab[ligne+1][colonne-1].valeur != -1  &&  tab[ligne+2][colonne-2].valeur == 0){
		estPossible = 1;
		tab[ligne+2][colonne-2].valeur = -1;
	}
  return(estPossible);
}
