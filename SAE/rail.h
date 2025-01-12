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



/**
 * @brief Inverse les caractères du rail recto pour remplir le rail verso.
 * @param[in,out] rail_jeu Un pointeur vers la structure `Rails` contenant les rails recto et verso.
 * @pre
 * - Le tableau `recto` doit être une chaîne de caractères valide,
 *   avec une taille maximale de `MAX_RAIL`.
 * - La structure `Rails` doit être allouée et initialisée avant l'appel.
 */

void inverserRail(Rails* rail_jeu);

/**
 * @brief Inverse le contenu du verso d'un rail et l'affecte au recto.
 *
 * @param[in, out] rail_jeu Pointeur vers la structure `Rails` contenant les rails du jeu. Le champ `recto` est modifié après l'inversion du `verso`.
 *
 * @pre `rail_jeu` doit être un pointeur valide vers une structure `Rails` correctement initialisée.
 * @pre `verso` doit contenir une chaîne valide d'une longueur maximale de `MAX_RAIL`.
 * @pre `recto` doit avoir une taille suffisante pour stocker l'inversion de `verso`.
 *
 */
void inverserRail_VR(Rails* rail_jeu);


/**
 * @brief
 * Cette fonction parcourt la chaîne `mot` et enlève tous les caractères '(' et ')',
 * en décalant les caractères restants pour compacter la chaîne.
 *
 * @param[in, out] mot Pointeur vers la chaîne de caractères à simplifier.
 *La modification est effectuée directement sur cette chaîne.
 */
void simplifier(char* mot);



/**
 * @brief Initialise le rail recto en combinant les mots initiaux des deux joueurs.
 *
 * @param[in] joueur1 Un pointeur vers le premier joueur, contenant son mot initial.
 * @param[in] joueur2 Un pointeur vers le second joueur, contenant son mot initial.
 * @param[in,out] rail_jeu Un pointeur vers la structure `Rails` à initialiser.

 * @pre
 * - Les pointeurs `joueur1`, `joueur2` et `rail_jeu` doivent être valides et non nuls.
 */

void initRail(Joueur* joueur1, Joueur* joueur2, Rails* rail_jeu);

/**
 * @brief Supprime les parenthèses d'une chaîne de caractères.
 * @param[in,out] mot Une chaîne de caractères à simplifier.
 *                    La chaîne est modifiée directement en supprimant tous les caractères '(' et ')'.
 * @pre
 * - `mot` doit être une chaîne valide terminée par `\0`.
 */

void simplifier(char* mot);

/**
 * @brief Sépare un mot en deux parties selon les parenthèses : le mot dans les parenthèses va dans mot_rail et le reste dans mot_main.
 * Cette fonction recherche les parenthèses dans un mot donné et sépare le mot en deux parties :
 * - Le mot entre les parenthèses est copié dans `mot_rail`.
 * - Le mot en dehors des parenthèses est copié dans `mot_main`.
 * @param[in] mot_entier Le mot entier contenant des parenthèses, à séparer.
 * @param[out] mot_rail La partie du mot entre les parenthèses, qui sera stockée ici.
 * @param[out] mot_main La partie du mot en dehors des parenthèses, qui sera stockée ici.

 * @return true Si la séparation du mot a été réalisée avec succès.
 * @return false Si les parenthèses sont mal placées ou absentes, rendant la séparation impossible.
 *
 * @pre `mot_entier` doit contenir au moins une parenthèse ouvrante et une parenthèse fermante.
 */

bool separer_mots(const char* mot_entier, char* mot_rail, char* mot_main);

/**
 * @brief Détermine de quel côté du rail un mot se trouve, en fonction de sa première parenthèse.
 * Cette fonction vérifie si le mot commence par une parenthèse ouvrante `(`. Si c'est le cas, cela signifie
 * que le mot est sur le côté droit du rail (indiqué par 'D'). Sinon, il est sur le côté gauche (indiqué par 'G').
 *
 * @param[in] mot Le mot à analyser pour déterminer son côté.
 *
 * @return 'D' Si le mot commence par une parenthèse ouvrante, indiquant le côté droit du rail.
 * @return 'G' Si le mot ne commence pas par une parenthèse ouvrante, indiquant le côté gauche du rail.
 *
 * @pre `mot` doit être une chaîne de caractères valide et non vide.
 */
char cote_rail(const char* mot);

/**
 * @brief Vérifie si un mot peut être joué en utilisant les lettres de la main du joueur.
 *
 * @param[in] mot Le mot à vérifier (avant modification et simplification).
 * @param[in] mot_main Le mot joué, potentiellement modifié.
 * @param[in,out] joueur_act Le joueur dont la main sera modifiée si le mot est validé.
 *
 * @return `true` Si le mot est valide, autrement `false`.
 *
 * @pre `mot` doit être une chaîne de caractères non vide.
 * @pre `mot_main` doit être une chaîne de caractères non vide et ne pas dépasser la taille maximale autorisée pour un mot.
 */
bool verifier_main(char* mot, const char* mot_main, Joueur* joueur_act);

/**
 * @brief Vérifie si un mot peut être introduit sur un rail par un joueur.
 *
 * @param[in] rail_act Le rail sur lequel le mot est introduit. Il contient les chaînes `recto`
 * et `verso` représentant respectivement le côté recto et verso du rail.
 * @param[in] joueur_act Le joueur qui joue le mot. Il contient la main du joueur avec les lettres disponibles.
 * @param[in] mot Le mot que le joueur souhaite jouer. Il est vérifié pour sa longueur et sa validité.
 * @param[in] mot_rail Le mot à placer sur le rail. Il est séparé du mot du joueur et doit correspondre
 * à la chaîne sur le rail.
 * @param[in] mot_main La main du joueur. Elle contient les lettres disponibles pour jouer le mot.
 * @param[in] cote Le côté du rail sur lequel le mot est introduit. 'R' pour recto, 'V' pour verso.
 * @return `true` Si le mot peut être validé et joué sur le rail, autrement `false`.
 *
 * @pre `mot` doit être une chaîne de caractères non vide.
 * @pre `mot_rail` doit être une chaîne de caractères non vide et correspondre aux lettres du rail.
 * @pre `mot_main` doit être une chaîne de caractères non vide et contenir des lettres valides du joueur.
 * @pre `cote` doit être un caractère valant 'R' ou 'V', représentant respectivement le recto ou le verso du rail.
 */

bool verifier_introduction(Rails* rail_act, Joueur* joueur_act, const char* mot, char* mot_rail, char* mot_main, const char cote);

/**
 * @brief Vérifie si un mot a une longueur de 8 caractères et s'il est valide selon le dictionnaire.

 *
 * @param[in] mot Pointeur vers la chaîne de caractères représentant le mot à vérifier.
 * @param[in] mot_rail Pointeur vers le mot actuellement présent sur le rail (non utilisé ici).
 * @param[in] mot_main Pointeur vers les lettres disponibles dans la main du joueur (non utilisé ici).
 *
 * @return `true` si le mot contient exactement 8 lettres et est valide selon `verifDico()`, `false` sinon.
 *
 * @pre `mot` doit être un pointeur valide vers une chaîne de caractères non nulle.
 * @pre La fonction `simplifier(mot)` doit être correctement définie et appliquée avant la vérification.
 * @pre La fonction `verifDico(mot)` doit être disponible et retourner `true` si le mot est valide.
 */
bool verifier_octo(char* mot, char* mot_rail, char* mot_main);

/**
 * @brief Modifie le rail droit en insérant un mot et en ajustant la main du joueur adverse.
 *
 * @param[in, out] rail_act Pointeur vers le rail à modifier.
 * @param[in, out] joueur_adv Pointeur vers le joueur adverse dont la main est ajustée.
 * @param[in] mot_main Chaîne de caractères représentant le mot à insérer.
 * @param[in] cote Caractère indiquant le côté du rail concerné ('r' ou 'v').
 * @param[in, out] taille_main Pointeur vers la taille de la main du joueur adverse, mise à jour après l'insertion.
 *
 * @pre `rail_act` doit être un pointeur valide vers une structure `Rails` correctement initialisée.
 * @pre `joueur_adv` doit être un pointeur valide vers une structure `Joueur` correctement initialisée.
 * @pre `mot_main` doit être une chaîne de caractères valide et conforme aux règles du jeu.
 * @pre `taille_main` doit être un pointeur valide indiquant la taille actuelle de la main du joueur adverse.
 */
void adapter_railDroit(Rails* rail_act, Joueur* joueur_adv, char* mot_main, const char cote, int* taille_main);

/**
 * @brief Modifie le rail gauche en insérant un mot et en ajustant la main du joueur adverse.
 *
 * @param[in, out] rail_act Pointeur vers le rail à modifier.
 * @param[in, out] joueur_adv Pointeur vers le joueur adverse dont la main est ajustée.
 * @param[in] mot_main Chaîne de caractères représentant le mot à insérer.
 * @param[in] cote Caractère indiquant le côté du rail concerné ('r' ou 'v').
 * @param[in, out] taille_main Pointeur vers la taille de la main du joueur adverse, mise à jour après l'insertion.
 *
 * @pre `rail_act` doit être un pointeur valide vers une structure `Rails` correctement initialisée.
 * @pre `joueur_adv` doit être un pointeur valide vers une structure `Joueur` correctement initialisée.
 * @pre `mot_main` doit être une chaîne de caractères valide et conforme aux règles du jeu.
 * @pre `taille_main` doit être un pointeur valide indiquant la taille actuelle de la main du joueur adverse.
 */
void adapter_railGauche(Rails* rail_act, Joueur* joueur_adv, char* mot_main, const char cote, int* taille_main);

/**
 * @brief Affiche la main des joueurs ainsi que l'état du rail après inversion si nécessaire.
 *
 * @param[in] joueur1 Pointeur vers le premier joueur.
 * @param[in] taille1 Taille de la main du premier joueur.
 * @param[in] joueur2 Pointeur vers le second joueur.
 * @param[in] taille2 Taille de la main du second joueur.
 * @param[in] cote Caractère indiquant le côté du rail concerné ('r' ou 'v').
 * @param[in] rail Pointeur vers le rail du jeu.
 *
 * @pre `joueur1` et `joueur2` doivent être des pointeurs valides vers des structures `Joueur` correctement initialisées.
 * @pre `rail` doit être un pointeur valide vers une structure `Rails` correctement initialisée.
 * @pre `taille1` et `taille2` doivent être supérieurs ou égaux à zéro.
 */
void afficher_main_et_rail(Joueur* joueur1, int taille1, Joueur* joueur2, int taille2, char cote, Rails* rail);

/**
 * @brief Gère la mise à jour d'un rail (gauche ou droit) en fonction du mouvement du joueur.
 *
 * @param[in] direction Caractère indiquant la direction du rail ('g' pour gauche, 'd' pour droit).
 * @param[in, out] rail Pointeur vers le rail à modifier.
 * @param[in, out] joueur_act Pointeur vers le joueur actif dont la main est mise à jour.
 * @param[in, out] joueur_adverse Pointeur vers le joueur adverse dont la main peut être ajustée.
 * @param[in, out] mot_main Chaîne représentant le mot joué par le joueur actif.
 * @param[in] mot_rail Chaîne représentant le mot actuellement présent sur le rail.
 * @param[in] cote Caractère indiquant le côté du rail concerné ('r' ou 'v').
 * @param[in, out] taille_main_adv Pointeur vers la taille de la main du joueur adverse, mise à jour si nécessaire.
 * @param[in] taille_main_act Taille de la main du joueur actif.
 * @param[in, out] memoire Pointeur vers une mémoire temporaire utilisée dans la gestion du rail.
 * @param[in, out] pioche Pointeur vers la pioche du jeu, qui peut être modifiée après l'action.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, mise à jour si nécessaire.
 *
 * @pre `rail` doit être un pointeur valide vers une structure `Rails` correctement initialisée.
 * @pre `joueur_act` et `joueur_adverse` doivent être des pointeurs valides vers des structures `Joueur` correctement initialisées.
 * @pre `mot_main` et `mot_rail` doivent être des chaînes de caractères valides conformes aux règles du jeu.
 * @pre `taille_main_adv` et `taille_pioche` doivent être des pointeurs valides.
 * @pre `taille_main_act` doit être supérieur ou égal à zéro.
 * @pre `memoire` et `pioche` doivent être des pointeurs valides vers des zones mémoire correctement allouées.
 */
void gerer_rail(char direction, Rails* rail, Joueur* joueur_act, Joueur* joueur_adverse, char* mot_main,
    char* mot_rail, char cote, int* taille_main_adv, int taille_main_act,
    char* memoire, char* pioche, int* taille_pioche);
