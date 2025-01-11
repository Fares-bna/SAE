﻿#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "partie.h"
#include "pioche.h"






// Fonction pour d�marrer la partie
void initialiserPartie(Partie* jeu) {
    srand(time(NULL));
    int* nbrJoueur = 1;
    int* taille_pioche = TAILLE_PIOCHE;


    jeu->pioche = (char*)malloc(TAILLE_PIOCHE * sizeof(char));
    if (jeu->pioche == NULL) {
        free(jeu->pioche);
    }

    initialiser_Pioche(jeu->pioche);

    creation_joueur(jeu->pioche, &jeu->joueur1, &nbrJoueur, &taille_pioche);
    creation_joueur(jeu->pioche, &jeu->joueur2, &nbrJoueur, &taille_pioche);

    do {
        demanderMot(&jeu->joueur1);
    } while (!verifier_mot(&jeu->joueur1));

   

    do {
        demanderMot(&jeu->joueur2);
    } while (strcmp(jeu->joueur1.mot_initial, jeu->joueur2.mot_initial) == 0 || !verifier_mot(&jeu->joueur2));


    ranger_main(&jeu->joueur1, TAILLE_MAIN, TAILLE_MAXMOTS-1);
    affiche_main(&jeu->joueur1, TAILLE_MAIN - (TAILLE_MAXMOTS - 1));
    ranger_main(&jeu->joueur2, TAILLE_MAIN, TAILLE_MAXMOTS -1);
    affiche_main(&jeu->joueur2, TAILLE_MAIN - (TAILLE_MAXMOTS - 1));

    initRail(&jeu->joueur1, &jeu->joueur2, &jeu->rail);
    ajouter_mot(&jeu->rail, &jeu->joueur1);
    ajouter_mot(&jeu->rail, &jeu->joueur2);
}
void ajouter_mot(Rails* rail, Joueur* joueur_act) {
    char cote = '\0';
    char mot_entier[MAX_RAIL + QTE_PARENTHESES] = "";
    char mot_rail[TAILLE_MAXMOTS - 1];
    char mot_main[TAILLE_MAXMOTS - 1];
    do {



        do {
            printf("%d> ", joueur_act->NoJoueur);
            scanf(" %c", &cote);
            scanf(" %s", mot_entier);

        } while (cote != 'R' && cote != 'V');




    } while (!verifier_introduction(rail, joueur_act, mot_entier, &mot_rail, &mot_main, cote));


}



