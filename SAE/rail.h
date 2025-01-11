#pragma once

#define MAX_RAIL 8
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char recto[MAX_RAIL];
	char verso[MAX_RAIL];
} Rails;



/**
*@brief Une fonction permettant de v�rifier l'ordre alphab�tique des deux mots afin de cr�er le recto du rail
*@param[in] joueur1->mot_initial Le  mot entr� par le premier joueur
*@param[in] joueur2->mot_initial Le  mot entr� par le deuxi�me joueur
*@param[out] rail Le rail, prenant ici la valeur des deux mots mis c�te � c�te (respectant l'ordre alphab�tique)
*/