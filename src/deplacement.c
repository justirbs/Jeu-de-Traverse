/*!
 * \file deplacement.c
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 27 avril 2020
 *
 * \brief fonctions relatives aux déplacements d'un pion
 *
 *
 */

// Inclusion des librairies
#include "deplacement.h"


// Codes des fonctions


void deplacerPion(s_pion** tab, s_coord laCase1, int joueur, s_coord laCase2){
  tab[laCase2.ligne][laCase2.colonne].valeur = tab[laCase1.ligne][laCase1.colonne].valeur;
  tab[laCase2.ligne][laCase2.colonne].joueur = joueur;
  tab[laCase1.ligne][laCase1.colonne].valeur = 0;
  tab[laCase1.ligne][laCase1.colonne].joueur = 0;
}


int deplacementsPossiblesSimples(s_pion** tab, int n, s_coord laCase){
	int estPossible;
	estPossible = 0;
	switch (tab[laCase.ligne][laCase.colonne].valeur) {
	case 1 :
		if (deplacementsPossiblesSimplesCarre(tab, n, laCase)){
			estPossible = 1;
		}
		break;
	case 2 :
		if (deplacementsPossiblesSimplesTriangle(tab, n, laCase)){
			estPossible = 1;
		}
		break;
	case 3 :
		if (deplacementsPossiblesSimplesLosange(tab, n, laCase)){
			estPossible = 1;
		}
		break;
	case 4 :
		if (deplacementsPossiblesSimplesCercle(tab, n, laCase)){
			estPossible = 1;
		}
		break;
	default :
		break;
	}
	return(estPossible);
}


int deplacementPossiblesSaut(s_pion** tab, int n, s_coord laCase){
  int estPossible;
	estPossible = 0;
	switch (tab[laCase.ligne][laCase.colonne].valeur) {
	case 1 :
		if (deplacementsPossiblesSautCarre(tab, n, laCase)){
			estPossible = 1;
		}
		break;
	case 2 :
		if (deplacementsPossiblesSautTriangle(tab, n, laCase)){
			estPossible = 1;
		}
		break;
	case 3 :
		if (deplacementsPossiblesSautLosange(tab, n, laCase)){
			estPossible = 1;
		}
		break;
	case 4 :
		if (deplacementsPossiblesSautCercle(tab, n, laCase)){
			estPossible = 1;
		}
		break;
	default :
		break;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesCarre(s_pion** tab, int n, s_coord laCase){
	int estPossible;
	estPossible = 0;
	//déplacement en haut
	if (laCase.ligne > 0  &&  tab[laCase.ligne-1][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-1][laCase.colonne].valeur = -1;
	}
	//déplacement en bas
	if (laCase.ligne < n-1	 &&  tab[laCase.ligne+1][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+1][laCase.colonne].valeur = -1;
	}
	//déplacement à droite
	if (laCase.colonne < n-2  &&  tab[laCase.ligne][laCase.colonne+1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne][laCase.colonne+1].valeur = -1;
	}
	//déplacement à gauche
	if (laCase.colonne > 1	&&  tab[laCase.ligne][laCase.colonne-1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne][laCase.colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesTriangle(s_pion** tab, int n, s_coord laCase){
	int estPossible;
	estPossible = 0;
	//déplacement en bas
	if (laCase.ligne < n-1	 &&  tab[laCase.ligne+1][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+1][laCase.colonne].valeur = -1;
	}
	//déplacement en haut à droite
	if (laCase.ligne > 0  &&  laCase.colonne < n-2	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-1][laCase.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (laCase.ligne > 0  &&  laCase.colonne > 1 &&  tab[laCase.ligne-1][laCase.colonne-1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-1][laCase.colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesLosange(s_pion** tab, int n, s_coord laCase){
	int estPossible;
	estPossible = 0;
	//déplacement en haut à droite
	if (laCase.ligne > 0  &&  laCase.colonne < n-2	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-1][laCase.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (laCase.ligne > 0  &&  laCase.colonne > 1 &&  tab[laCase.ligne-1][laCase.colonne-1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-1][laCase.colonne-1].valeur = -1;
	}
	//déplacement en bas à droite
	if (laCase.ligne < n-1	 &&  laCase.colonne < n-2  &&	tab[laCase.ligne+1][laCase.colonne+1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+1][laCase.colonne+1].valeur = -1;
	}
	//déplacement en bas à gauche
	if (laCase.ligne < n-1	 &&  laCase.colonne > 1 &&  tab[laCase.ligne+1][laCase.colonne-1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+1][laCase.colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesCercle(s_pion** tab, int n, s_coord laCase){
	int estPossible;
	estPossible = 0;
	//déplacement en haut
	if (laCase.ligne > 0  &&  tab[laCase.ligne-1][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-1][laCase.colonne].valeur = -1;
	}
	//déplacement en bas
	if (laCase.ligne < n-1	 &&  tab[laCase.ligne+1][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+1][laCase.colonne].valeur = -1;
	}
	//déplacement à droite
	if (laCase.colonne < n-2  &&  tab[laCase.ligne][laCase.colonne+1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne][laCase.colonne+1].valeur = -1;
	}
	//déplacement à gauche
	if (laCase.colonne > 1	&&  tab[laCase.ligne][laCase.colonne-1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne][laCase.colonne-1].valeur = -1;
	}
	//déplacement en haut à droite
	if (laCase.ligne > 0  &&  laCase.colonne < n-2	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-1][laCase.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (laCase.ligne > 0  &&  laCase.colonne > 1 &&  tab[laCase.ligne-1][laCase.colonne-1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-1][laCase.colonne-1].valeur = -1;
	}
	//déplacement en bas à droite
	if (laCase.ligne < n-1	 &&  laCase.colonne < n-2  &&	tab[laCase.ligne+1][laCase.colonne+1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+1][laCase.colonne+1].valeur = -1;
	}
	//déplacement en bas à gauche
	if (laCase.ligne < n-1	 &&  laCase.colonne > 1 &&  tab[laCase.ligne+1][laCase.colonne-1].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+1][laCase.colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSautCarre(s_pion** tab, int n, s_coord laCase){
  int estPossible;
  estPossible = 0;
  //saut en haut
	if (laCase.ligne > 1  &&  tab[laCase.ligne-1][laCase.colonne].valeur != 0 && tab[laCase.ligne-1][laCase.colonne].valeur != -1 && tab[laCase.ligne-2][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne].valeur = -1;
	}
	//saut en bas
	if (laCase.ligne < n-2	 &&  tab[laCase.ligne+1][laCase.colonne].valeur != 0 && tab[laCase.ligne+1][laCase.colonne].valeur != -1 && tab[laCase.ligne+2][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne].valeur = -1;
	}
	//saut à droite
	if (laCase.colonne < n-3  &&  tab[laCase.ligne][laCase.colonne+1].valeur != 0 && tab[laCase.ligne][laCase.colonne+1].valeur != -1 && tab[laCase.ligne][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne][laCase.colonne+2].valeur = -1;
	}
	//saut à gauche
	if (laCase.colonne > 2 &&  tab[laCase.ligne][laCase.colonne-1].valeur != 0 && tab[laCase.ligne][laCase.colonne-1].valeur != -1 && tab[laCase.ligne][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne][laCase.colonne-2].valeur = -1;
	}
  return(estPossible);
}


int deplacementsPossiblesSautTriangle(s_pion** tab, int n, s_coord laCase){
  int estPossible;
  estPossible = 0;
  //saut en bas
	if (laCase.ligne < n-2	 &&  tab[laCase.ligne+1][laCase.colonne].valeur != 0 && tab[laCase.ligne+1][laCase.colonne].valeur != -1 && tab[laCase.ligne+2][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne].valeur = -1;
	}
	//saut en haut à droite
	if (laCase.ligne > 1  &&  laCase.colonne < n-3	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur != 0	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur != -1  &&  tab[laCase.ligne-2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (laCase.ligne > 1  &&  laCase.colonne > 1	&&  tab[laCase.ligne-1][laCase.colonne-1].valeur != 0	 &&  tab[laCase.ligne-1][laCase.colonne-1].valeur != -1	&&  tab[laCase.ligne-2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (laCase.ligne > 1  &&  laCase.ligne == n-2  &&  tab[laCase.ligne-1][laCase.ligne+1].valeur != 0  &&	tab[laCase.ligne-1][laCase.ligne+1].valeur != -1  && tab[laCase.ligne-2][laCase.ligne+1].valeur != 0 && tab[laCase.ligne-2][laCase.ligne+1].valeur != -1  &&  tab[laCase.ligne-2][laCase.ligne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.ligne+2].valeur = -1;
	}
	//saut en haut à gauche vers la colonne extérieure gauche
	if (laCase.ligne > 1  &&  laCase.ligne == 1	 &&  tab[laCase.ligne-1][laCase.ligne-1].valeur != 0  &&  tab[laCase.ligne-1][laCase.ligne-1].valeur != -1  &&	tab[laCase.ligne-1][laCase.ligne-2].valeur != 0  &&	 tab[laCase.ligne-1][laCase.ligne-2].valeur != -1  &&  tab[laCase.ligne-2][laCase.ligne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne-2].valeur = -1;
	}
  return(estPossible);
}


int deplacementsPossiblesSautLosange(s_pion** tab, int n, s_coord laCase){
  int estPossible;
  estPossible = 0;
  //saut en haut à droite
	if (laCase.ligne > 1  &&  laCase.colonne < n-3	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur != 0	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur != -1  &&  tab[laCase.ligne-2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (laCase.ligne > 1  &&  laCase.colonne > 1	&&  tab[laCase.ligne-1][laCase.colonne-1].valeur != 0	 &&  tab[laCase.ligne-1][laCase.colonne-1].valeur != -1	&&  tab[laCase.ligne-2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne-2].valeur = -1;
	}
	//saut en bas à droite
	if (laCase.ligne < n-2	 &&  laCase.colonne < n-3  &&	tab[laCase.ligne+1][laCase.colonne+1].valeur != 0  &&	 tab[laCase.ligne+1][laCase.colonne+1].valeur != -1  &&	tab[laCase.ligne+2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne+2].valeur = -1;
	}
	//saut en bas à gauche
	if (laCase.ligne < n-2	 &&  laCase.colonne > 1	 &&  tab[laCase.ligne+1][laCase.colonne-1].valeur != 0	 &&  tab[laCase.ligne+1][laCase.colonne-1].valeur != -1  &&  tab[laCase.ligne+2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (laCase.ligne > 1  &&  laCase.colonne == n-2  &&  tab[laCase.ligne-1][laCase.colonne+1].valeur != 0  &&	tab[laCase.ligne-1][laCase.colonne+1].valeur != -1  &&  tab[laCase.ligne-2][laCase.colonne+1].valeur  !=0  &&  tab[laCase.ligne-2][laCase.colonne+1].valeur != -1	&&  tab[laCase.ligne-2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne+2].valeur = -1;
	}
  //saut en haut à gauche vers la colonne extérieure gauche
	if (laCase.ligne > 1  &&  laCase.colonne == 1	 &&  tab[laCase.ligne-1][laCase.colonne-1].valeur != 0  &&  tab[laCase.ligne-1][laCase.colonne-1].valeur != -1  &&	tab[laCase.ligne-1][laCase.colonne-2].valeur != 0  &&	 tab[laCase.ligne-1][laCase.colonne-2].valeur != -1  &&  tab[laCase.ligne-2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne-2].valeur = -1;
	}
  //saut en bas à droite vers la colonne extérieure droite
	if (laCase.ligne < n-2	 &&  laCase.colonne == n-2  &&	 tab[laCase.ligne+1][laCase.colonne+1].valeur != 0  &&  tab[laCase.ligne+1][laCase.colonne+1].valeur != -1	&& tab[laCase.ligne+2][laCase.colonne+1].valeur  != 0	&&  tab[laCase.ligne+2][laCase.colonne+1].valeur  != -1  &&  tab[laCase.ligne+2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne+2].valeur = -1;
	}
  //saut en bas à gauche vers la colonne extérieure gauche
	if (laCase.ligne < n-2	 &&  laCase.colonne == 1  &&  tab[laCase.ligne+1][laCase.colonne-1].valeur != 0  &&	tab[laCase.ligne+1][laCase.colonne-1].valeur != -1  &&  tab[laCase.ligne+1][laCase.colonne-2].valeur != 0	 &&  tab[laCase.ligne+1][laCase.colonne-2].valeur != -1  &&  tab[laCase.ligne+2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne-2].valeur = -1;
	}
  return(estPossible);
}


int deplacementsPossiblesSautCercle(s_pion** tab, int n, s_coord laCase){
  int estPossible;
  estPossible = 0;
  //saut en haut
	if (laCase.ligne > 1  &&  tab[laCase.ligne-1][laCase.colonne].valeur != 0 && tab[laCase.ligne-1][laCase.colonne].valeur != -1 && tab[laCase.ligne-2][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne].valeur = -1;
	}
	//saut en bas
	if (laCase.ligne < n-2	 &&  tab[laCase.ligne+1][laCase.colonne].valeur != 0 && tab[laCase.ligne+1][laCase.colonne].valeur != -1 && tab[laCase.ligne+2][laCase.colonne].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne].valeur = -1;
	}
	//saut à droite
	if (laCase.colonne < n-3  &&  tab[laCase.ligne][laCase.colonne+1].valeur != 0 && tab[laCase.ligne][laCase.colonne+1].valeur != -1 && tab[laCase.ligne][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne][laCase.colonne+2].valeur = -1;
	}
	//saut à gauche
	if (laCase.colonne > 2 &&  tab[laCase.ligne][laCase.colonne-1].valeur != 0 && tab[laCase.ligne][laCase.colonne-1].valeur != -1 && tab[laCase.ligne][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne][laCase.colonne-2].valeur = -1;
	}
	//saut en haut à droite
	if (laCase.ligne > 1  &&  laCase.colonne < n-3	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur != 0	 &&  tab[laCase.ligne-1][laCase.colonne+1].valeur != -1  &&  tab[laCase.ligne-2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (laCase.ligne > 1  &&  laCase.colonne > 1	&&  tab[laCase.ligne-1][laCase.colonne-1].valeur != 0	 &&  tab[laCase.ligne-1][laCase.colonne-1].valeur != -1	&&  tab[laCase.ligne-2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne-2].valeur = -1;
	}
	//saut en bas à droite
	if (laCase.ligne < n-2	 &&  laCase.colonne < n-3  &&	tab[laCase.ligne+1][laCase.colonne+1].valeur != 0  &&	 tab[laCase.ligne+1][laCase.colonne+1].valeur != -1  &&	tab[laCase.ligne+2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne+2].valeur = -1;
	}
	//saut en bas à gauche
	if (laCase.ligne < n-2	 &&  laCase.colonne > 1	 &&  tab[laCase.ligne+1][laCase.colonne-1].valeur != 0	 &&  tab[laCase.ligne+1][laCase.colonne-1].valeur != -1  &&  tab[laCase.ligne+2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (laCase.ligne > 1  &&  laCase.colonne == n-2  &&  tab[laCase.ligne-1][laCase.colonne+1].valeur != 0  &&	tab[laCase.ligne-1][laCase.colonne+1].valeur != -1  &&  tab[laCase.ligne-2][laCase.colonne+1].valeur  !=0  &&  tab[laCase.ligne-2][laCase.colonne+1].valeur != -1	&&  tab[laCase.ligne-2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne+2].valeur = -1;
	}
  //saut en haut à gauche vers la colonne extérieure gauche
	if (laCase.ligne > 1  &&  laCase.colonne == 1	 &&  tab[laCase.ligne-1][laCase.colonne-1].valeur != 0  &&  tab[laCase.ligne-1][laCase.colonne-1].valeur != -1  &&	tab[laCase.ligne-1][laCase.colonne-2].valeur != 0  &&	 tab[laCase.ligne-1][laCase.colonne-2].valeur != -1  &&  tab[laCase.ligne-2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne-2][laCase.colonne-2].valeur = -1;
	}
  //saut en bas à droite vers la colonne extérieure droite
	if (laCase.ligne < n-2	 &&  laCase.colonne == n-2  &&	 tab[laCase.ligne+1][laCase.colonne+1].valeur != 0  &&  tab[laCase.ligne+1][laCase.colonne+1].valeur != -1	&& tab[laCase.ligne+2][laCase.colonne+1].valeur  != 0	&&  tab[laCase.ligne+2][laCase.colonne+1].valeur  != -1  &&  tab[laCase.ligne+2][laCase.colonne+2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne+2].valeur = -1;
	}
  //saut en bas à gauche vers la colonne extérieure gauche
	if (laCase.ligne < n-2	 &&  laCase.colonne == 1  &&  tab[laCase.ligne+1][laCase.colonne-1].valeur != 0  &&	tab[laCase.ligne+1][laCase.colonne-1].valeur != -1  &&  tab[laCase.ligne+1][laCase.colonne-2].valeur != 0	 &&  tab[laCase.ligne+1][laCase.colonne-2].valeur != -1  &&  tab[laCase.ligne+2][laCase.colonne-2].valeur == 0){
		estPossible = 1;
		tab[laCase.ligne+2][laCase.colonne-2].valeur = -1;
	}
  return(estPossible);
}
