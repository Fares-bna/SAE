#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include "rail.h" // Nécessaire pour la structure Rails et les fonctions associées


//a enlever 


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


bool separer_mots(const char* mot_entier, char* mot_rail, char* mot_main) {
    // Chercher l'indice de la première parenthèse ouvrante et fermante
    char* debut = strchr(mot_entier, '(');
    char* fin = strchr(mot_entier, ')');

    // Vérifier que les parenthèses existent et que leur ordre est correct
    if (debut == NULL || fin == NULL || debut >= fin) {
        return false;  // Pas de parenthèses ou ordre invalide
    }

    // Si la parenthèse est avant le mot principal
    if (debut == mot_entier) {
        // Copier le mot entre les parenthèses dans mot_rail
        strncpy(mot_rail, debut + 1, fin - debut - 1);
        mot_rail[fin - debut - 1] = '\0';  // Assurez-vous que mot_rail est bien terminé

        // Copier le mot après la parenthèse dans mot_main
        strcpy(mot_main, fin + 1);
    }
    // Si la parenthèse est après le mot principal
    else {
        // Copier le mot avant la parenthèse dans mot_main
        strncpy(mot_main, mot_entier, debut - mot_entier);
        mot_main[debut - mot_entier] = '\0';  // Assurez-vous que mot_main est bien terminé

        // Copier le mot entre les parenthèses dans mot_rail
        strncpy(mot_rail, debut + 1, fin - debut - 1);
        mot_rail[fin - debut - 1] = '\0';  // Assurez-vous que mot_rail est bien terminé
    }

    return true;  // Séparation réussie
}

char cote_rail(const char* mot) {

    if (mot[0] == '(') {
        return 'D';
    }
    return 'G';
}

bool verifier_main(char* mot, const char* mot_main, Joueur* joueur_act) {
    int temoin = 0;

    simplifier(mot);
    if (!verifDico(mot)) {
        return false;
    }

    if (strlen(mot_main) >= TAILLE_MAXMOTS) {
        return false;
    }

    for (int i = 0; i < strlen(mot_main); ++i) { //On parcours l'entiereté du mot entré, jusqu'arriver au caractère nul

        for (int j = 0; j < TAILLE_MAIN; ++j) { //Pour chaque lettre, on regarde l'entièreté de la main du joueur..

            if (mot_main[i] == joueur_act->main_joueur[j]) { //Si la lettre du mot correspond à une lettre du chevalet, on incrémente la valeur témoin et on continue la boucle
                ++temoin;
                break;
            }
        }

    }




    if (temoin == (strlen(mot_main))) {

        modifier_Main(mot_main, &joueur_act->main_joueur);
        ranger_main(joueur_act, strlen(joueur_act->main_joueur), strlen(mot_main));

        return true;
    }

    return false;
}


//Pour le recto
bool verifier_introduction(Rails* rail_act, Joueur* joueur_act, const char* mot, char* mot_rail, char* mot_main, const char cote) {

    if (strlen(mot) < 2 && strlen(mot) > 4) {
        return false;
    }



    if (cote == 'R') {




        if (cote_rail(mot) == 'G') {

            if (!separer_mots(mot, mot_rail, mot_main)) {
                return false;
            }


            int temoin = 0;

            for (int i = 0; i < strlen(mot_rail); ++i) {
                if (mot_rail[i] == rail_act->recto[i]) {
                    ++temoin;
                }
            }

            if (temoin == strlen(mot_rail)) {
                return verifier_main(mot, mot_main, joueur_act);

            }

        }
    

        if (cote_rail(mot) == 'D') {

            if (!separer_mots(mot, mot_rail, mot_main)) {
                return false;
            }

            int temoin = 0;
            int index = 0;

            for (int i = strlen(rail_act->recto) - 1; i > (strlen(rail_act->recto) - strlen(mot_rail)) - 1; --i) {
                if (mot_rail[strlen(mot_rail) - 1 - index] == rail_act->recto[i]) {
                    ++temoin;
                }  ++index;
            }

            if (temoin == strlen(mot_rail)){
                return verifier_main(mot, mot_main, joueur_act);
            }

        }

    }
    if (cote == 'V') {




        if (cote_rail(mot) == 'G') {

            if (!separer_mots(mot, mot_rail, mot_main)) {
                return false;
            }


            int temoin = 0;

            for (int i = 0; i < strlen(mot_rail); ++i) {
                if (mot_rail[i] == rail_act->verso[i]) {
                    ++temoin;
                }
            }
            if (temoin == strlen(mot_rail)) {
                return verifier_main(mot, mot_main, joueur_act);
            }

        }


        if (cote_rail(mot) == 'D') {

            if (!separer_mots(mot, mot_rail, mot_main)) {
                return false;
            }

            int temoin = 0;
            int index = 0;

            for (int i = strlen(rail_act->verso) - 1; i > (strlen(rail_act->verso) - strlen(mot_rail)) - 1; --i) {
                if (mot_rail[strlen(mot_rail) - 1 - index] == rail_act->verso[i]) {
                    ++temoin;
                }  ++index;
            }

            if (temoin == strlen(mot_rail)) {
                return verifier_main(mot, mot_main, joueur_act);
            }

        }

    }
    
    
    return false;


}








  