#include "header.h"

char **vertical(char **grid, int length, int width, int i, int j,int *pscore) {
    /*-----------------------------------------------------------------
    - Parametres :  - grid (char**) : La grille de jeu
                    - length (int) : La longueur de la grille
                    - widht (int) : La largeur de la grille
                    - i (int) : Coordonnée de la ligne
                    - j (int) : Coordonnée de la colonne
                    - score (int*) : Score
    
    - Fonction : Supprime tous les alignements verticaux

    - Retour : Renvoie une grille après modification
    -----------------------------------------------------------------*/
  if ((j <= length - 1 && j >= 0) && (i <= width - 2 && i >= 1)) {
    int top_border = 0, bottom_border = width - 1;
    int top = i - 1, bottom = i + 1;
    
    // -- Vérifie l'alignement avec les bords de la grille pour chaque colonne et supprime les symboles alignés en haut et en bas de la grille
    if ((i == 1 || i == width - 2) && grid[i][j] == grid[0][j] &&
        grid[i][j] == grid[width - 1][j]) {
      while (top_border + 1 <= width - 1 && grid[0][j] == grid[top_border + 1][j]) {
        grid[top_border + 1][j] = ' ';
        *pscore += 10;
        top_border++;
      }

      while (bottom_border - 1 > 1 &&
             grid[width - 1][j] == grid[bottom_border - 1][j]) {
        grid[bottom_border - 1][j] = ' ';
        *pscore += 10;
        bottom_border--;
      }

      grid[i][j] = ' ';
      grid[0][j] = ' ';
      grid[width - 1][j] = ' ';
      *pscore += 30;
    }

    // -- Vérifie l'alignement vertical pour chaque colonne et supprime les symboles alignés
    if (grid[bottom][j] == grid[i][j] && grid[top][j] == grid[i][j]) {
      while (top - 1 > 0 && grid[i][j] == grid[top - 1][j]) {
        grid[top - 1][j] = ' ';
        *pscore += 10;
        top--;
      }

      while (bottom + 1 < width - 1 && grid[i][j] == grid[bottom + 1][j]) {
        grid[bottom + 1][j] = ' ';
        *pscore += 10;
        bottom++;
      }

      grid[i][j] = ' ';
      grid[i - 1][j] = ' ';
      grid[i + 1][j] = ' ';
      *pscore += 30;
    }
    
  }
  
  return grid;
  
}

char **horizontal(char **grid, int length, int width, int i, int j,int *pscore) {
  /*-----------------------------------------------------------------
    - Parametres :  - grid (char**) : La grille de jeu
                    - length (int) : La longueur de la grille
                    - widht (int) : La largeur de la grille
                    - i (int) : Coordonnée de la ligne
                    - j (int) : Coordonnée de la colonne
                    - score (int*) : Score
    
    - Fonction : Supprime tous les alignements horizontaux

    - Retour : Renvoie une grille après modification
   -----------------------------------------------------------------*/
  
  if ((i <= width - 1 && i >= 0) && (j <= length - 2 && j >= 1)) {
    int left_border = 0, right_border = length - 1;
    int left = j - 1, right = j + 1;
    
    // -- Vérifie l'alignement avec les bords de la grille pour chaque ligne et supprime les symboles alignés à gauche et à droite de la grille
    if ((j == 1 || j == length - 2) && grid[i][j] == grid[i][0] &&
        grid[i][j] == grid[i][length - 1]) {
      while (left_border + 1 <= length - 1 &&
             grid[i][0] == grid[i][left_border + 1]) {
        grid[i][left_border + 1] = ' ';
        *pscore += 10;
        left_border++;
      }

      while (right_border - 1 >= 0 &&
             grid[i][length - 1] == grid[i][right_border - 1]) {
        grid[i][right_border - 1] = ' ';
        pscore += 10;
        right_border--;
      }

      grid[i][j] = ' ';
      grid[i][0] = ' ';
      grid[i][length - 1] = ' ';
      *pscore += 30;
    }

    // -- Vérifie l'alignement horizontal pour chaque ligne et supprime les symboles alignés
    if (grid[i][right] == grid[i][j] && grid[i][left] == grid[i][j]) {
      while (left - 1 > 0 && grid[i][j] == grid[i][left - 1]) {
        grid[i][left - 1] = ' ';
        *pscore += 10;
        left--;
      }

      while (right + 1 < length - 1 && grid[i][j] == grid[i][right + 1]) {
        grid[i][right + 1] = ' ';
        pscore += 10;
        right++;
      }
      
      grid[i][j] = ' ';
      grid[i][j - 1] = ' ';
      grid[i][j + 1] = ' ';
      *pscore += 30;
    }
    
  }
  
  return grid;
}


char **clearsymbol(char **grid, int length, int width,int *pscore) {
      /*-----------------------------------------------------------------
    - Parametres :  - grid (char**) : La grille de jeu
                    - length (int) : La longueur de la grille
                    - widht (int) : La largeur de la grille
                    - score (int*) : Score
    
    - Fonction : Supprime tous les alignements

    - Retour : Renvoie une grille après modification
    -----------------------------------------------------------------*/
  
  int i, j;
  char **gridinter;
  // -- Vérifie l'alignement horizontal des symboles
  for (i = 0; i < width; i++) {
    for (j = 1; j < length - 1; j++) {
      grid = horizontal(grid, length, width, i, j,pscore);
    }
    
  }

  // -- Vérifie l'alignement verticale des symboles
  for (j = 0; j < length; j++) {
    for (i = 1; i < width - 1; i++) {
      gridinter = vertical(grid, length, width, i, j,pscore);
    }
    
  }
  
  // -- Fusion des deux tableaux
  for (i = 0; i < width; i++) {
    for (j = 0; j < length; j++) {
      if (gridinter[i][j] == ' ') {
        grid[i][j] = ' ';
      }
      
    }
    
  }

  return grid;
}
