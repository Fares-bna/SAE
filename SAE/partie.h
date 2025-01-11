#pragma once


#include "joueur.h"
#include "rail.h"

typedef struct {
    char* pioche;
    Joueur joueur1;
    Joueur joueur2;
    Rails rail;
} Partie;


void initialiserPartie(Partie* jeu);
void ajouter_mot(Partie* jeu, Joueur* joueur_act);
