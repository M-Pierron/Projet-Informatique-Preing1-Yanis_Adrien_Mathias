#include "header.h"

char **mooveCase(char **grid, int i1, int i2, int j1, int j2) {
  /*-------------------------------------------------------------------
    - Parametres :  - grid (char**) : La grille de jeu
                    - i1 (int) : Coordonnée de la ligne de la case 1
                    - j1 (int) : Coordonnée de la colonne de la case 1
                    - i2 (int) : Coordonnée de la ligne de la case 1
                    - j2 (int) : Coordonnée de la colonne de la case 1
                    
    
    - Fonction : Inverse deux cases du tableau

    - Retour : La nouvelle grille avec les deux symboles deplacés
    -------------------------------------------------------------------*/
  
  // -- Variable intermediaire
  char temp = grid[i1][j1]; 
  grid[i1][j1] = grid[i2][j2];
  grid[i2][j2] = temp;
  return grid;
}

char **gravity(char **grid, int length, int width, int nmbr_of_symbol) {
    /*-----------------------------------------------------------------
    - Parametres :  - grid (char**) : La grille de jeu
                    - length (int) : La longueur de la grille
                    - widht (int) : La largeur de la grille
                    - nmbr_of_symbol (int) : Le nombre de symbole
    
    - Fonction : Applique la gravité vers la gauche, puis rempli les
    cases vides

    - Retour : La grille après les opérations de gravité de 
    remplissage
    -----------------------------------------------------------------*/
  
  // -- Calcul le nombre de cases à remplir pour appliquer la gravité vers la gauche
  for (int i = width - 1; i >= 0; i--) {
    for (int j = 0; j < length - 1; j++) {
      if (grid[i][j] == ' ') {
        int k = j + 1;
        while (k < length && grid[i][k] == ' ') {
          k++; 
        }
        
        if (k < length) {
          grid[i][j] = grid[i][k];
          grid[i][k] = ' ';
        }
        
      }
      
    }
    
  }

  // -- Remplissage des cases vides
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < length; j++) {
      if (grid[i][j] == ' ') {
        grid[i][j] = Symbol[rand() % nmbr_of_symbol];
      }
      
    }
    
  }
  
  return grid;
}

