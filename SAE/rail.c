#pragma warning(disable:4996)
#include "partie.h"
#include "joueur.h"
#include "pioche.h"
#include "dictionnaire.h"
#include "rail.h"

//a enlever 
#define MAX_

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

void simplifier(char* mot) {
    int j = 0; // Index pour le résultat
    for (int i = 0; mot[i] != '\0'; i++) {
        // Copier uniquement les caractères qui ne sont pas des parenthèses
        if (mot[i] != '(' && mot[i] != ')') {
            mot[j++] = mot[i];  // Modifier directement le tableau 'mot'
        }
    }
    mot[j] = '\0'; // Ajouter le caractère nul à la fin
}

//Pour le recto
bool verifier_introduction(Rails* rail, const char* mot, const char cote) {
    
    if (strlen(mot) < 2 && strlen(mot) > 4) {
        return false;
    }

    if (cote == 'R') {
        int temoin = 0;
        printf("%d", strlen(mot));
        for (int i = 0; i < strlen(mot); ++i) {
            if (mot[i] == rail->recto[i]) {
                ++temoin;
            }
        }
        return temoin == strlen(mot);

    }

    if (cote == 'V') {
        int temoin = 0;
        int index = 0;
        
        for (int i = strlen(rail->verso) - 1; i > (strlen(rail->verso) - strlen(mot)) - 1; --i) {
            if (mot[strlen(mot) - 1 - index] == rail->verso[i]) {
                ++temoin; 
            }  ++index;
        }

        return temoin == strlen(mot);

    }


    return false;


}



void ajouter_mot(Partie* jeu, Joueur* joueur_act) {
    char cote = '\0';
    char mot_rail[MAX_RAIL] = "";
    do {



        do {
            printf("%d> ", joueur_act->NoJoueur);
            scanf(" %c", &cote);
        } while (cote != 'R' && cote != 'V');

        scanf(" (%s)", mot_rail);
        simplifier(mot_rail);

    } while (verifier_introduction(&jeu->rail, mot_rail, cote));
}

  