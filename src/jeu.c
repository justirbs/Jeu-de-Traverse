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
  int colone; //la colonne du pion à déplacer
  //on choisi d'abord le pions à déplacer
  do {
    do {
      printf("Veuillez entrer la case du pion que vous voulez déplacer (ligne puis colonne) : \n");
      ligne = saisirEntier();
      colone = saisirEntier();
      //la case doit exister sur le plateau
    } while((ligne < 0 || ligne >= n) || (colone < 0 || colone >= n));
    //la case doit contenir un pion du joueur
  } while(tab[ligne][colone].joueur != joueur);
  printf("ok choix\n");
  if (deplacement(tab, n, ligne, colone)) {
    printf("ok deplacement\n");
  }
}


int deplacement(s_pion** tab, int n, int ligne, int colone){
  int estDeplace; //variable booléenne qui indique si le pion est déplacé
  switch (tab[ligne][colone].valeur) {
    case 1 : estDeplace = deplacementCarre(tab, n, ligne, colone);
      break;
    case 2 : estDeplace = 1;
      break;
    case 3 : estDeplace = 1;
      break;
    case 4 : estDeplace = 1;
      break;
    default : printf("erreur\n");
      estDeplace = 0;
      break;
  }
  return(estDeplace);
}


int deplacementCarre(s_pion** tab, int n, int ligne, int colone){
  int estDeplace;
  estDeplace = 0;
  int choix; //choix de déplacement du joueur
  printf("Vers où voulez-vous déplacer votre pion carré ?\n1-Vers le haut\n2-Vers le bas\n3-Vers le droite\n4-Vers la gauche\n");
  do {
    //choix du déplacement
    do {
      printf("Veuillez choisir votre déplacement\n");
      choix = saisirEntier();
    } while (choix < 1  ||  choix > 4);
    //déplacement
    switch (choix) {
      case 1 :
        if (ligne > 0  &&  tab[ligne-1][colone].valeur == 0){
          estDeplace = 1;
          deplacementHaut(tab, ligne, colone, 1);
        }
        break;
      case 2 :
        if (ligne < n+1  && tab[ligne+1][colone].valeur == 0){
          estDeplace = 1;
          deplacementBas(tab, ligne, colone, 1);
        }
        break;
      case 3 :
        if (colone < n+2  &&  tab[ligne][colone+1].valeur == 0){
          estDeplace = 1;
          deplacementDroite(tab, ligne, colone, 1);
        }
        break;
      case 4 :
        if (colone > 1  &&  tab[ligne][colone-1].valeur == 0){
          estDeplace = 1;
          deplacementGauche(tab, ligne, colone, 1);
        }
        break;
      default :
        printf("Ce déplacement n'existe pas ...\n");
        break;
    }
    if (!estDeplace){
      printf("Déplacement impossible\n");
    }
  } while (!estDeplace);
  return(estDeplace);
}


void deplacementHaut(s_pion** tab, int ligne, int colone, int valeur){
  tab[ligne-1][colone].valeur = valeur;
  tab[ligne][colone].valeur = 0;
}


void deplacementBas(s_pion** tab, int ligne, int colone, int valeur){
  tab[ligne+1][colone].valeur = valeur;
  tab[ligne][colone].valeur = 0;
}


void deplacementDroite(s_pion** tab, int ligne, int colone, int valeur){
  tab[ligne][colone+1].valeur = valeur;
  tab[ligne][colone].valeur = 0;
}


void deplacementGauche(s_pion** tab, int ligne, int colone, int valeur){
  tab[ligne][colone-1].valeur = valeur;
  tab[ligne][colone].valeur = 0;
}


void deplacementHautD(s_pion** tab, int ligne, int colone, int valeur){
  tab[ligne-1][colone+1].valeur = valeur;
  tab[ligne][colone].valeur = 0;
}


void deplacementHautG(s_pion** tab, int ligne, int colone, int valeur){
  tab[ligne-1][colone-1].valeur = valeur;
  tab[ligne][colone].valeur = 0;
}


void deplacementBasD(s_pion** tab, int ligne, int colone, int valeur){
  tab[ligne+1][colone+1].valeur = valeur;
  tab[ligne][colone].valeur = 0;
}


void deplacementBasG(s_pion** tab, int ligne, int colone, int valeur){
  tab[ligne+1][colone-1].valeur = valeur;
  tab[ligne][colone].valeur = 0;
}
