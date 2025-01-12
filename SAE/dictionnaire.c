#pragma warning(disable : 4996)
#define MAX_LIGNE 28 //Le nombre maximum de lettre dans le plus long mot du dictionnaire de la langue fran?aise (+1)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "dictionnaire.h"

bool verifDico(const char* mot) {



    FILE* dico = fopen("ods4.txt", "r");
    if (dico == NULL) {
        printf("Le dictionnaire est introuvable\n");
        return false;
    }
    char ligne[MAX_LIGNE];
    // Lire le fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), dico)) {
        
        ligne[strcspn(ligne, "\n")] = '\0'; // Supprime le saut de ligne pour pouvoir comparer la ligne avec le mot
        // Comparer directement la ligne avec le mot
        if (strcmp(ligne, mot) == 0) {
            fclose(dico);  // Fermer le fichier apr?s avoir trouv? le mot
            return true;  // Le mot a ?t? trouv?
        }
    }

    fclose(dico);  // Fermer le fichier si le mot n'est pas trouv?
    return false;
}



