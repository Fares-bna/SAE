#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define TAILLE_MAXMOTS 5
#define TAILLE_MAIN 12

typedef struct {
    int NoJoueur;
    char* main_joueur;
    char mot_initial[TAILLE_MAXMOTS];
} Joueur;



/**
 * @brief  Cette fonction permet de tirer des lettres de la pioche et de les attribuer à un joueur,
 * en les plaçant dans la main du joueur. Elle met également à jour la taille restante de la pioche.
 *
 * @param[in,out] pioche La pioche contenant les lettres disponibles. Après le tirage, les lettres
 * seront retirées de la pioche.
 * @param[in,out] joueur_act Le joueur auquel les lettres sont distribuées. Sa main est mise à jour.
 * @param[in,out] taille_pioche Le nombre de lettres restantes dans la pioche. Ce nombre est mis à jour
 * après le tirage en soustrayant le nombre de lettres distribuées.
 *
 * @pre `pioche` doit être un tableau de caractères représentant la pioche contenant les lettres disponibles.
 * @pre `joueur_act` doit être un pointeur vers un joueur ayant une main pouvant accueillir les lettres tirées.
 * @pre `taille_pioche` doit être un pointeur vers un entier représentant le nombre de lettres restantes dans la pioche.
 */

void tirer_main(char* pioche, Joueur* joueur_act, int* taille_pioche);


/**
 * @brief Modifie la main d'un joueur après qu'il ait joué un mot.
 *
 * Cette fonction parcourt le mot joué par le joueur et, pour chaque lettre du mot, elle marque cette lettre
 * comme utilisée dans la main du joueur en la remplaçant par un caractère spécial ('0').
 *
 * @param[in] mot Le mot joué par le joueur. Ce mot est utilisé pour identifier les lettres à supprimer de la main.
 * @param[in,out] main La main du joueur. Les lettres présentes dans `mot` seront remplacées par '0' dans cette main.
 *
 * @pre `mot` doit être une chaîne de caractères non vide.
 * @pre `main` doit être une chaîne de caractères représentant la main du joueur.
 */

void modifier_Main(const char* mot, char* main);

/**
 * @brief Vérifie si le mot joué par un joueur peut être formé avec les lettres de sa main.
 *
 * @param[in,out] joueur_act Le joueur dont le mot est vérifié et dont la main sera modifiée si le mot est valide.
 *
 * @return `true` Si le mot est valide et peut être joué avec les lettres de la main du joueur, autrement `false`.
 *
 * @pre `joueur_act->mot_initial` doit être une chaîne de caractères non vide et de longueur exacte égale à 4.
 * @pre `joueur_act->main_joueur` doit être une chaîne de caractères non vide de taille maximale `TAILLE_MAIN`.
 */

bool verifier_mot(Joueur* joueur_act);

/**
 * @brief Affiche la main d'un joueur, c'est-à-dire les lettres qu'il possède actuellement.

 * @param[in] joueur_act Le joueur dont la main est affichée. Son identifiant et les lettres de sa main seront utilisées.
 * @param[in] taille_main La taille actuelle de la main du joueur, indiquant combien de lettres afficher.
 *
 * @pre `joueur_act->main_joueur` doit être une chaîne de caractères valide représentant la main du joueur.
 * @pre `taille_main` doit être un entier représentant la taille de la main du joueur.
 */

void affiche_main(Joueur* joueur_act, int taille_main);


/**
 * @brief Trie les lettres de la main d'un joueur par ordre alphabétique croissant.

 * @param[in,out] joueur_act Le joueur dont la main sera triée. Sa main (`main_joueur`) sera modifiée en place.
 * @param[in] taille_main La taille actuelle de la main du joueur. Elle détermine combien de lettres doivent être triées.
 *
 * @pre `joueur_act->main_joueur` doit être une chaîne de caractères valide représentant la main du joueur.
 * @pre `taille_main` doit être un entier représentant la taille de la main du joueur.
 */

void seulementTrierMain(Joueur* joueur_act, const int taille_main);


/**
 * @brief Trie les lettres de la main d'un joueur par ordre alphabétique (algorithme du tri à bulles) et affiche ensuite la main triée.
 *
 * @param[in,out] joueur_act Le joueur dont la main sera triée et affichée. Sa main (`main_joueur`) sera modifiée en place.
 * @param[in] taille_main La taille actuelle de la main du joueur. Elle détermine combien de lettres doivent être triées.
 *
 * @pre `joueur_act->main_joueur` doit être une chaîne de caractères valide représentant la main du joueur.
 * @pre `taille_main` doit être un entier représentant la taille de la main du joueur.
 */

void trier_et_afficher_main(Joueur* joueur_act, const int taille_main);

/**
 * @brief
 * Cette fonction initialise un joueur en lui attribuant un numéro unique basé sur le nombre de joueurs existants,
 * tire une main de lettres à partir de la pioche et affiche la main du joueur triée par ordre alphabétique.
 *
 * @param[in,out] pioche La pioche de lettres. La fonction tirera les lettres nécessaires pour la main du joueur et modifiera la taille de la pioche.
 * @param[in,out] joueur_act Le joueur à créer. Sa main (`main_joueur`) sera remplie et triée, et son numéro de joueur (`NoJoueur`) sera attribué.
 * @param[in,out] nbJoueur Le nombre actuel de joueurs. Ce nombre sera utilisé pour attribuer un numéro unique au nouveau joueur, puis sera incrémenté.
 * @param[in,out] taille_pioche La taille actuelle de la pioche. Elle sera modifiée au fur et à mesure des tirages de lettres.
 * @param[in] taille_main La taille de la main à attribuer au joueur.
 *
 * @pre `pioche` doit être une chaîne de caractères représentant la pioche de lettres disponible.
 * @pre `joueur_act` doit être un pointeur valide sur une structure `Joueur` vide.
 * @pre `nbJoueur` doit être un pointeur valide contenant le nombre de joueurs actuel.
 * @pre `taille_pioche` doit être un pointeur valide représentant la taille actuelle de la pioche.
 * @pre `taille_main` doit être un entier valide représentant la taille de la main du joueur.
 */


void creation_joueur(char* pioche, Joueur* joueur_act, int* nbJoueur, int* taille_pioche, const int taille_main);


/**

 *@brief Cette fonction invite le joueur à entrer un mot, puis vérifie si ce mot est valide en utilisant la fonction `verifDico`.
 * Si le mot n'est pas valide, le joueur est invité à entrer un autre mot jusqu'à ce qu'un mot valide soit fourni.
 *
 * @param[in,out] joueur_act Le joueur qui doit entrer un mot. Le mot saisi sera stocké dans le champ `mot_initial` de la structure `Joueur`.
 *
 * @pre `joueur_act` doit être un pointeur valide vers une structure `Joueur` qui contient un champ `mot_initial` pour stocker le mot saisi
 */
void demanderMot(Joueur* joueur_act);

/**
 * @brief Réorganise les lettres dans la main d'un joueur en déplaçant les lettres non-nulles à la première position disponible.
 *
 * @param[in,out] joueur_act Le joueur dont la main est modifiée. Les lettres non-nulles dans `main_joueur` sont déplacées.
 * @param[in] taille_main La taille totale de la main du joueur.
 * @param[in] taille_mot La taille du mot joué, utilisé pour limiter les déplacements.
 *
 * @pre `joueur_act` doit être un pointeur valide vers une structure `Joueur` qui contient un champ `main_joueur` pour représenter la main du joueur.
 * @pre `taille_main` doit être un entier représentant la taille de la main du joueur.
 */
void ranger_main(Joueur* joueur_act, int taille_main, int taille_mot);

/**
 * @brief  Cette fonction permet d'ajouter un mot à la main du joueur en fin de chaîne et d'ajuster la main du joueur
 * en réorganisant les lettres, tout en prenant en compte la nouvelle taille de la main après l'ajout.
 *
 * @param[in] mot_ajt Le mot à ajouter à la main du joueur.
 * @param[in] mot_suprime Le mot supprimé de la main (non utilisé dans cette fonction mais peut être destiné à un autre aspect du jeu).
 * @param[in,out] joueur_concerne Le joueur dont la main est modifiée. La main du joueur sera mise à jour avec le mot ajouté.
 * @param[in] taille_main La taille actuelle de la main du joueur avant l'ajout du mot.
 *
 * @pre `mot_ajt` doit être une chaîne de caractères valide représentant un mot à ajouter à la main du joueur.
 * @pre `joueur_concerne` doit être un pointeur valide vers une structure `Joueur` contenant un champ `main_joueur` pour représenter la main du joueur.
 * @pre `taille_main` doit être la taille actuelle de la main du joueur avant l'ajout du mot.
 */

void adapter_main(char* mot_ajt, const char* referentiel, Joueur* joueur_concerne, int* taille_main);

/**
 * @brief Permet à un joueur d'échanger une lettre de sa main avec une lettre aléatoire de la pioche.
 *
 * @param[in, out] joueur_act Pointeur vers le joueur actif dont une lettre de la main sera échangée.
 * @param[in] taille_main Taille de la main du joueur actif.
 * @param[in, out] pioche Pointeur vers le tableau représentant la pioche.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, qui ne change pas ici.
 * @param[in] signe Caractère représentant une condition ou une option pour l'échange (non utilisé dans la version actuelle).
 *
 * @return `true` si l'échange a eu lieu avec succès, `false` sinon.
 *
 */
bool echanger_lettre(Joueur* joueur_act, int taille_main, char* pioche, int* taille_pioche, char signe);

/**
 * @brief Supprime une lettre de la main d'un joueur et la remet dans la pioche.

 * @param[in, out] joueur_act Pointeur vers le joueur actif dont une lettre doit être supprimée.
 * La main du joueur est modifiée après la suppression.
 * @param[in] taille_main Taille de la main du joueur (nombre de lettres).
 * @param[in, out] pioche Tableau représentant la pioche du jeu, qui est modifiée après la suppression.
 * @param[in, out] taille_pioche Pointeur vers la taille actuelle de la pioche, qui sera mise à jour après la suppression.
 *
 * @pre `joueur_act` doit être un pointeur valide vers une structure `Joueur` correctement initialisée.
 * @pre `taille_main` doit être supérieur à 0 et correspondre à la taille effective de la main du joueur.
 * @pre `pioche` doit être un tableau valide contenant les lettres restantes en jeu.
 * @pre `taille_pioche` doit être un pointeur valide indiquant la taille actuelle de la pioche.
 * @pre La main du joueur doit contenir au moins une lettre pour que la suppression soit possible.
 */
void supprimer_lettre(Joueur* joueur_act, int taille_main, char* pioche, int* taille_pioche);
