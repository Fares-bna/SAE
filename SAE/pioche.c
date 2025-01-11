#include <stdio.h>
#include <stdlib.h>
#include "pioche.h"   // Pour les constantes et fonctions li�es � la pioche




void melangerPioche(char* pioche) {
    for (int i = TAILLE_PIOCHE - 1; i > 0; i--) { // Parcourir de taille_pioche - 1 � 1
        int j = rand() % (i + 1); // G�n�rer un indice al�atoire valide
        // �changer les caract�res entre les positions i et j
        char temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;

    }
}

void initialiser_Pioche(char* pioche) {

    char lettresJeu[NB_LETTRES] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int frequencesJeu[NB_LETTRES] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };
    int somme = 0;

    for (int i = 0; i < NB_LETTRES; ++i) {
        for (int j = somme; j < frequencesJeu[i] + somme; ++j) {
            pioche[j] = lettresJeu[i];

        }
        somme += frequencesJeu[i];

    }

    melangerPioche(pioche);
}






