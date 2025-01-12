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




/**
 * @brief Met à jour l'affichage du jeu en fonction des actions effectuées par les joueurs.
 *
 * Cette fonction détermine la direction du rail à partir de la mémoire de l'action précédente (`memoire`),
 * puis appelle `gerer_rail()` pour mettre à jour le rail et l'état des joueurs.
 *
 * @param[in, out] rail Pointeur vers la structure `Rails` représentant l'état du rail du jeu.
 *                      Le rail est mis à jour après l'action.
 * @param[in, out] joueur_act Pointeur vers le joueur actif dont la main peut être modifiée.
 * @param[in, out] joueur_adverse Pointeur vers le joueur adverse, qui peut être affecté par l'action.
 * @param[in, out] mot_main Pointeur vers le mot joué par le joueur actif, mis à jour après l'ajout sur le rail.
 * @param[in, out] mot_rail Pointeur vers le mot actuellement présent sur le rail, qui peut être modifié.
 * @param[in] cote Caractère indiquant le côté du rail concerné ('R' pour recto, 'V' pour verso).
 * @param[in, out] taille_main_adv Pointeur vers la taille de la main du joueur adverse, qui peut être mise à jour.
 * @param[in] taille_main_act Taille de la main du joueur actif.
 * @param[in] memoire Pointeur vers une chaîne de caractères représentant l'action en mémoire.
 * @param[in, out] pioche Pointeur vers la pioche du jeu, qui peut être modifiée en cas d'ajout ou de retrait de lettres.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, mise à jour si nécessaire.

 */
void affichage_correct(Rails* rail, Joueur* joueur_act, Joueur* joueur_adverse,
    char* mot_main, char* mot_rail, char cote,
    int* taille_main_adv, int taille_main_act,
    char* memoire, char* pioche, int* taille_pioche);


/**
 * @brief Initialise une partie de jeu, incluant la pioche, les joueurs et le rail.
 * @param[in,out] jeu Un pointeur vers la structure Partie qui sera initialisée.
 * @pre La structure Partie doit être allouée avant l'appel de cette fonction.
 **/

void initialiserPartie(Partie* jeu);



/**
  * @brief
 * Cette fonction permet au joueur actif d'introduire un mot sur le rail en suivant les règles du jeu.
 * Elle gère également l'affichage des joueurs, la possibilité d'échanger une lettre,
 * et met à jour les états des joueurs et du rail après validation.
 *
 * @param[in, out] rail Pointeur vers la structure `Rails` représentant le rail du jeu.
 * Il est mis à jour après l'ajout du mot.
 * @param[in, out] joueur_act Pointeur vers le joueur actif, dont la main peut être modifiée.
 * @param[in, out] joueur_adverse Pointeur vers le joueur adverse, qui peut être affecté par l'ajout du mot.
 * @param[in, out] pioche Pointeur vers le tableau représentant la pioche, modifié en cas d'échange de lettre.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, mise à jour si nécessaire.
 *
 * @pre Les structures Rails, Joueur (joueur_act et joueur_adverse) doivent être correctement initialisées.
**/


void ajouter_mot(Rails* rail, Joueur* joueur_act, Joueur* joueur_adverse);