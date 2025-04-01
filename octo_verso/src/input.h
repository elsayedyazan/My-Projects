#pragma once
#include <stdio.h>
#include <stdlib.h>
//#include <assert.h>
#include "pioche.h"

typedef struct {
    char EntreParenthese[NB_LETTRES_RAIL + 1];
    char HorsParenthese[NB_LETTRES_RAIL + 1];
    char MotForme[NB_LETTRES_RAIL + 1];
}Input;

/**
 * @brief prend une chaîne de caractère(un mot) et copie ce qui est entre parenthèses dans resultat
 * @param[in] input : la chaîne de caractère à traiter
 * @param[out] resultat : ce qui est entre parenthèses
 */
void Extraire_Hors_Parenthese(const char* input, char* resultat);

/**
 * @brief extrait ce qui est entre parenthèses dans une chaîne de caractère.
 * @param[in] entre : La chaîne de caractère à traiter
 * @param[out] motExtrait : mot extrait des parenthèses
 */
void extraire_entre_parenthese(const char* entre, char* motExtrait);

/**
 * @brief prend une chaîne de caractère(un mot) et enlève tous les caractères '(' rt ')'
 * @param[in] input : la chaîne de caractère à traiter 
 * @param[out] MotForme : la chaîne de caractère sans '(' et ')'
 */
void forme_mot(const char* input, char* MotForme);

/**
 * @brief demande un joueur de former un mot en indiquant le coté du rail où il doit être posé par la lettre correspondante 
 (R ou V) suivi du mot.
 * @param[in] j : la pioche du joueur .
 * @param[in] rail : le rail recto (R).
 * @param[in] railInverse : le rail verso (V).
 * @param[in] dict : le dictionnaire des mots fraincais.
 * @param[out] inputJoueur : l'entré du joueur .
 * @param[in] mot_Joue : la liste des mots déja joués au cours du jeu .
 * @param[in] joueur : le numéro du joueur .
 * @param[in,out] commande : la commande entrée au premier coup (R ou V).
 * @return : si le coup est validée renvoie le code d'entrée du mot formé (coté du rail traiter  1 = gauche , 2 = droite ).
 */
int saisieMotJoueur(const Pioche* j, const Pioche* rail,const Pioche* railInverse,const Mots* dict, 
    Input* inputJoueur,const Mots* mot_Joue, int joueur, char* commande);

/**
 * @brief enlever de la pioche du joueur les lettres dont il a utilisé pour former le mot
 * @param[in] joueur
 * @param[in] mot
 */
void prelever(Pioche* joueur, char* mot);

/**
 * @brief demande aux joueurs de débarrasser d'une lettre de sa pioche
 * @param[in] joueur
 * @param[in] nbjoueur
 */
void debarasser(Pioche* joueur, int nbjoueur);

/** 
 * @brief mets à jour P2 de P1 (copie p1 dans p2)
 * @param[in] p1
 * @param[in,out] p2
 */
void mettre_a_jour(const Pioche* p1, Pioche* p2);


/**
 * @brief Teste les foncrions liées au composant Input.
 */
void testInput();
