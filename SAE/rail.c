#pragma warning(disable:4996)
#include "partie.h"
#include "joueur.h"
#include "pioche.h"
#include "dictionnaire.h"
#include "rail.h"

void inverserRail(Rails* rail_jeu) {



    // Boucle pour inverser les caract�res du recto dans le verso
    for (int i = 0; i < MAX_RAIL; ++i) {
        rail_jeu->verso[i] = rail_jeu->recto[(MAX_RAIL - 1) - i];
    }

    // Ajout du caract�re nul � la fin de la cha�ne verso
    rail_jeu->verso[(MAX_RAIL)] = '\0';

    // Affichage du r�sultat
    printf("V : %s\n", rail_jeu->verso);
}

void initRail(Joueur* joueur1, Joueur* joueur2, Rails* rail_jeu) {
    // Si le premier mot est plus proche de A (ordre alphab�tique) que le second
    // alors le rail est compos� du premier mot suivi du deuxi�me
    if (strcmp(joueur1->mot_initial, joueur2->mot_initial) < 0) {
        strncpy(rail_jeu->recto, joueur1->mot_initial, MAX_RAIL);
        strncat(rail_jeu->recto, joueur2->mot_initial, MAX_RAIL - strlen(rail_jeu->recto));
    }
    // Sinon, inversement
    if (strcmp(joueur1->mot_initial, joueur2->mot_initial) > 0) {
        strncpy(rail_jeu->recto, joueur2->mot_initial, MAX_RAIL);
        strncat(rail_jeu->recto, joueur1->mot_initial, MAX_RAIL - strlen(rail_jeu->recto));
    }

    // Ajout du caract�re nul � la fin de recto si n�cessaire
    rail_jeu->recto[MAX_RAIL] = '\0';

    printf("R : %s\n", rail_jeu->recto);
    inverserRail(rail_jeu);
}

void ajouter_mot(Partie* jeu) {
    char cote = "";
    char mot[MAX_RAIL];
    do {
        scanf('%c', cote);
    } while (!strcmp(cote, 'R') == 0 || !strcmp(cote, 'V') == 0);

    if (strcmp(cote, 'R') == 0) {
        scanf("(%c)", mot);
        //ici utiliser strncpy / strcst selon la mm logique que initRail
    }

    if (strcmp(cote, 'R') == 0) {

    }

}