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
  do {
    do {
      do {
        printf("Veuillez entrer la case du pion que vous voulez déplacer (ligne puis colonne) : \n");
        ligne = saisirEntier();
        colone = saisirEntier();
        //la case doit exister sur le plateau
      } while((ligne < 0 || ligne >= n) || (colone < 0 || colone >= n));
      //la case doit contenir un pion du joueur
    } while(tab[ligne][colone].joueur != joueur);
    //le pion doit pouvoir se déplacer
  } while(!deplacement(tab, n, ligne, colone, joueur));
}


int deplacement(s_pion** tab, int n, int ligne, int colone, int joueur){
  int estDeplace; //variable booléenne qui indique si le pion est déplacé
  int ligne2;
  int colone2;
  estDeplace = 0;
  if (deplacementsPossibles(tab, n, ligne, colone)) {
    estDeplace = 1;
    afficherTab(tab,n);
    do {
      do {
        printf("Veuillez entrer la ligne puis la colonne de la case où vous voulez déplacer votre pion : \n");
        ligne2 = saisirEntier();
        colone2 = saisirEntier();
      } while((ligne2 < 0 || ligne2 >= n) || (colone2 < 0 || colone2 >= n));
    } while(tab[ligne2][colone2].valeur != -1);
    tab[ligne2][colone2].valeur = tab[ligne][colone].valeur;
    tab[ligne2][colone2].joueur = joueur;
    tab[ligne][colone].valeur = 0;
    tab[ligne][colone].joueur = 0;
    enleveCroix(tab, n);
  }
  return(estDeplace);
}


int deplacementsPossibles(s_pion** tab, int n, int ligne, int colone){
  int estPossible;
  estPossible = 0;
  switch (tab[ligne][colone].valeur) {
    case 1 :
      if (deplacementsPossiblesCarre(tab, n, ligne, colone)){
        estPossible = 1;
      }
      break;
    case 2 :
      if (deplacementsPossiblesTriangle(tab, n, ligne, colone)){
        estPossible = 1;
      }
      break;
    case 3 :
      if (deplacementsPossiblesLosange(tab, n, ligne, colone)){
        estPossible = 1;
      }
      break;
    case 4 :
      if (deplacementsPossiblesCercle(tab, n, ligne, colone)){
        estPossible = 1;
      }
      break;
    default :
      break;
  }
  return(estPossible);
}


int deplacementsPossiblesCarre(s_pion** tab, int n, int ligne, int colone){
  int estPossible;
  estPossible = 0;
  //déplacement en haut
  if (ligne > 0  &&  tab[ligne-1][colone].valeur == 0){
    estPossible = 1;
    tab[ligne-1][colone].valeur = -1;
  }
  //déplacement en bas
  if (ligne < n-1  &&  tab[ligne+1][colone].valeur == 0){
    estPossible = 1;
    tab[ligne+1][colone].valeur = -1;
  }
  //déplacement à droite
  if (colone < n-2  &&  tab[ligne][colone+1].valeur == 0){
    estPossible = 1;
    tab[ligne][colone+1].valeur = -1;
  }
  //déplacement à gauche
  if (colone > 1  &&  tab[ligne][colone-1].valeur == 0){
    estPossible = 1;
    tab[ligne][colone-1].valeur = -1;
  }
  return(estPossible);
}


int deplacementsPossiblesTriangle(s_pion** tab, int n, int ligne, int colone){
  int estPossible;
  estPossible = 0;
  //déplacement en bas
  if (ligne < n-1  &&  tab[ligne+1][colone].valeur == 0){
    estPossible = 1;
    tab[ligne+1][colone].valeur = -1;
  }
  //déplacement en haut à droite
  if (ligne > 0  &&  colone < n-2  &&  tab[ligne-1][colone+1].valeur == 0){
    estPossible = 1;
    tab[ligne-1][colone+1].valeur = -1;
  }
  //déplacement en haut à gauche
  if (ligne > 0  &&  colone > 1 &&  tab[ligne-1][colone-1].valeur == 0){
    estPossible = 1;
    tab[ligne-1][colone-1].valeur = -1;
  }
  return(estPossible);
}


int deplacementsPossiblesLosange(s_pion** tab, int n, int ligne, int colone){
  int estPossible;
  estPossible = 0;
  //déplacement en haut à droite
  if (ligne > 0  &&  colone < n-2  &&  tab[ligne-1][colone+1].valeur == 0){
    estPossible = 1;
    tab[ligne-1][colone+1].valeur = -1;
  }
  //déplacement en haut à gauche
  if (ligne > 0  &&  colone > 1 &&  tab[ligne-1][colone-1].valeur == 0){
    estPossible = 1;
    tab[ligne-1][colone-1].valeur = -1;
  }
  //déplacement en bas à droite
  if (ligne < n-1  &&  colone < n-2  &&  tab[ligne+1][colone+1].valeur == 0){
    estPossible = 1;
    tab[ligne+1][colone+1].valeur = -1;
  }
  //déplacement en bas à gauche
  if (ligne < n-1  &&  colone > 1 &&  tab[ligne+1][colone-1].valeur == 0){
    estPossible = 1;
    tab[ligne+1][colone-1].valeur = -1;
  }
  return(estPossible);
}


int deplacementsPossiblesCercle(s_pion** tab, int n, int ligne, int colone){
  int estPossible;
  estPossible = 0;
  //déplacement en haut
  if (ligne > 0  &&  tab[ligne-1][colone].valeur == 0){
    estPossible = 1;
    tab[ligne-1][colone].valeur = -1;
  }
  //déplacement en bas
  if (ligne < n-1  &&  tab[ligne+1][colone].valeur == 0){
    estPossible = 1;
    tab[ligne+1][colone].valeur = -1;
  }
  //déplacement à droite
  if (colone < n-2  &&  tab[ligne][colone+1].valeur == 0){
    estPossible = 1;
    tab[ligne][colone+1].valeur = -1;
  }
  //déplacement à gauche
  if (colone > 1  &&  tab[ligne][colone-1].valeur == 0){
    estPossible = 1;
    tab[ligne][colone-1].valeur = -1;
  }
  //déplacement en haut à droite
  if (ligne > 0  &&  colone < n-2  &&  tab[ligne-1][colone+1].valeur == 0){
    estPossible = 1;
    tab[ligne-1][colone+1].valeur = -1;
  }
  //déplacement en haut à gauche
  if (ligne > 0  &&  colone > 1 &&  tab[ligne-1][colone-1].valeur == 0){
    estPossible = 1;
    tab[ligne-1][colone-1].valeur = -1;
  }
  //déplacement en bas à droite
  if (ligne < n-1  &&  colone < n-2  &&  tab[ligne+1][colone+1].valeur == 0){
    estPossible = 1;
    tab[ligne+1][colone+1].valeur = -1;
  }
  //déplacement en bas à gauche
  if (ligne < n-1  &&  colone > 1 &&  tab[ligne+1][colone-1].valeur == 0){
    estPossible = 1;
    tab[ligne+1][colone-1].valeur = -1;
  }
  return(estPossible);
}
