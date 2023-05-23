#include "header.h"

int check_align(char **grid, int length, int width) {
  /*-----------------------------------------------------------------
    - Parametres :  - grid (char**) : La grille de jeu
                    - length (int) : La longueur de la grille
                    - widht (int) : La largeur de la grille
    
    - Fonction : Vérifie si des alignements de 3 symboles existent

    - Retour : 1 s'il y a un alignement, 0 sinon
    -----------------------------------------------------------------*/
  
  int i, j;
  // -- Vérifie l'alignement horizontal des symboles
  for (i = 0; i < width; i++) {
    for (j = 1; j < length - 1; j++) {
      if (grid[i][j-1] == grid[i][j] && grid[i][j+1] == grid[i][j]) {
        return 1;
      }
      
      // -- Vérification des symboles alignés horizontalementaux aux extrémités Est et Ouest du tableau
      if ((j == 1 || j == length - 2) && grid[i][j] == grid[i][0] &&
        grid[i][j] == grid[i][length - 1]) {
        return 1;
      }
      
    }
    
  }
  
  // -- Vérifie l'alignement verticale des symboles
  for (j = 0; j < length; j++) {
    for (i = 1; i < width - 1; i++) {
      if (grid[i-1][j] == grid[i][j] && grid[i+1][j] == grid[i][j]) {
        return 1;
      }
      
      // -- Vérifiacation des symboles alignés en verticales aux extrémités Nord et Sud du tableau
      if ((i == 1 || i == width - 2) && grid[i][j] == grid[0][j] &&
        grid[i][j] == grid[width - 1][j]) {
        return 1;
      }
      
    }
    
  }
  
  return 0;
}

int check_possibility(char **grid, int length, int width) {
  /*-----------------------------------------------------------------
    - Parametres :  - grid (char**) : La grille de jeu
                    - length (int) : La longueur de la grille
                    - widht (int) : La largeur de la grille
    
    - Fonction : Vérifie si des deplacements sont disponibles

    - Retour : 1 s'il y a une disponibilité, 0 sinon
    -----------------------------------------------------------------*/
  
  int i, j,k ,l; 
  // -- Vérifie sur l'horizontale
  for (i = 0; i < width; i++) {
    for (j = 0; j < length - 2; j++) {
      if (grid[i][j] == grid[i][j + 1] || grid[i][j + 1] == grid[i][j + 2]) {
        for (k = 0; k < width; k++) {
          for (l = 0; l < length - 2; l++) {
            if (k != i && (l != j || l!= j+1 || l!= j+2) && grid[k][l] == grid[i][j+1]){
              return 1;
            }
            
          }
          
        }
        
      }
      // -- Les bordures
      if (j == 0 || grid[i][length - 1] == grid[i][j] || grid[i][j] == grid[i][j + 1]) {
        for (k = 0; k < width; k++) {
          for (l = 0; l < length - 2; l++) {
            if (k != i && (l != j || l!= j+1 || l!= j+2) && grid[k][l] == grid[i][length-1]){
              return 1;
            }
            
          }
          
        }
        
      }
      
      if (j == length - 3 || grid[i][0] == grid[i][j + 2] || grid[i][j + 2] == grid[i][j + 1]) {
        for (k = 0; k < width; k++) {
          for (l = 0; l < length - 2; l++) {
            if (k != i && (l != j || l!= j+1 || l!= j+2) && grid[k][l] == grid[i][j+2]){
              return 1;
            }
            
          }
          
        }
        
      }
      
    }
    
  }
  
  // -- Vérifie sur la verticale
  for (j = 0; j < length; j++) {
    for (i = 0; i < width - 2; i++) {
      if (grid[i][j] == grid[i + 1][j] || grid[i + 1][j] == grid[i + 2][j]) {
        for (k = 0; k < width; k++) {
          for (l = 0; l < length - 2; l++) {
            if ((k != i || k!= i+1 || k != i+2) && l != j && grid[k][l] == grid[i + 1][j]){
              return 1;
            }
            
          }
          
        }
        
      }
      
      // -- Les bordures
      if (i == 0 || grid[width - 1][j] == grid[i][j] || grid[i][j] == grid[i + 1][j]) {
        for (k = 0; k < width; k++) {
          for (l = 0; l < length - 2; l++) {
            if ((k != i || k!= i+1 || k != i+2) && l != j && grid[k][l] == grid[width - 1][j]){
              return 1;
            }
            
          }
          
        }
        
      }
      
      if (i == width - 3 || grid[0][j] == grid[i + 2][j] ||  grid[i + 2][j] == grid[i + 1][j]) {
        for (k = 0; k < width; k++) {
          for (l = 0; l < length - 2; l++) {
            if ((k != i || k!= i+1 || k != i+2) && l != j && grid[k][l] == grid[i + 2][j]){
              return 1;
            }
            
          }
          
        }
        
      }
      
    }
    
  }
  
  return 0;
}
