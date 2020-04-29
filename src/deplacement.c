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


void deplacerPion(s_pion** tab, s_coord pion1, int joueur, s_coord pion2){
  tab[pion2.ligne][pion2.colonne].valeur = tab[pion1.ligne][pion1.colonne].valeur;
  tab[pion2.ligne][pion2.colonne].joueur = joueur;
  tab[pion1.ligne][pion1.colonne].valeur = 0;
  tab[pion1.ligne][pion1.colonne].joueur = 0;
}


int deplacementsPossibles(s_pion** tab, int n, s_coord pion){
  int estPossible;
  int estSaut; //variable booléenne qui indique si un déplacement avec saut est possible
  int estSimple; //variable booléenne qui indique si un déplacement simple est possible
  estSaut = deplacementPossiblesSaut(tab, n, pion);
  estSimple = deplacementsPossiblesSimples(tab, n, pion);
  if(estSaut ||  estSimple){
    estPossible = 1;
  } else {
    estPossible = 0;
  }
  return(estPossible);
}


int deplacementsPossiblesSimples(s_pion** tab, int n, s_coord pion){
	int estPossible;
	estPossible = 0;
	switch (tab[pion.ligne][pion.colonne].valeur) {
	case 1 :
		if (deplacementsPossiblesSimplesCarre(tab, n, pion)){
			estPossible = 1;
		}
		break;
	case 2 :
		if (deplacementsPossiblesSimplesTriangle(tab, n, pion)){
			estPossible = 1;
		}
		break;
	case 3 :
		if (deplacementsPossiblesSimplesLosange(tab, n, pion)){
			estPossible = 1;
		}
		break;
	case 4 :
		if (deplacementsPossiblesSimplesCercle(tab, n, pion)){
			estPossible = 1;
		}
		break;
	default :
		break;
	}
	return(estPossible);
}


int deplacementPossiblesSaut(s_pion** tab, int n, s_coord pion){
  int estPossible;
	estPossible = 0;
	switch (tab[pion.ligne][pion.colonne].valeur) {
	case 1 :
		if (deplacementsPossiblesSautCarre(tab, n, pion)){
			estPossible = 1;
		}
		break;
	case 2 :
		if (deplacementsPossiblesSautTriangle(tab, n, pion)){
			estPossible = 1;
		}
		break;
	case 3 :
		if (deplacementsPossiblesSautLosange(tab, n, pion)){
			estPossible = 1;
		}
		break;
	case 4 :
		if (deplacementsPossiblesSautCercle(tab, n, pion)){
			estPossible = 1;
		}
		break;
	default :
		break;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesCarre(s_pion** tab, int n, s_coord pion){
	int estPossible;
	estPossible = 0;
	//déplacement en haut
	if (pion.ligne > 0  &&  tab[pion.ligne-1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne].valeur = -1;
	}
	//déplacement en bas
	if (pion.ligne < n-1	 &&  tab[pion.ligne+1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne].valeur = -1;
	}
	//déplacement à droite
	if (pion.colonne < n-2  &&  tab[pion.ligne][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne+1].valeur = -1;
	}
	//déplacement à gauche
	if (pion.colonne > 1	&&  tab[pion.ligne][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesTriangle(s_pion** tab, int n, s_coord pion){
	int estPossible;
	estPossible = 0;
	//déplacement en bas
	if (pion.ligne < n-1	 &&  tab[pion.ligne+1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne].valeur = -1;
	}
	//déplacement en haut à droite
	if (pion.ligne > 0  &&  pion.colonne < n-2	 &&  tab[pion.ligne-1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (pion.ligne > 0  &&  pion.colonne > 1 &&  tab[pion.ligne-1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesLosange(s_pion** tab, int n, s_coord pion){
	int estPossible;
	estPossible = 0;
	//déplacement en haut à droite
	if (pion.ligne > 0  &&  pion.colonne < n-2	 &&  tab[pion.ligne-1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (pion.ligne > 0  &&  pion.colonne > 1 &&  tab[pion.ligne-1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne-1].valeur = -1;
	}
	//déplacement en bas à droite
	if (pion.ligne < n-1	 &&  pion.colonne < n-2  &&	tab[pion.ligne+1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne+1].valeur = -1;
	}
	//déplacement en bas à gauche
	if (pion.ligne < n-1	 &&  pion.colonne > 1 &&  tab[pion.ligne+1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSimplesCercle(s_pion** tab, int n, s_coord pion){
	int estPossible;
	estPossible = 0;
	//déplacement en haut
	if (pion.ligne > 0  &&  tab[pion.ligne-1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne].valeur = -1;
	}
	//déplacement en bas
	if (pion.ligne < n-1	 &&  tab[pion.ligne+1][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne].valeur = -1;
	}
	//déplacement à droite
	if (pion.colonne < n-2  &&  tab[pion.ligne][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne+1].valeur = -1;
	}
	//déplacement à gauche
	if (pion.colonne > 1	&&  tab[pion.ligne][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne-1].valeur = -1;
	}
	//déplacement en haut à droite
	if (pion.ligne > 0  &&  pion.colonne < n-2	 &&  tab[pion.ligne-1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne+1].valeur = -1;
	}
	//déplacement en haut à gauche
	if (pion.ligne > 0  &&  pion.colonne > 1 &&  tab[pion.ligne-1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-1][pion.colonne-1].valeur = -1;
	}
	//déplacement en bas à droite
	if (pion.ligne < n-1	 &&  pion.colonne < n-2  &&	tab[pion.ligne+1][pion.colonne+1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne+1].valeur = -1;
	}
	//déplacement en bas à gauche
	if (pion.ligne < n-1	 &&  pion.colonne > 1 &&  tab[pion.ligne+1][pion.colonne-1].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+1][pion.colonne-1].valeur = -1;
	}
	return(estPossible);
}


int deplacementsPossiblesSautCarre(s_pion** tab, int n, s_coord pion){
  int estPossible;
  int i;
  int j;
  s_coord pion2;
  estPossible = 0;
  //saut en haut
	if (pion.ligne > 1  &&  tab[pion.ligne-1][pion.colonne].valeur != 0 && tab[pion.ligne-1][pion.colonne].valeur != -1 && tab[pion.ligne-2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne].valeur = -1;
	}
	//saut en bas
	if (pion.ligne < n-2	 &&  tab[pion.ligne+1][pion.colonne].valeur != 0 && tab[pion.ligne+1][pion.colonne].valeur != -1 && tab[pion.ligne+2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne].valeur = -1;
	}
	//saut à droite
	if (pion.colonne < n-3  &&  tab[pion.ligne][pion.colonne+1].valeur != 0 && tab[pion.ligne][pion.colonne+1].valeur != -1 && tab[pion.ligne][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne+2].valeur = -1;
	}
	//saut à gauche
	if (pion.colonne > 2 &&  tab[pion.ligne][pion.colonne-1].valeur != 0 && tab[pion.ligne][pion.colonne-1].valeur != -1 && tab[pion.ligne][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne-2].valeur = -1;
	}
  if(estPossible == 1){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if(tab[i][j].valeur == -1){
          pion2.ligne = i;
          pion2.colonne = j;
          estPossible = deplacementsPossiblesSautCarre(tab, n, pion2);
        }
      }
    }
  }
  return(estPossible);
}


int deplacementsPossiblesSautTriangle(s_pion** tab, int n, s_coord pion){
  int estPossible;
  int i;
  int j;
  s_coord pion2;
  estPossible = 0;
  //saut en bas
	if (pion.ligne < n-2	 &&  tab[pion.ligne+1][pion.colonne].valeur != 0 && tab[pion.ligne+1][pion.colonne].valeur != -1 && tab[pion.ligne+2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne].valeur = -1;
	}
	//saut en haut à droite
	if (pion.ligne > 1  &&  pion.colonne < n-3	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (pion.ligne > 1  &&  pion.colonne > 1	&&  tab[pion.ligne-1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (pion.ligne > 1  &&  pion.colonne == n-2  &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0  &&	tab[pion.ligne-1][pion.colonne+1].valeur != -1  && tab[pion.ligne-2][pion.colonne+1].valeur != 0 && tab[pion.ligne-2][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.ligne+2].valeur = -1;
	}
	//saut en haut à gauche vers la colonne extérieure gauche
	if (pion.ligne > 1  &&  pion.colonne == 1	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != 0  &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1  &&	tab[pion.ligne-1][pion.colonne-2].valeur != 0  &&	 tab[pion.ligne-1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
  if(estPossible == 1){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if(tab[i][j].valeur == -1){
          pion2.ligne = i;
          pion2.colonne = j;
          estPossible = deplacementsPossiblesSautTriangle(tab, n, pion2);
        }
      }
    }
  }
  return(estPossible);
}


int deplacementsPossiblesSautLosange(s_pion** tab, int n, s_coord pion){
  int estPossible;
  int i;
  int j;
  s_coord pion2;
  estPossible = 0;
  //saut en haut à droite
	if (pion.ligne > 1  &&  pion.colonne < n-3	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (pion.ligne > 1  &&  pion.colonne > 1	&&  tab[pion.ligne-1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
	//saut en bas à droite
	if (pion.ligne < n-2	 &&  pion.colonne < n-3  &&	tab[pion.ligne+1][pion.colonne+1].valeur != 0  &&	 tab[pion.ligne+1][pion.colonne+1].valeur != -1  &&	tab[pion.ligne+2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne+2].valeur = -1;
	}
	//saut en bas à gauche
	if (pion.ligne < n-2	 &&  pion.colonne > 1	 &&  tab[pion.ligne+1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne+1][pion.colonne-1].valeur != -1  &&  tab[pion.ligne+2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (pion.ligne > 1  &&  pion.colonne == n-2  &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0  &&	tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+1].valeur  !=0  &&  tab[pion.ligne-2][pion.colonne+1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
  //saut en haut à gauche vers la colonne extérieure gauche
	if (pion.ligne > 1  &&  pion.colonne == 1	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != 0  &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1  &&	tab[pion.ligne-1][pion.colonne-2].valeur != 0  &&	 tab[pion.ligne-1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
  //saut en bas à droite vers la colonne extérieure droite
	if (pion.ligne < n-2	 &&  pion.colonne == n-2  &&	 tab[pion.ligne+1][pion.colonne+1].valeur != 0  &&  tab[pion.ligne+1][pion.colonne+1].valeur != -1	&& tab[pion.ligne+2][pion.colonne+1].valeur  != 0	&&  tab[pion.ligne+2][pion.colonne+1].valeur  != -1  &&  tab[pion.ligne+2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne+2].valeur = -1;
	}
  //saut en bas à gauche vers la colonne extérieure gauche
	if (pion.ligne < n-2	 &&  pion.colonne == 1  &&  tab[pion.ligne+1][pion.colonne-1].valeur != 0  &&	tab[pion.ligne+1][pion.colonne-1].valeur != -1  &&  tab[pion.ligne+1][pion.colonne-2].valeur != 0	 &&  tab[pion.ligne+1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne+2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne-2].valeur = -1;
	}
  if(estPossible == 1){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if(tab[i][j].valeur == -1){
          pion2.ligne = i;
          pion2.colonne = j;
          estPossible = deplacementsPossiblesSautLosange(tab, n, pion2);
        }
      }
    }
  }
  return(estPossible);
}


int deplacementsPossiblesSautCercle(s_pion** tab, int n, s_coord pion){
  int estPossible;
  int i;
  int j;
  s_coord pion2;
  estPossible = 0;
  //saut en haut
	if (pion.ligne > 1  &&  tab[pion.ligne-1][pion.colonne].valeur != 0 && tab[pion.ligne-1][pion.colonne].valeur != -1 && tab[pion.ligne-2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne].valeur = -1;
	}
	//saut en bas
	if (pion.ligne < n-2	 &&  tab[pion.ligne+1][pion.colonne].valeur != 0 && tab[pion.ligne+1][pion.colonne].valeur != -1 && tab[pion.ligne+2][pion.colonne].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne].valeur = -1;
	}
	//saut à droite
	if (pion.colonne < n-3  &&  tab[pion.ligne][pion.colonne+1].valeur != 0 && tab[pion.ligne][pion.colonne+1].valeur != -1 && tab[pion.ligne][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne+2].valeur = -1;
	}
	//saut à gauche
	if (pion.colonne > 2 &&  tab[pion.ligne][pion.colonne-1].valeur != 0 && tab[pion.ligne][pion.colonne-1].valeur != -1 && tab[pion.ligne][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne][pion.colonne-2].valeur = -1;
	}
	//saut en haut à droite
	if (pion.ligne > 1  &&  pion.colonne < n-3	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
	//saut en haut à gauche
	if (pion.ligne > 1  &&  pion.colonne > 1	&&  tab[pion.ligne-1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
	//saut en bas à droite
	if (pion.ligne < n-2	 &&  pion.colonne < n-3  &&	tab[pion.ligne+1][pion.colonne+1].valeur != 0  &&	 tab[pion.ligne+1][pion.colonne+1].valeur != -1  &&	tab[pion.ligne+2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne+2].valeur = -1;
	}
	//saut en bas à gauche
	if (pion.ligne < n-2	 &&  pion.colonne > 1	 &&  tab[pion.ligne+1][pion.colonne-1].valeur != 0	 &&  tab[pion.ligne+1][pion.colonne-1].valeur != -1  &&  tab[pion.ligne+2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne-2].valeur = -1;
	}
  //saut en haut à droite vers la colonne extérieure droite
	if (pion.ligne > 1  &&  pion.colonne == n-2  &&  tab[pion.ligne-1][pion.colonne+1].valeur != 0  &&	tab[pion.ligne-1][pion.colonne+1].valeur != -1  &&  tab[pion.ligne-2][pion.colonne+1].valeur  !=0  &&  tab[pion.ligne-2][pion.colonne+1].valeur != -1	&&  tab[pion.ligne-2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne+2].valeur = -1;
	}
  //saut en haut à gauche vers la colonne extérieure gauche
	if (pion.ligne > 1  &&  pion.colonne == 1	 &&  tab[pion.ligne-1][pion.colonne-1].valeur != 0  &&  tab[pion.ligne-1][pion.colonne-1].valeur != -1  &&	tab[pion.ligne-1][pion.colonne-2].valeur != 0  &&	 tab[pion.ligne-1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne-2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne-2][pion.colonne-2].valeur = -1;
	}
  //saut en bas à droite vers la colonne extérieure droite
	if (pion.ligne < n-2	 &&  pion.colonne == n-2  &&	 tab[pion.ligne+1][pion.colonne+1].valeur != 0  &&  tab[pion.ligne+1][pion.colonne+1].valeur != -1	&& tab[pion.ligne+2][pion.colonne+1].valeur  != 0	&&  tab[pion.ligne+2][pion.colonne+1].valeur  != -1  &&  tab[pion.ligne+2][pion.colonne+2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne+2].valeur = -1;
	}
  //saut en bas à gauche vers la colonne extérieure gauche
	if (pion.ligne < n-2	 &&  pion.colonne == 1  &&  tab[pion.ligne+1][pion.colonne-1].valeur != 0  &&	tab[pion.ligne+1][pion.colonne-1].valeur != -1  &&  tab[pion.ligne+1][pion.colonne-2].valeur != 0	 &&  tab[pion.ligne+1][pion.colonne-2].valeur != -1  &&  tab[pion.ligne+2][pion.colonne-2].valeur == 0){
		estPossible = 1;
		tab[pion.ligne+2][pion.colonne-2].valeur = -1;
	}
  if(estPossible == 1){
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if(tab[i][j].valeur == -1){
          pion2.ligne = i;
          pion2.colonne = j;
          estPossible = deplacementsPossiblesSautCercle(tab, n, pion2);
        }
      }
    }
  }
  return(estPossible);
}
