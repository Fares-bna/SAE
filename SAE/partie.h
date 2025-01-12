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
 * @brief Met � jour l'affichage du jeu en fonction des actions effectu�es par les joueurs.
 *
 * Cette fonction d�termine la direction du rail � partir de la m�moire de l'action pr�c�dente (`memoire`),
 * puis appelle `gerer_rail()` pour mettre � jour le rail et l'�tat des joueurs.
 *
 * @param[in, out] rail Pointeur vers la structure `Rails` repr�sentant l'�tat du rail du jeu.
 *                      Le rail est mis � jour apr�s l'action.
 * @param[in, out] joueur_act Pointeur vers le joueur actif dont la main peut �tre modifi�e.
 * @param[in, out] joueur_adverse Pointeur vers le joueur adverse, qui peut �tre affect� par l'action.
 * @param[in, out] mot_main Pointeur vers le mot jou� par le joueur actif, mis � jour apr�s l'ajout sur le rail.
 * @param[in, out] mot_rail Pointeur vers le mot actuellement pr�sent sur le rail, qui peut �tre modifi�.
 * @param[in] cote Caract�re indiquant le c�t� du rail concern� ('R' pour recto, 'V' pour verso).
 * @param[in, out] taille_main_adv Pointeur vers la taille de la main du joueur adverse, qui peut �tre mise � jour.
 * @param[in] taille_main_act Taille de la main du joueur actif.
 * @param[in] memoire Pointeur vers une cha�ne de caract�res repr�sentant l'action en m�moire.
 * @param[in, out] pioche Pointeur vers la pioche du jeu, qui peut �tre modifi�e en cas d'ajout ou de retrait de lettres.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, mise � jour si n�cessaire.

 */
void affichage_correct(Rails* rail, Joueur* joueur_act, Joueur* joueur_adverse,
    char* mot_main, char* mot_rail, char cote,
    int* taille_main_adv, int taille_main_act,
    char* memoire, char* pioche, int* taille_pioche);


/**
 * @brief Initialise une partie de jeu, incluant la pioche, les joueurs et le rail.
 * @param[in,out] jeu Un pointeur vers la structure Partie qui sera initialis�e.
 * @pre La structure Partie doit �tre allou�e avant l'appel de cette fonction.
 **/

void initialiserPartie(Partie* jeu);



/**
  * @brief
 * Cette fonction permet au joueur actif d'introduire un mot sur le rail en suivant les r�gles du jeu.
 * Elle g�re �galement l'affichage des joueurs, la possibilit� d'�changer une lettre,
 * et met � jour les �tats des joueurs et du rail apr�s validation.
 *
 * @param[in, out] rail Pointeur vers la structure `Rails` repr�sentant le rail du jeu.
 * Il est mis � jour apr�s l'ajout du mot.
 * @param[in, out] joueur_act Pointeur vers le joueur actif, dont la main peut �tre modifi�e.
 * @param[in, out] joueur_adverse Pointeur vers le joueur adverse, qui peut �tre affect� par l'ajout du mot.
 * @param[in, out] pioche Pointeur vers le tableau repr�sentant la pioche, modifi� en cas d'�change de lettre.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, mise � jour si n�cessaire.
 *
 * @pre Les structures Rails, Joueur (joueur_act et joueur_adverse) doivent �tre correctement initialis�es.
**/


void ajouter_mot(Rails* rail, Joueur* joueur_act, Joueur* joueur_adverse);