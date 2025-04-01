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
 * @brief prend une cha�ne de caract�re(un mot) et copie ce qui est entre parenth�ses dans resultat
 * @param[in] input : la cha�ne de caract�re � traiter
 * @param[out] resultat : ce qui est entre parenth�ses
 */
void Extraire_Hors_Parenthese(const char* input, char* resultat);

/**
 * @brief extrait ce qui est entre parenth�ses dans une cha�ne de caract�re.
 * @param[in] entre : La cha�ne de caract�re � traiter
 * @param[out] motExtrait : mot extrait des parenth�ses
 */
void extraire_entre_parenthese(const char* entre, char* motExtrait);

/**
 * @brief prend une cha�ne de caract�re(un mot) et enl�ve tous les caract�res '(' rt ')'
 * @param[in] input : la cha�ne de caract�re � traiter 
 * @param[out] MotForme : la cha�ne de caract�re sans '(' et ')'
 */
void forme_mot(const char* input, char* MotForme);

/**
 * @brief demande un joueur de former un mot en indiquant le cot� du rail o� il doit �tre pos� par la lettre correspondante 
 (R ou V) suivi du mot.
 * @param[in] j : la pioche du joueur .
 * @param[in] rail : le rail recto (R).
 * @param[in] railInverse : le rail verso (V).
 * @param[in] dict : le dictionnaire des mots fraincais.
 * @param[out] inputJoueur : l'entr� du joueur .
 * @param[in] mot_Joue : la liste des mots d�ja jou�s au cours du jeu .
 * @param[in] joueur : le num�ro du joueur .
 * @param[in,out] commande : la commande entr�e au premier coup (R ou V).
 * @return : si le coup est valid�e renvoie le code d'entr�e du mot form� (cot� du rail traiter  1 = gauche , 2 = droite ).
 */
int saisieMotJoueur(const Pioche* j, const Pioche* rail,const Pioche* railInverse,const Mots* dict, 
    Input* inputJoueur,const Mots* mot_Joue, int joueur, char* commande);

/**
 * @brief enlever de la pioche du joueur les lettres dont il a utilis� pour former le mot
 * @param[in] joueur
 * @param[in] mot
 */
void prelever(Pioche* joueur, char* mot);

/**
 * @brief demande aux joueurs de d�barrasser d'une lettre de sa pioche
 * @param[in] joueur
 * @param[in] nbjoueur
 */
void debarasser(Pioche* joueur, int nbjoueur);

/** 
 * @brief mets � jour P2 de P1 (copie p1 dans p2)
 * @param[in] p1
 * @param[in,out] p2
 */
void mettre_a_jour(const Pioche* p1, Pioche* p2);


/**
 * @brief Teste les foncrions li�es au composant Input.
 */
void testInput();
