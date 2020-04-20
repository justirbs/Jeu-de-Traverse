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

int** creerTabEntier2D(int n)
{
  int** tab; //tableau d'entiers
  int i; //iterrateur de boucle
  tab = malloc(n*sizeof(int*));
  if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
  }
  for(i=0; i<n; i++){
    tab[i] = malloc(n*sizeof(int));
    if(tab==NULL){
    fprintf(stderr, "problème d'alloc\n");
    exit(1);
    }
  }
  return(tab);
}

void initTab(int** tab, int n){
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  srand(time(NULL));
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      tab[i][j] = ' ';
    }
  }
  initLigne(tab, n, 0);
  initLigne(tab, n, n-1);
}


void initLigne(int** tab, int n, int ligne){
  //Insertion des ■
  tab[ligne][1] = '■';
  tab[ligne][n-2] = tab[0][1];
  //Insertion des ▲
  tab[ligne][2] = '▲';
  tab[ligne][n-3] = tab[0][2];
  //Insertion des ♦
  tab[ligne][3] = '♦';
  tab[ligne][n-4] = tab[0][3];
  //Insertion des •
  tab[ligne][4] = '•';
  tab[ligne][n-5] = tab[0][4];
}


void afficherTab(int** tab, int n){
  int i; //iterrateur de boucle
  int j; //iterrateur de boucle
  int k;
  for(i=0; i<n; i++){
    for(k=0; k<n; k++){
      printf("----");
    }
    printf("-\n|");
    for(j=0; j<n; j++){
      printf(" %c |", tab[i][j]);
    }
    printf("\n");
  }
  for(k=0; k<n; k++){
    printf("----");
  }
  printf("-\n|");
}
