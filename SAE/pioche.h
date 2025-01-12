#pragma once
#define NB_LETTRES 22

// D?finition des constantes avec enum
enum {
    TAILLE_PIOCHE = 88,  // Nombre total de lettres dans la pioche
};



/**
 * @brief M�lange les caract�res de la pioche de mani�re al�atoire.
 * @param[in,out] pioche Un pointeur vers la cha�ne de caract�res repr�sentant la pioche.
 * @pre La pioche doit �tre une cha�ne de caract�res allou�e et remplie de mani�re valide,
 * avec au moins TAILLE_PIOCHE caract�res.
 **/

void melangerPioche(char* pioche);

/**
 * @brief Initialise la pioche avec les lettres du jeu en fonction de leurs fr�quences.
 * @param[out] pioche Un pointeur vers la cha�ne de caract�res repr�sentant la pioche � initialiser.
 * @pre
 * - La pioche doit �tre un tableau allou� avec au moins `TAILLE_PIOCHE` caract�res.
 * - La taille des tableaux `lettresJeu` et `frequencesJeu` doit �tre �gale � `NB_LETTRES`.
 */

void initialiser_Pioche(char* pioche);


/**
 * @brief Remet une lettre dans la pioche et m�lange celle-ci.
 *
 * @param[in] delete Caract�re repr�sentant la lettre � remettre dans la pioche.
 * @param[in, out] pioche Pointeur vers le tableau de caract�res repr�sentant la pioche.
 *                        La lettre est ajout�e et la pioche est m�lang�e apr�s modification.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, qui est incr�ment�e apr�s l'ajout de la lettre.
 */
void remettre_pioche(char delete, char* pioche, int* taille_pioche);