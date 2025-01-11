#pragma once
#include "joueur.h"

#define NB_LETTRES 22

// Définition des constantes avec enum
typedef enum {
    TAILLE_PIOCHE = 88,  // Nombre total de lettres dans la pioche
    TAILLE_MAIN = 12     // Nombre de lettres dans la main d'un joueur
} Constantes;

void melangerPioche(char* pioche);
void initialiser_Pioche(char* pioche);
void tirer_main(char* pioche, Joueur* joueur_act, int* taille_pioche);
void affiche_main(Joueur* joueur_act, int taille_main);
void trier_et_afficher_main(Joueur* joueur_act);


