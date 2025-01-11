
// joueur.c

#pragma warning (disable : 4996)
#include "pioche.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "dictionnaire.h"
#include "partie.h"
#include "joueur.h"







bool verifier_mot(Joueur* joueur_act) {
    int temoin = 0;
    if (strlen(joueur_act->mot_initial) != 4) {
        return false;
    }

    for (int i = 0; i < strlen(joueur_act->mot_initial); ++i) { //On parcours l'entiereté du mot entré, jusqu'arriver au caractère nul

        for (int j = 0; j < TAILLE_MAIN; ++j) { //Pour chaque lettre, on regarde l'entièreté de la main du joueur..

            if (joueur_act->mot_initial[i] == joueur_act->main_joueur[j]) { //Si la lettre du mot correspond à une lettre du chevalet, on incrémente la valeur témoin et on continue la boucle
                joueur_act->main_joueur[j] = '0';


                ++temoin;
                break;
            }
        }

    }



    if (temoin == (TAILLE_MAXMOTS - 1)) {

        return true;
    }

    return false;
}


void demanderMot(Joueur* joueur_act) {
    char mot[TAILLE_MAXMOTS];

    do {
        printf("%d> ", joueur_act->NoJoueur);
        scanf("%s", joueur_act->mot_initial);


        //Plante si le mot dépasse les 4 lettres
    } while (!verifDico(joueur_act->mot_initial));

}
void creation_joueur(char* pioche, Joueur* joueur_act, int* nbJoueur, int* taille_pioche) {

    joueur_act->NoJoueur = *nbJoueur;
    tirer_main(pioche, joueur_act, taille_pioche);
    trier_et_afficher_main(joueur_act);

    ++(*nbJoueur);


}


void ranger_main(Joueur* joueur_act, int taille_main) {
    // Index pour les lettres valides

   // Parcours de la main


   // Parcours de la main
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

    // A la fin, tous les '0' sont déjà à la fin, donc la main est déjà correctement réorganisée.



    // Remplir le reste avec '0'
    for (int i = TAILLE_MAIN - (TAILLE_MAXMOTS - 1); i < taille_main; i++) {
        joueur_act->main_joueur[i] = '\0';
    }

    affiche_main(joueur_act, TAILLE_MAIN - (TAILLE_MAXMOTS - 1));
}




/* void modifierMain(char* delete, Joueur* joueur_act, int taille_main) {
    //reserve à deplacer et a continuer
    char* reserve[TAILLE_PIOCHE];
    int taille_reserve = 0;

    for (int i = 0; i < strlen(delete); ++i) { //On parcours l'entiereté du mot entré, jusqu'arriver au caractère nul

        for (int j = 0; j < taille_main; ++j) { //Pour chaque lettre, on regarde l'entièreté de la main du joueur..

            if (delete[i] == joueur_act->main_joueur[j]) { //Si la lettre du mot correspond à une lettre du chevalet, on supprime la lettre du tableau
                joueur_act->main_joueur[taille_reserve] = joueur_act->main_joueur[j];
                ++taille_reserve;
                joueur_act->main_joueur[j] = "\0";
                break;
            }
        }


    }

        for (int i = 0; i < taille_main; ++i) {

              int temoin=0;
                if (joueur_act->main_joueur[i] = "0") {
                    ++temoin;
                }
                taille_main -= temoin;




        }

}

*/








