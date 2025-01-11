#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"
#include "pioche.h"

enum { TAILLE_MAXMOTS = 5 };

typedef struct {
	int NoJoueur;
	char main_joueur[TAILLE_MAIN];
	char mot_initial[TAILLE_MAXMOTS];
}Joueur;









