#pragma once

#include <stdbool.h>




/**
 * @brief V�rifie si un mot existe dans le dictionnaire.
 *
 * @param[in] mot Le mot � v�rifier dans le dictionnaire.
 *
 * @return `true` si le mot est trouv� dans le dictionnaire, sinon `false`.
 *
 * @pre `mot` doit �tre une cha�ne de caract�res valide � v�rifier dans le dictionnaire.
 * @pre Le fichier "ods4.txt" doit exister et �tre lisible.
 */
bool verifDico(const char* mot);