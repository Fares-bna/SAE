#pragma once
#define NB_LETTRES 22

// D?finition des constantes avec enum
enum {
    TAILLE_PIOCHE = 88,  // Nombre total de lettres dans la pioche
};



/**
 * @brief Mélange les caractères de la pioche de manière aléatoire.
 * @param[in,out] pioche Un pointeur vers la chaîne de caractères représentant la pioche.
 * @pre La pioche doit être une chaîne de caractères allouée et remplie de manière valide,
 * avec au moins TAILLE_PIOCHE caractères.
 **/

void melangerPioche(char* pioche);

/**
 * @brief Initialise la pioche avec les lettres du jeu en fonction de leurs fréquences.
 * @param[out] pioche Un pointeur vers la chaîne de caractères représentant la pioche à initialiser.
 * @pre
 * - La pioche doit être un tableau alloué avec au moins `TAILLE_PIOCHE` caractères.
 * - La taille des tableaux `lettresJeu` et `frequencesJeu` doit être égale à `NB_LETTRES`.
 */

void initialiser_Pioche(char* pioche);


/**
 * @brief Remet une lettre dans la pioche et mélange celle-ci.
 *
 * @param[in] delete Caractère représentant la lettre à remettre dans la pioche.
 * @param[in, out] pioche Pointeur vers le tableau de caractères représentant la pioche.
 *                        La lettre est ajoutée et la pioche est mélangée après modification.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, qui est incrémentée après l'ajout de la lettre.
 */
void remettre_pioche(char delete, char* pioche, int* taille_pioche);