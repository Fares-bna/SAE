
// joueur.c

#pragma warning (disable : 4996)
#include "pioche.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dictionnaire.h"
#include "partie.h"
#include "joueur.h"


void creation_joueur(char* pioche, Joueur* joueur_act, int* nbJoueur, int* taille_pioche) {

    joueur_act->NoJoueur = *nbJoueur;
    tirer_main(pioche, joueur_act, taille_pioche);
    trier_et_afficher_main(joueur_act);

    ++(*nbJoueur);


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
        strcpy(joueur_act->main_joueur, temp);
        modifier_Main(joueur_act->mot_initial, &joueur_act->main_joueur);
        return true;
    }

    return false;
}


void demanderMot(Joueur* joueur_act) {
    char mot[TAILLE_MAXMOTS];

    do {
        printf("%d> ", joueur_act->NoJoueur);
        scanf("%s", joueur_act->mot_initial );
      


        
    } while (!verifDico(joueur_act->mot_initial));

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


    // Remplir le reste avec '0'
    for (int i = taille_main - (taille_mot); i < taille_main; i++) {
        joueur_act->main_joueur[i] = '\0';
    }

    
}








