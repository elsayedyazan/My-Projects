#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h> 

typedef struct {
    char** mots;
    int nbMots;
    int capacite;
} Mots;

enum {
   // pour COMPO_LETTRES_DEPART
     A = 9
    ,B = 1
    ,C = 2
    ,D = 3
    ,E = 14
    ,F = 1
    ,G = 1
    ,H = 1
    ,I = 7
    ,J = 1
    ,K = 5
    ,L = 3
    ,M = 6
    ,N = 0
    ,O = 5
    ,P = 2
    ,Q = 1
    ,R = 6
    ,S = 7
    ,T = 6
    ,U = 5
    ,V = 2
    ,W = 0
    ,X = 0
    ,Y = 0
    ,Z = 0 
};


/**
 * @brief Initialise la structure contenant des mots .
 * @param[in] mots La structure contenant les mots qui seront joués à initialiser.
 * @param[in] m Premier mot à ajouter.
 */
void initMots(Mots* m, const char* mot, int capacite);

/**
 * @brief Ajoute un mot à une structure les mots si celui-ci n'a pas déjà été utilisé.
 * @param[in] m La structure contenant les mots déjà utilisés.
 * @param[in] mot Le mot à ajouter.
 * @return 1 si le mot a bien été ajouté, 0 sinon.
 */
int ajouterMot(Mots* m, const char* mot);

/**
 * @brief Verifie si un mot a déjà été joué.
 * @param[in] m La structure contenant des mots à traiter.
 * @param[in] mot Le mot à verifier.
 * @return 1 si le mot a déjà été joué , 0 sinon.
 */
int MotConnu(const Mots* m, const char* mot);

/**
 * @brief Libère toute la mémoire allouée dans la structure Mots et réinitialise ses champs.
 * @param[in/out] m Pointeur vers la structure Mots à détruire.
 *
 * @note Après l'appel à cette fonction, le tableau de mots sera vide et `m->mots` sera
 *       mis à NULL, tandis que `m->nbMots` sera réinitialisé à 0.
 */
void detruireMots(Mots* m);

/**
 * @brief Teste les fonctions spécifiques au composant Mots.
 */
void testMots();