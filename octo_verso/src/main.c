#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h> 

#pragma once
#include "input.h"
#pragma warning(disable : 4996 6031)

enum{FORMAT = 4};
const char format[FORMAT] = "%29s";

void initRandom() {
    srand((unsigned int)time(NULL));
}

int main(){
    char mot1[NB_LETTRES_MOT + 1]; 
    char mot2[NB_LETTRES_MOT + 1];
    Mots mot_Joue;
    Mots dict;
    FILE* f = fopen("ods4.txt", "r");
    if (f == NULL) {
        printf("fichier non accessible\n");
        return;
    }
    if (ferror(f)) {
        printf("erreur - %s\n", strerror(errno));
        return ;
    }

    char mot[30] = { 0 };
    int n;
    n = fscanf(f, format, mot);
    initMots(&dict, mot, 500);
    n = fscanf(f, format, mot);
    while (n == 1) {
        ajouterMot(&dict, mot);
        n = fscanf(f, format, mot);
    }
    fclose(f);

    int COMPO_LETTRES_DEPART[NB_LETTRES_DEPART] = { A, B, C, D, E, F, G, H, I, J, K, L, M, O, P, Q, R, S, T, U, V, W ,X ,Y ,Z };
    Pioche joueur1, joueur2, rail;

    initRandom(COMPO_LETTRES_DEPART);
    initJeu(&joueur1, NB_CHEVALETS_DEB, COMPO_LETTRES_DEPART);
    initJeu(&joueur2, NB_CHEVALETS_DEB, COMPO_LETTRES_DEPART);
  

    initVecteur(&rail, NB_LETTRES_RAIL);
    printf("Joueur 1: ");
    affiche(&joueur1);
    printf("Joueur 2: ");
    affiche(&joueur2);
    printf("\n");
    int premier_a_saisir;

    saisieMot(&joueur1, &dict, mot1, 1, &mot_Joue);
    initMots(&mot_Joue, mot1, 50); 
    prelever(&joueur1, mot1);

    saisieMot(&joueur2, &dict, mot2, 2, &mot_Joue);
    ajouterMot(&mot_Joue, mot2);
    prelever(&joueur2, mot2);

    if (strcmp(mot1, mot2) <= 0) { 
        ajoute1(mot1, &rail); ajoute1(mot2, &rail);
        premier_a_saisir = 1;
    }
    else {
        ajoute1(mot2, &rail); ajoute1(mot1, &rail);
        premier_a_saisir = 2;
    }

    Pioche railInverse;
    initVecteur(&railInverse, NB_LETTRES_RAIL);
    inverseRail(&rail, &railInverse);

    //--------------------------------------------------------------------------------------//
    int joueur = premier_a_saisir;
    printf("\n");

    situation(&joueur1, &joueur2, &rail, &railInverse);
    printf("\n");
    Pioche railtmp;
    Pioche railInversetmp;
    Pioche joueur1tmp;
    Pioche joueur2tmp;
    initVecteur(&railtmp,NB_LETTRES_RAIL);    initVecteur(&railInversetmp, NB_LETTRES_RAIL); initVecteur(&joueur1tmp, NB_LETTRES_RAIL); initVecteur(&joueur2tmp, NB_LETTRES_RAIL);
     
    fflush(stdin); // nettoie le buffer au cas où
    while (joueur1.nbElements > 0 && joueur2.nbElements > 0) {
        
        char commande;
        printf("%d> ", joueur);
        
        scanf(" %c", &commande);
        
        Input inputJoueur;

        if (commande == 'r' || commande == 'v') {
            int codeEntre = saisieMotJoueur(joueur == 1 ? &joueur2tmp : &joueur1tmp,
                &railtmp, &railInversetmp, &dict, &inputJoueur, &mot_Joue, joueur , &commande);
            printf("\n");
            if (codeEntre != 0)
            debarasser((joueur == 1 ? &joueur1 : &joueur2), joueur);
            printf("\n");
            situation(&joueur1, &joueur2, &rail, &railInverse);
            printf("\n");

            printf("%d> ", joueur);

            scanf(" %c", &commande);

        }
        if (commande == 'R' || commande == 'V') {

            int codeEntre = saisieMotJoueur(joueur == 1 ? &joueur1 : &joueur2,
                &rail, &railInverse, &dict, &inputJoueur, &mot_Joue, joueur, &commande);
            if (codeEntre != 0) {

                //----------sauvegarde la situation du jeu----------//
                mettre_a_jour(&rail, &railtmp);
                mettre_a_jour(&railInverse ,&railInversetmp);
                mettre_a_jour(&joueur1,&joueur1tmp );
                mettre_a_jour(&joueur2 ,&joueur2tmp);
                //----------sauvegarde la situation du jeu----------//


                ajouterMot(&mot_Joue, inputJoueur.MotForme);
                transferer(commande == 'R' ? &rail : &railInverse, joueur == 2 ? &joueur1 : &joueur2, codeEntre, (int)strlen(inputJoueur.HorsParenthese));
                codeEntre == 1 ? ajouteDeb(inputJoueur.HorsParenthese, commande == 'R' ? &rail : &railInverse) : ajoute(inputJoueur.HorsParenthese, commande == 'R' ? &rail : &railInverse);
                prelever(joueur == 1 ? &joueur1 : &joueur2, inputJoueur.HorsParenthese);


                // mettre à jour les rails du jeu
                if (commande == 'V') {
                    for (int i = 0, n = NB_LETTRES_RAIL - 1; i < NB_LETTRES_RAIL && n >= 0; ++i, --n) {
                        modifier(&rail, i, obtenir(&railInverse, n));

                    }
                }
                else
                {
                    for (int i = 0, n = NB_LETTRES_RAIL - 1; i < NB_LETTRES_RAIL && n >= 0; ++i, --n) {
                        modifier(&railInverse, i, obtenir(&rail, n));
                    }
                }

                if (strlen(inputJoueur.MotForme) == 8 && ( ( joueur == 1  ? joueur1 : joueur2 ).nbElements > 0)) {
                    printf("\n");
                    situation(&joueur1, &joueur2, &rail, &railInverse);
                    printf("\n");
                    debarasser((joueur == 1 ? &joueur1 : &joueur2), joueur);
                }
                if (joueur1.nbElements > 0 && joueur2.nbElements > 0) {
                    printf("\n");
                    situation(&joueur1, &joueur2, &rail, &railInverse);
                    printf("\n");
                }
            }
        }
        else if (commande == '-') {
            ItemV lettre;
            do {
                scanf("%c", &lettre);
            } while (!verifieLettre(joueur == 1 ? &joueur1 : &joueur2, lettre)); 
            echangeChevalet(joueur == 1 ? &joueur1 : &joueur2, lettre, COMPO_LETTRES_DEPART);
            printf("\n");
            situation(&joueur1, &joueur2, &rail, &railInverse);
            printf("\n");
        }

        if (commande == 'r' || commande == 'v' || commande == '-' || commande == 'R' || commande == 'V') {
            joueur = (joueur == 1 ? 2 : 1);
        }
    }
    detruireMots(&dict);
    detruireMots(&mot_Joue);

    detruireVecteur(&rail);
    detruireVecteur(&railInverse);
    detruireVecteur(&joueur1);
    detruireVecteur(&joueur2);

    detruireVecteur(&railtmp);
    detruireVecteur(&railInversetmp);
    detruireVecteur(&joueur1tmp);
    detruireVecteur(&joueur2tmp);
}

