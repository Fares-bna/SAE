#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define TAILLE_MAXMOTS 5
#define TAILLE_MAIN 12

typedef struct {
    int NoJoueur;
    char main_joueur[TAILLE_MAIN];
    char mot_initial[TAILLE_MAXMOTS];
} Joueur;


void modifier_Main(const char* mot, char* main);
bool verifier_mot(Joueur* joueur_act);
void demanderMot(Joueur* joueur_act);
void creation_joueur(char* pioche, Joueur* joueur_act, int* nbJoueur, int* taille_pioche, const int taille_main);
void ranger_main(Joueur* joueur_act, int taille_main, int taille_mot);
void tirer_main(char* pioche, Joueur* joueur_act, int* taille_pioche);
void affiche_main(Joueur* joueur_act, int taille_main);
void trier_et_afficher_main(Joueur* joueur_act, const int taille_main);
void adapter_main(const char* mot_ajt, char* mot_suprime, Joueur* joueur_concerne, int taille_main);
void seulementTrierMain(Joueur* joueur_act, const int taille_main);




