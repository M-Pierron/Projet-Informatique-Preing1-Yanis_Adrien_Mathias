#ifndef HEADER_H
#define HEADER_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SYMBOLMIN 4
#define SYMBOLMAX 6
extern char Symbol[SYMBOLMAX];

// -- Mouvements
char **mooveCase(char **tab, int i1, int i2, int j1, int j2);
char **gravity(char **grid, int length, int width, int nmbr_of_symbol);

// -- Verifications
int check_align(char **grid, int length, int width);
int check_possibility(char **grid, int length, int width);

// -- Supression
char **vertical(char **grid, int length, int width, int i, int j,int *pscore);
char **horizontal(char **grid, int length, int width, int i, int j,int *pscore);
char **clearsymbol(char **grid, int length, int width,int *pscore);

// -- Affichage
void showemoji(char **tab, int i , int j);
void ShowTab(char **tab, int length, int width);

#endif