#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "partie.h"
#include "pioche.h"


void affichage_correct(Rails* rail, Joueur* joueur_act, Joueur* joueur_adverse, char* mot_main, char* mot_rail, char cote, int* taille_main_adv, int taille_main_act, char* memoire) {
    char direction = cote_rail(memoire);
    gerer_rail(direction, rail, joueur_act, joueur_adverse, mot_main, mot_rail, cote, taille_main_adv, taille_main_act, memoire);
}

void ajouter_mot(Rails* rail, Joueur* joueur_act, Joueur* joueur_adverse) {
    char cote = '\0';
    char mot_entier[MAX_RAIL + QTE_PARENTHESES] = "";
    char memoire[MAX_RAIL + QTE_PARENTHESES];
    char mot_rail[TAILLE_MAXMOTS - 1];
    char mot_main[TAILLE_MAXMOTS - 1];

    //pour la fin
    char ancien_rail_recto[MAX_RAIL - 1];
    char ancien_rail_verso[MAX_RAIL - 1];

    do {



        do {
            printf("%d> ", joueur_act->NoJoueur);
            scanf(" %c", &cote);
            scanf(" %s", mot_entier);

            strcpy(memoire, mot_entier);

        } while (cote != 'R' && cote != 'V');




    } while (!verifier_introduction(rail, joueur_act, mot_entier, &mot_rail, &mot_main, cote));

    int taille_main_adv = strlen(joueur_adverse->main_joueur);
    int taille_main_act = strlen(joueur_act->main_joueur);

    assert(cote_rail(memoire) == 'G' || cote_rail(memoire) == 'D');

    //affiche les joueurs en fonction de leur numero

    affichage_correct(rail, joueur_act, joueur_adverse, mot_main, mot_rail, cote, &taille_main_adv, taille_main_act, memoire);
    
    
    if (verifier_octo(memoire, &mot_rail, &mot_main)) {
        supprimer_lettre(joueur_act, &taille_main_act);
    }


}

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

    creation_joueur(jeu->pioche, &jeu->joueur1, &nbrJoueur, &taille_pioche, TAILLE_MAIN);
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




  /*if (cote_rail(memoire) == 'D') {

        if (cote == 'R') {



            if (joueur_act->NoJoueur == 1)
            {
                adapter_railGauche(rail, joueur_adverse, mot_main, cote, &taille_main_adv);
                affiche_main(joueur_act, taille_main_act);
                affiche_main(joueur_adverse, taille_main_adv);
                printf("R : %s\n", rail->recto);
                inverserRail(rail);


            }

            else
            {
                adapter_railGauche(rail, joueur_adverse, mot_main, cote, &taille_main_adv);
                affiche_main(joueur_adverse, taille_main_adv);
                affiche_main(joueur_act, taille_main_act);
                printf("R : %s\n", rail->recto);
                inverserRail(rail);
            }

        }

        if (cote == 'V') {



            if (joueur_act->NoJoueur == 1)
            {
                adapter_railGauche(rail, joueur_adverse, mot_main, cote, &taille_main_adv);
                affiche_main(joueur_act, taille_main_act);
                affiche_main(joueur_adverse, taille_main_adv);
               
                inverserRail_VR(rail);
                printf("V : %s\n", rail->verso);

            }

            else
            {
                adapter_railGauche(rail, joueur_adverse, mot_main, cote, &taille_main_adv);
                affiche_main(joueur_adverse, taille_main_adv);
                affiche_main(joueur_act, taille_main_act);

                inverserRail_VR(rail);
                printf("V : %s\n", rail->verso);
            }

        }

    }



    

    if (cote_rail(memoire) == 'G')
    {
        if (cote == 'R') {



            if (joueur_act->NoJoueur == 1)
            {
                adapter_railDroit(rail, joueur_adverse, mot_main, cote, &taille_main_adv);
                affiche_main(joueur_act, taille_main_act);
                affiche_main(joueur_adverse, taille_main_adv);
                
                printf("R : %s\n", rail->recto);
                inverserRail(rail);


            }

            else
           
            {

                
                adapter_railDroit(rail, joueur_adverse, mot_main, cote, &taille_main_adv);
                affiche_main(joueur_adverse, taille_main_adv);
                affiche_main(joueur_act, taille_main_act);
                printf("R : %s\n", rail->recto);
                inverserRail(rail);
            }

        }

        if (cote == 'V') {



            if (joueur_act->NoJoueur == 1)
            {
                adapter_railDroit(rail, joueur_adverse, mot_main, cote, &taille_main_adv);
                affiche_main(joueur_act, taille_main_act);
                affiche_main(joueur_adverse, taille_main_adv);

                printf("je suis la");
                inverserRail_VR(rail);
                printf("V : %s\n", rail->verso);


            }

            else
            {
                adapter_railDroit(rail, joueur_adverse, mot_main, cote, &taille_main_adv);
                affiche_main(joueur_adverse, taille_main_adv);
                affiche_main(joueur_act, taille_main_act);

                inverserRail_VR(rail);
                printf("V : %s\n", rail->verso);
            }

        }

    }

}


*/






   
  


