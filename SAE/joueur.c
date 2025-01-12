
#pragma warning(disable:4996)
#include <stdio.h>     // Pour les entr�es/sorties standard
#include <stdbool.h>   // Pour le type bool
#include <string.h>    // Pour les manipulations de cha�nes
#include "joueur.h"    // N�cessaire pour la structure Joueur et les fonctions associ�es
#include "dictionnaire.h"

void tirer_main(char* pioche, Joueur* joueur_act, int* taille_pioche) {

    for (int i = 0; i < TAILLE_MAIN; ++i) {
        joueur_act->main_joueur[i] = pioche[*taille_pioche - i - 1];

    }
    joueur_act->main_joueur[TAILLE_MAIN] = '\0';
    *taille_pioche -= TAILLE_MAIN; 
}
void modifier_Main(const char* mot, char* main) {

    for (int i = 0; i < strlen(mot); i++) {
        for (int j = 0; j < strlen(main); j++)
        {
            if (mot[i] == main[j]) {
                main[j] = '0';
                break;
            }

        }


    }

}
bool verifier_mot(Joueur* joueur_act) {
    int temoin = 0;

    if (strlen(joueur_act->mot_initial) != 4) {
        return false;
    }
    char temp[TAILLE_MAIN];

    strncpy(temp, joueur_act->main_joueur, TAILLE_MAIN);
    for (int i = 0; i < strlen(joueur_act->mot_initial); ++i) { //On parcours l'entiereté du mot entré, jusqu'arriver au caractère nul

        for (int j = 0; j < TAILLE_MAIN; ++j) { //Pour chaque lettre, on regarde l'entièreté de la main du joueur..

            if (joueur_act->mot_initial[i] == joueur_act->main_joueur[j]) { //Si la lettre du mot correspond à une lettre du chevalet, on incrémente la valeur témoin et on continue la boucle
                
                if (temp[j] != '0') {
                    temp[j] = '0';
                    ++temoin;
                    break;
                }

                
            }
        }

    }

    if (temoin == (TAILLE_MAXMOTS - 1)) {
       
        strncpy(joueur_act->main_joueur, temp, TAILLE_MAIN);
        
        return true;
    }

    return false;
}
void affiche_main(Joueur* joueur_act, int taille_main) {

    taille_main = strlen(joueur_act->main_joueur);
    printf("%d : ", joueur_act->NoJoueur);
    for (int i = 0; i < taille_main; ++i) {
        printf("%c", joueur_act->main_joueur[i]);  // Affiche chaque lettre dans la main
    }
    printf("\n");
}


//a simplifier / modifier l'appel de la fonction trier et afficher et garder seulement celle la
void seulementTrierMain(Joueur* joueur_act, const int taille_main) {

    for (int i = 0; i < taille_main - 1; i++) {
        for (int j = i + 1; j < taille_main; j++) {
            if (joueur_act->main_joueur[i] > joueur_act->main_joueur[j]) {
                char temp = joueur_act->main_joueur[i];
                joueur_act->main_joueur[i] = joueur_act->main_joueur[j];
                joueur_act->main_joueur[j] = temp;
            }
        }
    }
  
}
void trier_et_afficher_main(Joueur* joueur_act, const int taille_main) {

    for (int i = 0; i < taille_main - 1; i++) {
        for (int j = i + 1; j < taille_main; j++) {
            if (joueur_act->main_joueur[i] > joueur_act->main_joueur[j]) {
                char temp = joueur_act->main_joueur[i];
                joueur_act->main_joueur[i] = joueur_act->main_joueur[j];
                joueur_act->main_joueur[j] = temp;
            }
        }
    }

    affiche_main(joueur_act, taille_main);
}



void creation_joueur(char* pioche, Joueur* joueur_act, int* nbJoueur, int* taille_pioche, const int taille_main) {



    joueur_act->NoJoueur = *nbJoueur;
    joueur_act->main_joueur = (char*)calloc(TAILLE_MAIN, sizeof(char));

    tirer_main(pioche, joueur_act, taille_pioche);
    trier_et_afficher_main(joueur_act, taille_main);
    ++(*nbJoueur);


}

void demanderMot(Joueur* joueur_act) {

    do {
        
        printf("%d> ", joueur_act->NoJoueur);
        scanf(" %s", joueur_act->mot_initial);
        
      
    } while (!verifDico(&joueur_act->mot_initial));

}

void ranger_main(Joueur* joueur_act, int taille_main, int taille_mot) {
 
    int index = 0; // Indice pour les lettres non-nulles
    for (int i = 0; i < taille_main; i++) {
        if (joueur_act->main_joueur[i] != '0') { // Si la lettre n'est pas un '0'
            joueur_act->main_joueur[index] = joueur_act->main_joueur[i]; // Déplace la lettre
            if (index != i) {
                joueur_act->main_joueur[i] = '0'; // Remplace l'ancienne position par '0'
            }
            index++; // Incrémente l'indice pour la prochaine lettre valide
        }
    }



    if (index != taille_main) {
        // Remplir le reste avec '0' jusqu'à la fin, seulement si index est inférieur à taille_main
        for (int i = taille_main - taille_mot; i < taille_main; ++i) {
            joueur_act->main_joueur[i] = '\0'; // Remplir le reste avec '0'
        }
    }

    
}



void adapter_main(char* mot_ajt, const char* referentiel, Joueur* joueur_concerne, int* taille_main) {
    
    
    // On calcule la nouvelle taille totale de la main
    
    int nouvelle_taille = *taille_main + strlen(referentiel);
    // Réallocation de la mémoire pour la nouvelle taille
    joueur_concerne->main_joueur = (char*)realloc(joueur_concerne->main_joueur, nouvelle_taille * sizeof(char));

    // Vérification de la réallocation
    

    // Ajouter les lettres du mot ajouté (mot_ajt) à la fin de la main
    for (int i = *taille_main; i < nouvelle_taille; ++i) {
        joueur_concerne->main_joueur[i] = mot_ajt[i - *taille_main]; // Copie du mot ajouté
    }

    joueur_concerne->main_joueur[nouvelle_taille] = '\0';

    // Mettre à jour la taille de la main du joueur
    *taille_main = nouvelle_taille;
    joueur_concerne->main_joueur;

    // Trier la main (si nécessaire)

    int long_mot = strlen(referentiel);
    seulementTrierMain(joueur_concerne, *taille_main);
    ranger_main(joueur_concerne, nouvelle_taille, long_mot);
}




