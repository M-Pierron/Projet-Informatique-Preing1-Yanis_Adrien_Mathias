README - Candy Crush Saga 
-------------------------
Auteurs : Yanis, Adrien, Mathias


__Description__ :

Jeu de type "match 3" sur terminal. Le but est d'aligner les symboles pour marquer des points.


__Comment jouer__ :

1. Compiler le Makefile
2. Vous serez invité à continuer une partie existante ou à en commencer une nouvelle.
   - Si vous choisissez de continuer une partie existante, le programme chargera la partie à partir d'un fichier sauvegardé.
   - Si vous choisissez de commencer une nouvelle partie, on vous demandera d'entrer votre nom d'utilisateur et les paramètres du jeu (dimensions de la grille et nombre de symboles).
3. La grille de jeu sera affichée, montrant des symboles représentés par des caractères.
4. Vous pouvez continuer à jouer tant qu'il reste des mouvements possibles.
5. À chaque tour, on vous demandera si vous souhaitez continuer ou quitter le jeu.
   - Si vous choisissez de continuer, on vous demandera d'entrer les coordonnées de deux symboles à échanger.
   - Le programme vérifiera si l'échange crée des alignements. Si oui, ces symboles alignés seront supprimés et de nouveaux symboles tomberont pour remplir les espaces vides.
   - Si aucun alignement n'est créé, vous serez informé que les symboles sélectionnés ne peuvent pas être échangés.
6. Le jeu se poursuivra jusqu'à ce qu'il n'y ait plus de mouvements possibles.
7. À la fin du jeu, votre score sera affiché, ainsi que les scores de tous les joueurs.
8. Les scores seront enregistrés dans le fichier "file_score.txt".


__Liste des fichiers__ :

- Makefile.txt : Permet de compiler le programme.
- candy.c : Fonction main().
- check.c : Fonctions pour effectuer toutes les vérifications (check_align() et check_possibility()).
- header.h : Fichier header, qui rassemble et declare toutes les fonctions.
- movement.c : Fonctions de deplacelements et d'application de gravité (mooveCase() et gravity()).
- show.c : Fonctions d'affichage dans le terminal (showemoji() et showTab()).
- symbol.c : Fonctions de supressions des symboles alignés (vertical(), horizontal() et clearsymbol()).
- file_score.txt : Fichier rassemblant tous les scores des joueurs.
- save.txt : Fichier de sauvegarde d'une partie arretée. 


Amusez-vous bien !
