#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include "vecteur.h"
#include "mots.h"

typedef Vecteur Pioche;

enum { NB_CHEVALETS_DEB = 12, NB_MAX_CHEVALETS = 88, NB_LETTRES_DEPART = 26, NB_LETTRES_MOT = 4, NB_LETTRES_RAIL = 8};
extern const int LETTERS[NB_LETTRES_DEPART];

/**
 * @brief Choisis al�atoirement un chevalet de la pioche.
 * @param[in] COMPO_LETTRES_DEPART La pioche contenant les chevalets.
 * @return Un chevalet de la pioche.
 */
ItemV lettreAleatoire(int* COMPO_LETTRES_DEPART);

/**
 * @brief Initialise le jeu d'un joueur.
 * @param[in,out] j La pioche du joueur.
 * @param[in] nb_chevalets Le nombre de chevalets que devra avoir le joueur.
 * @param[in] COMPO_LETTRES_DEPART La pioche contenant les chevalets.
 */
void initJeu(Pioche* j, int nb_chevalets, int* COMPO_LETTRES_DEPART);

/**
 * @brief Insere un �l�ment dans une pioche. Cet �l�ment est ajout� au bon endroit (garder l'ordre alphab�tique).
 * @param[in,out] f L'adresse de la pioche.
 * @param[in] it L'�l�ment devant �tre ajout�.
 * @return 0 en cas d'�chec (manque de m�moire disponible) et 1 en cas de succ�s.
 */
int inserer(Pioche* f, ItemV it);

/**
 * @brief Affiche les chevalets 
 * @param[in,out] j La pioche du joueur.
 * @param[in] nb_chevalets Le nombre de chevalets que devra avoir le joueur.
 * @param[in] COMPO_LETTRES_DEPART La pioche contenant les chevalets.
 */
void affiche(Pioche* p);

/**
 * @brief Cherche la position d'une lettre dans l'alphabet.
 * @param[in] c La lettre dont on cherche la position.
 * @return L'indice correspondant � la position de la lettre dans l'alphabet.
 */
int indexLettre(char c);

/**
 * @brief V�rifie si un joueur a les lettres necessaires pour former un mot.
 * @param[in] mot Le mot que l'on va v�rifier.
 * @param[in] p Le joueur dont on va acc�der � ses chevalets pour v�rifier si il peut composer le mot.
 * @return 1 si c'est possible de composer le mot et 0 sinon.
 */
int verifMot(char* mot, const Pioche* p);

/**
 * @brief Demande � un joueur de saisir un mot compatbile aux r�gles et ne s'arr�te pas tant que cette condition n'est pas valid�e.
 * @param[in] j Le jeu du joueur qui saisit son mot.
 */
void saisieMot(Pioche* j, Mots* dict, char* mot, int numJoueur, Mots* m);

/**
 * @brief Ajoute le mot saisi par un joueur dans le rail.
 * @param[in] mot Le mot que l'on ajoute au rail.
 * @param[in, out] rail Le rail dans lequel on ajoute le mot saisi.
 */
void ajoute(char* mot, Pioche* rail);

/**
 * @brief Ajoute le mot saisi par un joueur au d�but du rail.
 * @param[in] mot Le mot que l'on ajoute au rail.
 * @param[in, out] rail Le rail dans lequel on ajoute le mot saisi.
 */
void ajouteDeb(char* mot, Pioche* rail);

/**
 * @brief Inverse les lettres pr�senentes sur le rail. 
 * @param[in] j Le jeu du joueur qui saisit son mot.
 */
void inverseRail(Pioche* rail, Pioche* railInverse);

/**
 * @brief Affiche la situation courrante du jeu.
 * @param[in] j1 Le jeu du joueur 1.
 * @param[in] j2 Le jeu du joueur 2.
 * @param[in] r Le rail.
 * @param[in] rI Le rail invers�.
 */
void situation(Pioche* j1, Pioche* j2, Pioche* r, Pioche* rI);

/**
 * @brief V�rifie les lettres aux extr�mit�s d'un rail.
 * @param[in] rail Le rail auquel on verifie l'extr�mit�.
 * @param[in] motExtrait Mot dont on a extirp� les parenth�ses � verifier.
 * @param[in] codeEntre Chiffre indiquant quel cot� du rail  verifier ( 1 = gauche , 2 = droite ).
 * @return 1 si le mot peut bien �tre form� et 0 sinon.
 */
int verifier_lettres_extremite( const Pioche* rail,const char* motExtrait, int codeEntre);

/**
 * @brief Verifie : si le mot et conforme � la longueur max (8),
 * si le mot existe dans le dictionnaire,
 * si le mot a d�j� �t� jou�.
 * @param[in] mot_joue Liste contenant les mots d�ja jou�s.
 * @param[in] motExtrait Mot form� � verifier
 * @param[in] dict Structure contenant le dictionnaire.
 * @return 1 si le mot est conforme � toutes les conditions et 0 sinon. 
 */
int verifier(const Mots* mot_joue, const char* motExtrait,const Mots* dict);

/**
 * @brief Transfere des chevalets de rail � un joueur.
 * @param[in] rail Le rail dont on extrait les chevalets.
 * @param[in, out] joueur Le joueur qui va recevoir les chevalets 
 * @param[in] codeEntre Chiffre indiquant quel cot� du rail traiter ( 1 = gauche , 2 = droite ).
 * @param[in] nb_lettres_a_transferer Le nombre de letteres � transferer.
 */
void transferer(Pioche* rail, Pioche* joueur, int codeEntre, int nb_lettres_a_transferer);

/**
 * @brief Verifie si une lettre est pr�sente dans le jeu d'un joueur.
 * @param[in] pioche La pioche du jouer dont on va v�rifier la pr�sence de la lettre.
 * @param[in] lettre Le chevalet on dont v�rifie la pr�sence.
 * @return 0 si la lettre est absente et 1 si elle est pr�sente dans le jeu.
 */
int verifieLettre(Pioche* pioche, char lettre);

/**
 * @brief Echange le chevalet du joueur avec un de la pioche al�atoirement.
 * @param[in, out] joueur Le joueur dont on va �changer le chevalet.
 * @param[in] lettre Le chevalet qu'on change avec un autre de la pioche.
 * @param[in, out] pioche La pioche contenant les chevalets.
 */
void echangeChevalet(Pioche* joueur, ItemV lettre, int* pioche);

/**
 * @brief Ajoute le mot saisi par un joueur dans le rail qui est vide.
 * @param[in] mot Le mot que l'on ajoute au rail.
 * @param[in, out] rail Le rail dans lequel on ajoute le mot saisi.
 */
void ajoute1(char* mot, Pioche* rail);

/**
 * @brief Teste les fonctions sp�cifiques au composant Pioche.
 */
void testPioche();