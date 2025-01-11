#include <stdio.h>
#include <stdlib.h>
#include "partie.h"  // Nécessaire pour la structure Partie et la fonction initialiserPartie



int main() {
    // Déclaration et initialisation de la partie
    Partie jeu;

    // Initialisation des composants de la partie
    initialiserPartie(&jeu);

    printf("La partie Octo-Verso a été initialisée avec succès !\n");

    return 0;
}


