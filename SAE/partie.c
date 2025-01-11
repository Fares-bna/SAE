#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include "partie.h"  // Pour la structure Partie et la fonction initialiserPartie
#include "rail.h"    // Pour gérer les rails dans la partie
#include "pioche.h"  // Pour initialiser la pioche dans la partie
#include "joueur.h"  // Pour initialiser les joueurs







// Fonction pour d�marrer la partie
void initialiserPartie(Partie* jeu) {
    srand(time(NULL));
    int* nbrJoueur = 1;
    int taille_pioche = TAILLE_PIOCHE;


    jeu->pioche = (char*)malloc(TAILLE_PIOCHE - 1 * sizeof(char));
    if (jeu->pioche == NULL);
    free(jeu->pioche);

    initialiser_Pioche(&(jeu->pioche));

    creation_joueur(&(jeu->pioche), &(jeu->joueur1), &nbrJoueur, &taille_pioche);
    creation_joueur(&(jeu->pioche), &(jeu->joueur2), &nbrJoueur, &taille_pioche);


    do {
        demanderMot(&jeu->joueur1);
    } while (!verifier_mot(&jeu->joueur1));

    do {
        demanderMot(&jeu->joueur2);
    } while (strcmp(jeu->joueur1.mot_initial, jeu->joueur2.mot_initial) == 0 || !verifier_mot(&jeu->joueur2) );


    ranger_main(&jeu->joueur1, TAILLE_MAIN);
    ranger_main(&jeu->joueur2, TAILLE_MAIN);

    initRail(jeu->joueur1, jeu->joueur2, &jeu->rail);
    ajouter_mot(jeu, jeu->joueur1);
    ajouter_mot(jeu, jeu->joueur2);
}




