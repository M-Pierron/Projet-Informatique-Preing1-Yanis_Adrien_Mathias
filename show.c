#include "header.h"

void showemoji(char **tab, int i, int j) {
  /*-----------------------------------------------------------------
  - Parametres :  - grid (char**) : La grille de jeu
                  - i (int) : Coordonnée de la ligne
                  - j (int) : Coordonnée de la colone

  - Fonction : En fonction de la lettre contenue aux coordonnées (i,j)
  l'affiche avec un emoji

  - Retour : vide
  -----------------------------------------------------------------*/
  switch (tab[i][j]) {
  case ('A'):
    printf("\U0001F37E");
    break;
  case ('B'):
    printf("\U0001F377");
    break;
  case ('C'):
    printf("\U0001F378");
    break;
  case ('D'):
    printf("\U0001F379");
    break;
  case ('E'):
    printf("\U0001F942");
    break;
  case ('F'):
    printf("\U0001F37A");
    break;
  default:
    printf("%c", tab[i][j]);
    break;
  }
}

void ShowTab(char **tab, int length, int width) {
  /*-----------------------------------------------------------------
  - Parametres :  - grid (char**) : La grille de jeu
                  - length (int) : La longueur de la grille
                  - widht (int) : La largeur de la grille

  - Fonction : Affiche les caracteres dans la console

  - Retour : vide
  -----------------------------------------------------------------*/

  // -- Affichage des symboles avec décalage pour la largeur
  if (width > 9 && length <= 9) {
    printf("   ");
    for (int j = 0; j < length; j++) {
      printf("%d  ", j + 1);
    }

    printf("\n");
    for (int i = 0; i < 9; i++) {
      printf(" ");
      printf("%d ", i + 1);
      for (int j = 0; j < length; j++) {
        showemoji(tab, i, j);
        printf(" ");
      }

      printf("\n");
    }

    for (int i = 9; i < width; i++) {
      printf("%d ", i + 1);
      for (int g = 0; g < length; g++) {
        showemoji(tab, i, g);
        printf(" ");
      }

      printf("\n");
    }

  }

  // -- Affichage des symboles avec décalage pour la longueur
  else if (length > 9 && width <= 9) {
    printf(" ");
    for (int j = 0; j < 9; j++) {
      printf("%d  ", j + 1);
    }

    for (int j = 9; j < length; j++) {
      printf("%d ", j + 1);
    }

    printf("\n");
    for (int i = 0; i < width; i++) {
      printf("%d", i + 1);
      for (int h = 0; h < 9; h++) {
        showemoji(tab, i, h);
        printf(" ");
      }

      for (int g = 9; g < length; g++) {
        showemoji(tab, i, g);
        printf(" ");
      }

      printf("\n");
    }

  }

  // -- Affichage des symboles avec décalage pour la longueur et la largeur
  else if (length > 9 && width > 9) {
    printf("   ");
    for (int j = 0; j < 9; j++) {
      printf("%d  ", j + 1);
    }

    for (int j = 9; j < length; j++) {
      printf("%d ", j + 1);
    }

    printf("\n");
    for (int i = 0; i < 9; i++) {
      printf(" ");
      printf("%d ", i + 1);
      for (int h = 0; h < 9; h++) {
        showemoji(tab, i, h);
        printf(" ");
      }

      for (int g = 9; g < length; g++) {
        showemoji(tab, i, g);
        printf(" ");
      }

      printf("\n");
    }

    for (int h = 9; h < width; h++) {
      printf("%d ", h + 1);
      for (int f = 0; f < 9; f++) {
        showemoji(tab, h, f);
        printf(" ");
      }

      for (int t = 9; t < length; t++) {
        showemoji(tab, h, t);
        printf(" ");
      }

      printf("\n");
    }

  }

  // -- Affichage des symboles sans décalage
  else {
    printf("  ");
    for (int j = 0; j < length; j++) {
      printf("%d ", j + 1);
    }

    printf("\n");
    for (int i = 0; i < width; i++) {
      printf("%d", i + 1);
      for (int j = 0; j < length; j++) {
        showemoji(tab, i, j);
      }

      printf("\n");
    }
  }
}
 
