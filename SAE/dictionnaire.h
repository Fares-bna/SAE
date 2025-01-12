#pragma once

#include <stdbool.h>




/**
 * @brief Vérifie si un mot existe dans le dictionnaire.
 *
 * @param[in] mot Le mot à vérifier dans le dictionnaire.
 *
 * @return `true` si le mot est trouvé dans le dictionnaire, sinon `false`.
 *
 * @pre `mot` doit être une chaîne de caractères valide à vérifier dans le dictionnaire.
 * @pre Le fichier "ods4.txt" doit exister et être lisible.
 */
bool verifDico(const char* mot);