#pragma once
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"

#define MAX_RAIL 8
#define QTE_PARENTHESES 2

typedef struct {
    char recto[MAX_RAIL + 1];
    char verso[MAX_RAIL + 1];
} Rails;

void inverserRail(Rails* rail_jeu);
void initRail(Joueur* joueur1, Joueur* joueur2, Rails* rail_jeu);
void simplifier(char* mot);
bool separer_mots(const char* mot_entier, char* mot_rail, char* mot_main);
char cote_rail(const char* mot);
bool verifier_main(char* mot, const char* mot_main, Joueur* joueur_act);
bool verifier_introduction(Rails* rail_act, Joueur* joueur_act, const char* mot, char* mot_rail, char* mot_main, const char cote);