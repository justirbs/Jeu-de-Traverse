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
  s_pion*** jeu; //l'ensembles des plateaux du jeu
  s_pion** plateau; //le plateau du jeux
  int tour;
  int n;
  n = 10;
  tour = 0;
  plateau = creerTab2D(n);
  initTab(plateau, n);
  jeu = creerTab3D(1, n);
  do {
    system("clear");
    afficherTab(plateau,n);
    printf("\nNuméro du tour : %d\nC'est au tour du Joueur 1 (rouge) de jouer :\n\n", tour);
    joueurJoue(plateau, n, 1);
    if(tour > 1){
      jeu = agrandiTab(jeu, tour, n);
    }
    tour ++;
    jeu[tour-1] = copieTab2D(plateau, n);
    if (aGagne(plateau, n, tour) == 0   &&   !matchNul(jeu, n, tour)){
      system("clear");
      afficherTab(plateau,n);
      printf("\nNuméro du tour : %d\nC'est au tour du Joueur 2 (bleu) de jouer :\n\n", tour);
      joueurJoue(plateau, n, 2);
      jeu = agrandiTab(jeu, tour, n);
      tour ++;
      jeu[tour-1] = copieTab2D(plateau, n);;
    }
  } while(aGagne(plateau, n, tour) == 0  &&  !matchNul(jeu, n, tour));
  if(aGagne(plateau, n, tour) != 0){
    printf("Le joueur %d a gagné !\n", aGagne(plateau, n, tour));
  } else {
    printf("Match nul, c'est la troisième fois que l'on a cette disposition de plateau\n");
  }
  freeTab2D(plateau, n);
  freeTab3D(jeu, n, tour);
}





void partieJO(void){
  s_pion*** jeu; //l'ensembles des plateaux du jeu
  s_pion** plateau; //le plateau du jeux
  int tour;
  int n;
  n = 10;
  tour = 0;
  plateau = creerTab2D(n);
  initTab(plateau, n);
  jeu = creerTab3D(1, n);
  do {
    system("clear");
    afficherTab(plateau,n);
    printf("\nC'est au tour du Joueur 1 (en haut) de jouer :\n\n");
    joueurJoue(plateau, n, 1);
    if(tour > 1){
      jeu = agrandiTab(jeu, tour, n);
    }
    tour ++;
    jeu[tour-1] = copieTab2D(plateau, n);
    if (aGagne(plateau, n, tour) == 0  &&  !matchNul(jeu, n, tour)){
      system("clear");
      afficherTab(plateau, n);
      ordiJoue(plateau, n, jeu, tour, 2);
      jeu = agrandiTab(jeu, tour, n);
      tour ++;
      jeu[tour-1] = copieTab2D(plateau, n);
    }
  } while(aGagne(plateau, n, tour) == 0   &&   !matchNul(jeu, n, tour));
  if(aGagne(plateau, n, tour) != 0){
    printf("Le joueur %d a gagné !\n", aGagne(plateau, n, tour));
  } else {
    printf("Match nul, c'est la troisième fois que l'on a cette disposition de plateau\n");
  }
  freeTab2D(plateau, n);
  freeTab3D(jeu, n ,tour);
}



void partieOO(void){
  s_pion*** jeu; //l'ensembles des plateaux du jeu
  s_pion** plateau; //le plateau du jeux
  int tour;
  int n;
  n = 10;
  tour = 0;
  plateau = creerTab2D(n);
  initTab(plateau, n);
  jeu = creerTab3D(1, n);
  do {
    system("clear");
    afficherTab(plateau,n);
    ordiJoue(plateau, n, jeu, tour, 1);
    if(tour > 1){
      jeu = agrandiTab(jeu, tour, n);
    }
    tour ++;
    jeu[tour-1] = copieTab2D(plateau, n);
    if (aGagne(plateau, n, tour) == 0  &&  !matchNul(jeu, n, tour)){
      system("clear");
      afficherTab(plateau, n);
      ordiJoue(plateau, n, jeu, tour, 2);
      jeu = agrandiTab(jeu, tour, n);
      tour ++;
      jeu[tour-1] = copieTab2D(plateau, n);
    }
  } while(aGagne(plateau, n, tour) == 0   &&   !matchNul(jeu, n, tour));
  if(aGagne(plateau, n, tour) != 0){
    printf("Le joueur %d a gagné !\n", aGagne(plateau, n, tour));
  } else {
    printf("Match nul, c'est la troisième fois que l'on a cette disposition de plateau\n");
  }
  freeTab2D(plateau, n);
  freeTab3D(jeu, n ,tour);
}



void joueurJoue(s_pion** tab, int n, int joueur){
  s_coord pion;
  int estPossible; //variable booléenne qui indique si un déplacement est possible
  int aContinue; //variable bouléenne qui indique ou non si le joueur continue de chercher un pion jouable
  aContinue = 1;
  do {
    do {
      do {
        printf("Veuillez entrer la case du pion que vous voulez déplacer (ligne puis colonne) : \n");
        pion.ligne = saisirEntier();
        pion.colonne = saisirEntier();
        //la case doit exister sur le plateau
      } while((pion.ligne < 0 || pion.ligne >= n) || (pion.colonne < 0 || pion.colonne >= n));
      //la case doit contenir un pion du joueur
    } while(tab[pion.ligne][pion.colonne].joueur != joueur);
    //le pion doit pouvoir se déplacer
    estPossible = tourJoueur(tab, n, pion, joueur);
    aContinue = 0;
    if(estPossible == 0){
      printf("Votre pion ne peut pas être déplacé...\nSi vous voulez en essayer un autre, écrivez 1. Sinon écrivez 0.\n");
      do {
        aContinue = saisirEntier();
      } while (aContinue != 1  &&  aContinue != 0);
    }
  } while(aContinue == 1);
}


void ordiJoue(s_pion** tab, int n, s_pion*** jeu, int tour, int joueur){
  s_coord* pionDeb = malloc(sizeof(s_coord));
  s_coord* pionFin = malloc(sizeof(s_coord));
  s_coord pionTemp;
  int i;
  int j;
  int estPossible;
  int gain;
  estPossible = 0;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if (tab[i][j].joueur == joueur){
        pionTemp.ligne = i;
        pionTemp.colonne = j;
        if (deplacementsPossibles(tab, n, pionTemp)){
          estPossible = 1;
          enleveCroix(tab, n);
        }
      }
    }
  }
  if (estPossible){
    gain = tourMax(tab, n, jeu, tour, 1, pionDeb, pionFin, joueur);
    deplacerPion(tab, *pionDeb, joueur, *pionFin);
  }
  enleveCroix(tab, n);
}



int tourJoueur(s_pion** tab, int n, s_coord pion, int joueur){
	int estDeplace; //variable booléenne qui indique si le pion est déplacé
  s_coord pion2; //la future case du pion si il est déplacé
	estDeplace = 0;
  //on regarde si un déplacement est possible
	if (deplacementsPossibles(tab, n, pion)) {
    estDeplace = 1;
    system("clear");
    afficherTab(tab,n);
    pion2 = choixCase(tab, n);
    deplacerPion(tab, pion, joueur, pion2);
    enleveCroix(tab, n);
  }
	return(estDeplace);
}


s_coord choixCase(s_pion** tab, int n){
  s_coord pion2; //la future case du pion si il est déplacé
  do {
    do {
      printf("Veuillez entrer la ligne puis la colonne de la case où vous voulez déplacer votre pion : \n");
      pion2.ligne = saisirEntier();
      pion2.colonne = saisirEntier();
      //la future case doit faire partie du plateau
    } while((pion2.ligne < 0 || pion2.ligne >= n) || (pion2.colonne < 0 || pion2.colonne >= n));
    //la future case doit être un déplacement possible
  } while(tab[pion2.ligne][pion2.colonne].valeur != -1);
  return(pion2);
}


int aGagne(s_pion** tab, int n, int tour)
{
	int int_i;
	int gagne1 = 1;
	int gagne2 = 1;
  int aGagne;
	for (int_i = 1; int_i < n-1; int_i++)
	{
		if (tab[0][int_i].joueur != 2){
			gagne2 = 0;
		}
		if (tab[n-1][int_i].joueur != 1){
			gagne1 = 0;
		}
	}
	for (int_i = 1; int_i < n-1; int_i++)
	{
		if (tour>30 && tab[0][int_i].joueur == 1){
			gagne2 = 1;
		}
		if (tour>30 && tab[n-1][int_i].joueur == 2){
			gagne1 = 1;
		}
	}
  if(gagne1){
    aGagne = 1;
  } else {
    if(gagne2){
      aGagne = 2;
    } else {
      aGagne = 0;
    }
  }
  return(aGagne);
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
	test = malloc(sizeof(s_pion*) * n);
	for (int_i = 0; int_i < n; int_i++)
	{
		test[int_i] = malloc(sizeof(s_pion) *n);
	}

	for (int_i = 0; int_i < tour; int_i++){
		for (int_j = 0; int_j < n; int_j++){
			for (int_k = 0; int_k < n; int_k++){
				test[int_j][int_k] = jeu[int_i][int_j][int_k];
			}
		}
		plat_identique = 0;
		for (int_j = 0; int_j < tour; int_j++){
			identique = 1;
			for (int_k = 0; int_k < n; int_k++){
				for (int_l = 0; int_l < n; int_l++){
					if ( (test[int_k][int_l].valeur != jeu[int_j][int_k][int_l].valeur)  || (test[int_k][int_l].joueur != jeu[int_j][int_k][int_l].joueur)){
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
	return(matchnul);
}


int tourMax(s_pion** plateau, int n, s_pion*** jeu, int tour, int profondeur, s_coord* pionDeb, s_coord* pionFin, int joueur){
  int i;
  int j;
  int k;
  int l;
  int gainCourant;
  int gainMax;
  s_pion** copiePlateau;
  s_pion*** copieJeu;
  gainMax = -101;
  enleveCroix(plateau, n);
  if(profondeur == 0 || aGagne(plateau, n, tour) || matchNul(jeu, n, tour)){
    gainMax = evaluerGain(plateau, n, jeu, tour, joueur);
  } else {
    //pour tous les pions de l'IA
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if(plateau[i][j].joueur == joueur){
          enleveCroix(plateau, n);
          pionDeb->ligne = i;
          pionDeb->colonne = j;
          //Afficher les déplacements possibles
          if(deplacementsPossibles(plateau, n, *pionDeb)){
            //Pour chaque déplacement possible
            for(k=0; k<n; k++){
              for(l=0; l<n; l++){
                if(plateau[k][l].valeur == -1){
                  //on copie le plateau et le jeu
                  copiePlateau = copieTab2D(plateau, n);
                  copieJeu = copieTab3D(jeu, n, tour);
                  pionFin->ligne = k;
                  pionFin->colonne = l;
                  //on déplcae le pion dans la copie
                  deplacerPion(copiePlateau, *pionDeb, joueur, *pionFin);
                  //on simule le coup de l'utilisateur
                  gainCourant = tourMin(copiePlateau, n, copieJeu, tour, profondeur-1, joueur);
                  freeTab2D(copiePlateau, n);
                  freeTab3D(copieJeu, n, tour);
                  //on cherche le gain maximum
                  if(gainCourant > gainMax){
                    gainMax = gainCourant;
                    pionDeb->ligne = i;
                    pionDeb->colonne = j;
                    pionFin->ligne = k;
                    pionFin->colonne = l;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return(gainMax);
}


int tourMin(s_pion** plateau, int n, s_pion*** jeu, int tour, int profondeur, int joueur){
  int i;
  int j;
  int k;
  int l;
  int gainCourant;
  int gainMin;
  s_pion** copiePlateau;
  s_pion*** copieJeu;
  s_coord pionDeb;
  s_coord pionFin;
  int joueur2;
  if (joueur == 1){
    joueur2 = 2;
  } else {
    joueur2 = 1;
  }
  gainMin = 101;
  enleveCroix(plateau, n);
  if(profondeur == 0  ||   aGagne(plateau, n, tour)  ||  matchNul(jeu, n, tour)){
    gainMin = evaluerGain(plateau, n, jeu, tour, joueur2);
  } else {
    //pour tous les pions du joueur
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if(plateau[i][j].joueur == joueur2){
          pionDeb.ligne = i;
          pionDeb.colonne = j;
          //Afficher les déplacements possibles
          if(deplacementsPossibles(plateau, n, pionDeb)){
            //Pour chaque déplacement possible
            for(k=0; k<n; k++){
              for(l=0; l<n; l++){
                if(plateau[k][l].valeur == -1){
                  //on copie le plateau et le jeu
                  copiePlateau = copieTab2D(plateau, n);
                  copieJeu = copieTab3D(jeu, n, tour);
                  pionFin.ligne = k;
                  pionFin.colonne = l;
                  //on déplcae le pion dans la copie
                  deplacerPion(copiePlateau, pionDeb, joueur2, pionFin);
                  //on simule le coup de l'IA
                  gainCourant = tourMax(copiePlateau, n, copieJeu, tour, profondeur-1, &pionDeb, &pionFin, joueur);
                  freeTab2D(copiePlateau, n);
                  freeTab3D(copieJeu, n, tour);
                  //on cherche le gain le plus petit
                  if(gainCourant < gainMin){
                    gainMin = gainCourant;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return(gainMin);
}


int evaluerGain(s_pion** plateau, int n, s_pion*** jeu, int tour, int joueur){
  int gain;
  if (aGagne(plateau, n, tour) == joueur){
    gain = 100;
  } else {
    if (aGagne(plateau, n, tour) != joueur  &&  aGagne(plateau, n, tour) != 0){
      gain = -100;
    } else {
      if (matchNul(jeu, n, tour)){
        gain = 0;
      } else {
        gain = calculGain(plateau, n, joueur);
      }
    }
  }
  return(gain);
}


int calculGain(s_pion** plateau, int n, int joueur){
  int somme;
  int i;
  int j;
  somme = 0;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if (plateau[i][j].joueur == joueur){
        if (joueur == 1){
          somme = somme + i + 1;
        } else {
          somme = somme + n - i;
        }
      }
    }
  }
  return(somme);
}
