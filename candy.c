// -- Headers
#include "header.h"
char Symbol[SYMBOLMAX] = {'A', 'B', 'C', 'D', 'E', 'F'};


int main() {
    srand(time(NULL));
    int length, width, nmbr_of_symbol, i, j, k, i1, i2, j1, j2, resultyes, resultno, score = 0, *pscore = NULL;
    char answer[LENGHT], pseudo[LENGHT], line[LENGHT], savetest[LENGHT] = "save.txt", **grid, **gridinter;
    pscore = &score;

    // -- Intervention du joueur s'il veut recommencer une partie ou non
    do {
        printf("Voulez-vous continuer une partie déjà existante ? Répondez 'oui' ou 'non': ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';
        resultyes = (strcmp(answer, "oui") == 0);
        resultno = (strcmp(answer, "non") == 0);
        // -- Vérification de la réponse
        if (resultno == 0 && resultyes == 0) {
            printf("La réponse est incorrecte, veuillez recommencer.\n");
        }
    } while (resultno == 0 && resultyes == 0);

    FILE *fsavetest = fopen(savetest, "r");
    if (fsavetest != NULL && resultyes) {
        // -- Si le fichier de sauvegarde existe, charger la grille à partir du fichier
        fscanf(fsavetest, "%s", pseudo);
        fscanf(fsavetest, "%d", &score);
        fscanf(fsavetest, "%d %d %d", &length, &width, &nmbr_of_symbol);
        grid = malloc(width * sizeof(char *));
        for (i = 0; i < width; i++) {
            grid[i] = malloc(length * sizeof(char));
            for (j = 0; j < length; j++) {
                fscanf(fsavetest, " %c", &grid[i][j]);
            }
        }

        fclose(fsavetest);
        remove(savetest);
    }
    else {
        remove(savetest);
        printf("Veuillez rentrer votre pseudo : ");
        fgets(pseudo, sizeof(pseudo), stdin);
        pseudo[strcspn(pseudo, "\n")] = '\0';
        // -- Demande à l'utilisateur les paramètres du jeu
        do {
            printf("Rentrez les dimensions de la grille (MxN) et le nombre de symbole (entre 4 et 6) : ");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%d %d %d", &length, &width, &nmbr_of_symbol);

            // -- Vérification de la réponse
            if ((length <= 4) || (width <= 4) || (length > 50) || (width > 25) || (nmbr_of_symbol < SYMBOLMIN) || (nmbr_of_symbol > SYMBOLMAX)) {
                printf("Les valeurs sont incorrectes, veuillez recommencer.\n");
            }
        } while ((length <= 4) || (width <= 4) || (length > 50) || (width > 25) || (nmbr_of_symbol < SYMBOLMIN) || (nmbr_of_symbol > SYMBOLMAX));

        // -- Initialisation de la grille et sa construction
        grid = malloc(width * sizeof(char *));
        for (i = 0; i < width; i++) {
            grid[i] = malloc(length * sizeof(char));
            for (j = 0; j < length; j++) {
                grid[i][j] = Symbol[rand() % nmbr_of_symbol];
            }
        }

        while (check_align(grid, length, width) != 0) {
            grid = clearsymbol(grid, length, width, pscore);
            grid = gravity(grid, length, width, nmbr_of_symbol);
        }
        score = 0;
    }


  // -- Le lancement du jeu en lui-même
  do {
    system("clear");
    // -- Affichage de la grille avec la numerotation adequate
    ShowTab(grid, length, width);
    printf("Votre score est maintenant de %d\n", score);
    
    // -- Intervention du joueur s'il veut continuer la partie ou non
    do {
        printf("Voulez-vous continuer ? Répondez 'oui' ou 'non': ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';
        resultyes = (strcmp(answer, "oui") == 0);
        resultno = (strcmp(answer, "non") == 0);
        // -- Vérification de la réponse
        if (resultno == 0 && resultyes == 0) {
            printf("La réponse est incorrecte, veuillez recommencer.\n");
        }
    } while (resultno == 0 && resultyes == 0);

    // -- Si jamais l'utilisateur veut continuer
    if (resultyes) {
        do {
            do {
                printf("Rentrez les cases à déplacer, en rentrant le numéro de la ligne, puis celui de la colonne : ");
                fgets(line, sizeof(line), stdin);
                sscanf(line, "%d %d %d %d", &i1, &j1, &i2, &j2);

                // -- Vérification de la réponse
                if ((i1 < 1) || (j1 < 1) || (i2 < 1) || (j2 < 1) || (i1 > width) || (j1 > length) || (i2 > width) || (j2 > length)) {
                    printf("Les valeurs sont incorrectes, veuillez recommencer.\n");
                }
            } while ((i1 < 1) || (j1 < 1) || (i2 < 1) || (j2 < 1) || (i1 > width) || (j1 > length) || (i2 > width) || (j2 > length));
            
            gridinter = mooveCase(grid, i1 - 1, i2 - 1, j1 - 1, j2 - 1);

            if (check_align(gridinter, length, width) == 0) {
                printf("Vous ne pouvez pas déplacer ces deux symboles.\n");
            }
        } while (check_align(gridinter, length, width) == 0);
        
        grid = gridinter;
        
        // -- Opérations de suppression et de gravité
        do {
            grid = clearsymbol(grid, length, width, pscore);
            grid = gravity(grid, length, width, nmbr_of_symbol);
        } while (check_align(grid, length, width) != 0);
    }
    // -- Si l'utilisateur veut arrêter et sauvegarder son fichier
    else {
        FILE *save = NULL;
        // -- Création du fichier
        save = fopen("save.txt", "w");
        fprintf(save, "%s\n", pseudo);
        fprintf(save, "%d\n", score);
        fprintf(save, "%d %d %d\n", length, width, nmbr_of_symbol);
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < length; j++) {
                fprintf(save, "%c ", grid[i][j]);
            }
            fprintf(save, "\n");
        }
        fclose(save);
        printf("Partie enregistrée avec succès.\n");
        return 0;
    }
} while (check_possibility(grid, length, width) != 0);

remove(savetest);
printf("Jeu terminé, voici les scores :\n");

// -- Fichier des scores
FILE *addfile = NULL;
// -- Ouverture du fichier en mode ajout
addfile = fopen("file_score.txt", "a");
fprintf(addfile, "%s %d\n", pseudo, *pscore);
fclose(addfile);

FILE *readfile = NULL;
// -- Ouverture du fichier en mode lecture
readfile = fopen("file_score.txt", "r");
while (fgets(line, sizeof(line), readfile) != NULL) {
    printf("%s", line);
}
fclose(readfile);

return 0;
}
