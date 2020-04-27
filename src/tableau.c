/*!
 * \file tableau.c
 *
 * \author Vincent Donney et Justine Ribas <ribasjusti@eisti.eu>
 * \version 0.1
 * \date 20 avril 2020
 *
 * \brief fonctions pour créer des tableaux
 *
 *
 */

// Inclusion des entêtes de librairies
#include"tableau.h"


// Codes des fonctions

s_pion** creerTab2D(int n)
{
  s_pion** tab; //tableau d'entiers
  int i; //iterrateur de boucle
  tab = malloc(n*sizeof(s_pion*));
  if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }
  for(i=0; i<n; i++){
    tab[i] = malloc(n*sizeof(s_pion));
    if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
    }
  }
  return(tab);
}


s_pion*** creerTab3D(int n, int m){
  s_pion*** tab; //tableau d'entiers
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  tab = malloc(n*sizeof(s_pion**));
  if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }
  for(i=0; i<n; i++){
    tab[i] = malloc(n*sizeof(s_pion*));
    if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
    }
    for(j=0; i<n; i++){
      tab[i][j] = malloc(n*sizeof(s_pion));
      if(tab==NULL){
      fprintf(stderr, "problème d'alloc\n");
      exit(1);
      }
    }
  }
  return(tab);
}


void initTab(s_pion** tab, int n){
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      tab[i][j].valeur = 0;
      tab[i][j].joueur = 0;
    }
  }
  initLigne(tab, n, 0, 1);
  initLigne(tab, n, n-1, 2);
}


void initLigne(s_pion** tab, int n, int ligne, int joueur){
  //Insertion des ■
  tab[ligne][1].valeur = 1;
  tab[ligne][n-2].valeur = 1;
  tab[ligne][1].joueur = joueur;
  tab[ligne][n-2].joueur = joueur;
  //Insertion des ▲
  tab[ligne][2].valeur = 2;
  tab[ligne][n-3].valeur = 2;
  tab[ligne][2].joueur = joueur;
  tab[ligne][n-3].joueur = joueur;
  //Insertion des ♦
  tab[ligne][3].valeur = 3;
  tab[ligne][n-4].valeur = 3;
  tab[ligne][3].joueur = joueur;
  tab[ligne][n-4].joueur = joueur;
  //Insertion des •
  tab[ligne][4].valeur = 4;
  tab[ligne][n-5].valeur = 4;
  tab[ligne][4].joueur = joueur;
  tab[ligne][n-5].joueur = joueur;
}


void afficherTab(s_pion** tab, int n){
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int k; //iterrateur de boucle
  printf(" ");
  for(k=0; k<n; k++){
    printf(" %d  ", k);
  }
  printf("\n");
  for(i=0; i<n; i++){
    for(k=0; k<n; k++){
      printf("----");
    }
    printf("-\n|");
    for(j=0; j<n; j++){
      switch (tab[i][j].joueur){
        case 0 :
            printf(" %c |", pion(tab[i][j].valeur));
          break;
        case 1 :
          printf("\033[0;31m");
          printf(" %c", pion(tab[i][j].valeur));
          printf("\033[0m");
          printf(" |");
          break;
        case 2 :
          printf("\033[0;34m");
          printf(" %c", pion(tab[i][j].valeur));
          printf("\033[0m");
          printf(" |");
          break;
        default :
          printf("erreur\n");
          break;
      }
    }
    printf(" %d\n", i);
  }
  for(k=0; k<n; k++){
    printf("----");
  }
  printf("-\n");
}


char pion(int valeur){
  char symbole; //le symbole du pion
  switch (valeur){
    case -1 :
      symbole = 'X';
      break;
    case 0 :
      symbole = ' ';
      break;
    case 1 :
      symbole = '■';
      break;
    case 2 :
      symbole = '▲';
      break;
    case 3 :
      symbole = '♦';
      break;
    case 4 :
      symbole = '•';
      break;
    default :
      printf("Erreur\n");
      break;
  }
  return(symbole);
}


void enleveCroix(s_pion** tab, int n){
  int i;
  int j;
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(tab[i][j].valeur == -1){
        tab[i][j].valeur = 0;
      }
    }
  }
}
