#pragma warning(disable : 4996)
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

    creation_joueur(jeu->pioche, &jeu->joueur1, &nbrJoueur, &taille_pioche,TAILLE_MAIN);
    creation_joueur(jeu->pioche, &jeu->joueur2, &nbrJoueur, &taille_pioche, TAILLE_MAIN);

    do {
        demanderMot(&jeu->joueur1);
    } while (!verifier_mot(&jeu->joueur1));
 

    do {
        demanderMot(&jeu->joueur2);
    } while (strcmp(jeu->joueur1.mot_initial, jeu->joueur2.mot_initial) == 0 || !verifier_mot(&jeu->joueur2));


    ranger_main(&jeu->joueur1, TAILLE_MAIN, TAILLE_MAXMOTS-1);
    affiche_main(&jeu->joueur1, TAILLE_MAIN - (TAILLE_MAXMOTS - 1));
    ranger_main(&jeu->joueur2, TAILLE_MAIN, TAILLE_MAXMOTS-1);
    affiche_main(&jeu->joueur2, TAILLE_MAIN - (TAILLE_MAXMOTS - 1));

    initRail(&jeu->joueur1, &jeu->joueur2, &jeu->rail);
    ajouter_mot(&jeu->rail, &jeu->joueur1, &jeu->joueur2);
    ajouter_mot(&jeu->rail, &jeu->joueur2,&jeu->joueur1);
}
void ajouter_mot(Rails* rail, Joueur* joueur_act, Joueur* joueur_adverse) {
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

    int taille_main_adv = strlen(joueur_adverse->main_joueur);
    int taille_main_act = strlen(joueur_act->main_joueur);
    
    adapter_main(mot_entier, mot_main, joueur_adverse, &taille_main_adv);


    //affiche les joueurs en fonction de leur numero
    if (joueur_act->NoJoueur == 1) {
        affiche_main(joueur_act, taille_main_act);
        affiche_main(joueur_adverse, taille_main_adv);
    }
    else {
        affiche_main(joueur_adverse, taille_main_adv);
        affiche_main(joueur_act, taille_main_act);
    }

}



