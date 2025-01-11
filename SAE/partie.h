#pragma once


#include "joueur.h"
#include "rail.h"
#include "pioche.h"

typedef struct {
    char* pioche;
    Joueur joueur1;
    Joueur joueur2;
    Rails rail;
} Partie;

void initialiserPartie(Partie* jeu);

