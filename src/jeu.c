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

/*Fonction qui déroule une partie "Joueur-Joueur"*/
void partieJJ(void){
  s_pion*** jeu; //l'ensembles des plateaux du jeu depuis le début de la partie
  s_pion** plateau; //le plateau du jeux actuel
  int tour; //le nombre de tours depuis le début de la partie
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
    }
    tour ++;
    jeu[tour-1] = copieTab2D(plateau, n);
    if (aGagne(plateau, n, tour) == 0  &&  !matchNul(jeu, n, tour)){
      system("clear");
      afficherTab(plateau, n);
      ordiJoue(plateau, n, jeu, tour, 2);
      jeu = agrandiTab(jeu, tour, n);
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
    printf("\nNombre de tours : %d\n", tour);
    ordiJoue(plateau, n, jeu, tour, 1);
    if(tour > 1){
      jeu = agrandiTab(jeu, tour, n);
    }
    tour ++;
    jeu[tour-1] = copieTab2D(plateau, n);
    //sleep(1);
    if (aGagne(plateau, n, tour) == 0  &&  !matchNul(jeu, n, tour)){
      system("clear");
      afficherTab(plateau, n);
      printf("\nNombre de tours : %d\n", tour);
      ordiJoue(plateau, n, jeu, tour, 2);
      jeu = agrandiTab(jeu, tour, n);
      tour ++;
      jeu[tour-1] = copieTab2D(plateau, n);
      //sleep(1);
    }
    printf("A gagner : %d\n", aGagne(plateau, n, tour));
  } while(aGagne(plateau, n, tour) == 0   &&   !matchNul(jeu, n, tour));
  system("clear");
  afficherTab(plateau, n);
  printf("\nNombre de tours : %d\n", tour);
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
    gain = minMax(tab, n, jeu, tour, 2, pionDeb, pionFin, joueur, 1);
    deplacerPion(tab, *pionDeb, joueur, *pionFin);
    gain++;
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
  //un joueur n'a pas gagné si tous ses pions ne sont pas sur la ligne d'arrivé
	for (int_i = 1; int_i < n-1; int_i++)
	{
		if (tab[0][int_i].joueur != 2){
			gagne2 = 0;
		}
		if (tab[n-1][int_i].joueur != 1){
			gagne1 = 0;
		}
	}
  //si au tour 30 un joueur a des pions sur sa ligne de départ, l'adversaire gagne
  if (tour>30){
  	for (int_i = 1; int_i < n-1; int_i++)
  	{
  		if (tab[0][int_i].joueur == 1){
  			gagne2 = 1;
  		}
  		if (tab[n-1][int_i].joueur == 2){
  			gagne1 = 1;
  		}
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
	int identique; //vrai si deux plateau sont identiques
	int plat_identique; //le compteur de plateau identique
	int matchnul; //vrai si le match est nul
	matchnul = 0;

	for (int_i = 0; int_i < tour; int_i++){
		plat_identique = 0;
		for (int_j = 0; int_j < tour; int_j++){
      if (int_i != int_j) {
        //Verrifier si les deux plateaux courants sont identiques
  			identique = 1;
        int_k = 0;
  			while (identique == 1 && int_k < n){
          int_l = 0;
  				while (identique == 1 && int_l < n){
  					if ( (jeu[int_i][int_k][int_l].valeur != jeu[int_j][int_k][int_l].valeur)  || (jeu[int_i][int_k][int_l].joueur != jeu[int_j][int_k][int_l].joueur)){
  						identique = 0;
  					}
            int_l++;
  				}
          int_k++;
  			}
        //si ils sont identiques, augmenter le compteur
  			if (identique == 1){
  				plat_identique++;
  			}
      }
		}
    //si il y a plus de deux plateaux identiques, alors le match est nul
		if(plat_identique > 2){
			matchnul = 1;
		}
	}
	return(matchnul);
}


int minMax(s_pion** plateau, int n, s_pion*** jeu, int tour, int profondeur, s_coord* pionDeb, s_coord* pionFin, int joueur, int evalMax){
  int i;
  int j;
  int k;
  int l;
  int gainCourant;
  int gainResultat;
  s_pion** copiePlateau;
  s_pion*** copieJeu;
  s_coord* pionDebTemp = malloc(sizeof(s_coord));
  s_coord* pionFinTemp = malloc(sizeof(s_coord));
  gainResultat = -2000;
  enleveCroix(plateau, n);
  if(profondeur == 0 || aGagne(plateau, n, tour) != 0 || matchNul(jeu, n, tour)){
    gainResultat = evaluerGain(plateau, n, jeu, tour, joueur);
  } else {
    //pour tous les pions de l'IA
    for(i=0; i<n; i++){
      for(j=0; j<n; j++){
        if(plateau[i][j].joueur == joueur){
          enleveCroix(plateau, n);
          pionDebTemp->ligne = i;
          pionDebTemp->colonne = j;
          //Afficher les déplacements possibles
          if(deplacementsPossibles(plateau, n, *pionDebTemp)){
            //Pour chaque déplacement possible
            for(k=0; k<n; k++){
              for(l=0; l<n; l++){
                if(plateau[k][l].valeur == -1){
                  //on copie le plateau et le jeu
                  copiePlateau = copieTab2D(plateau, n);
                  copieJeu = copieTab3D(jeu, n, tour);
                  enleveCroix(copiePlateau, n);
                  pionDebTemp->ligne = i;
                  pionDebTemp->colonne = j;
                  pionFinTemp->ligne = k;
                  pionFinTemp->colonne = l;
                  //printf("\n");
                  //afficherTab(copiePlateau, n);
                  //sleep(1);
                  //L'IA JOUE
                  deplacerPion(copiePlateau, *pionDebTemp, joueur, *pionFinTemp);
                  if(tour > 1){
                    copieJeu = agrandiTab(copieJeu, tour, n);
                  }
                  copieJeu[tour] = copieTab2D(copiePlateau, n);
                  //on simule le coup de l'utilisateur
                  gainCourant = minMax(copiePlateau, n, copieJeu, tour+1, profondeur-1, pionDebTemp, pionFinTemp,(joueur == 1 ? 2 : 1), !evalMax);
                  freeTab2D(copiePlateau, n);
                  freeTab3D(copieJeu, n, tour);
                  if((evalMax && gainCourant > gainResultat) || (!evalMax && gainCourant < gainResultat) || gainResultat == -2000){
                    gainResultat = gainCourant;
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
  free(pionDebTemp);
  free(pionFinTemp);
  enleveCroix(plateau, n);
  //sleep(1);
  //printf("\nPour le joueur %d, on déplace le pion %d;%d à la case %d;%d \nLe gain est %d\n\n", joueur, pionDeb->ligne, pionDeb->colonne, pionFin->ligne, pionFin->colonne, gainMax );
  return(gainResultat);
}


int evaluerGain(s_pion** plateau, int n, s_pion*** jeu, int tour, int joueur){
  int gain;
  if (aGagne(plateau, n, tour) == joueur){
    gain = 1000;
  } else {
    if (aGagne(plateau, n, tour) != joueur  &&  aGagne(plateau, n, tour) != 0){
      gain = -1000;
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
      //on ajoute les distance des pion de l'IA depuis sa ligne d'arrivée
      if (plateau[i][j].joueur == joueur){
        if (joueur == 1){
          somme += (i==0 ? -100 : i);
        } else {
          somme += (i==9 ? -100 : n - 1 - i);
        }
      }
      //on retire les distance des pion de l'adversaire depuis sa ligne d'arrivée
      if (plateau[i][j].joueur != joueur  &&  plateau[i][j].joueur != 0){
        if (joueur == 1){
          somme -= i;
        } else {
          somme -= n - 1 - i;
        }
      }
    }
  }
  return(somme);
}
