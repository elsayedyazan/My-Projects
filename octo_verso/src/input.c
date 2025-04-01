#pragma once
#include "input.h"

#pragma warning(disable : 4996 6031)

void extraire_entre_parenthese(const char* input, char* resultat) {
    int i = 0, j = 0;
    int dansParenthese = 0;  

    while (input[i] != '\0') {
        
        if (input[i] == '(') {
            dansParenthese = 1;
        }
        else if (input[i] == ')') {
            dansParenthese = 0;
        }
        else if (dansParenthese) {
            resultat[j++] = input[i];
        }
        i++;
    }
    resultat[j] = '\0';
}

void Extraire_Hors_Parenthese(const char* input, char* resultat) {
    int i = 0, j = 0;
    int dansParenthese = 0;  // Indicateur pour savoir si nous sommes dans les parenthèses

    // Parcourir chaque caractère de la chaîne d'entrée
    while (input[i] != '\0') {
        // Si nous rencontrons une parenthèse ouvrante, on entre dans la section des parenthèses
        if (input[i] == '(') {
            dansParenthese = 1;
        }
        // Si nous rencontrons une parenthèse fermante, on sort de la section des parenthèses
        else if (input[i] == ')') {
            dansParenthese = 0;
        }
        // Si nous ne sommes pas dans les parenthèses, on copie 
        else if (!dansParenthese) {
            resultat[j++] = input[i];
        }
        i++;
    }
    resultat[j] = '\0';
}

void forme_mot(const char* input, char* MotForme) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (input[i] != '(' && input[i] != ')')
            MotForme[j++] = input[i];
        ++i;
    }
    MotForme[j] = '\0';
}

int saisieMotJoueur(const Pioche* j, const Pioche* rail, const Pioche* railInverse, const Mots* dict,
    Input* inputJoueur, const Mots* mot_Joue, int joueur, char* commande){

    char EntreJoueur[NB_LETTRES_RAIL + 3]; // ( = 1 , ) = 1 , \0 = 1 : 1+1+1 = 3
    int codeEntre = 0;
    int coupe = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    do {
        codeEntre = 0;

        if (coupe != 0) {
            printf("%d> ", joueur);
            scanf(" %c", commande);
            if (*commande != 'R' && *commande != 'V' && *commande != 'r' && *commande != 'v') return codeEntre;
        }
        scanf(" %s", EntreJoueur);

        char p = EntreJoueur[0];
        if (p == '(') codeEntre = 2; else codeEntre = 1;

        extraire_entre_parenthese(EntreJoueur, inputJoueur->EntreParenthese);
        Extraire_Hors_Parenthese(EntreJoueur, inputJoueur->HorsParenthese);
        forme_mot(EntreJoueur, inputJoueur->MotForme);
        ++coupe;
        a = verifMot(inputJoueur->HorsParenthese, j);
        b = verifier(mot_Joue, inputJoueur->MotForme, dict);
        c = verifier_lettres_extremite(*commande == 'R' || *commande == 'r' ? rail : railInverse, inputJoueur->EntreParenthese, codeEntre);
    } while (//strlen(EntreJoueur) > NB_LETTRES_RAIL + 1 || // pas sur de cette condition
        (a == 0) || (b == 0) || (c == 0));

    return codeEntre;
}

void prelever(Pioche* joueur, char* mot) {
    int n = (int)strlen(mot);
    for (int i = 0; i < n; ++i) {
        char lettre = mot[i];
        for (int j = 0; j < taille(joueur); ++j) {
            if (obtenir(joueur, j) == lettre) {
                supprimer(joueur, j);
                break;

            }
        }
    }
}

void debarasser(Pioche* joueur, int nbjoueur) {
    char lettre_a_debarasser;
    do {
        printf("-%d> ", nbjoueur);
        scanf(" %c", &lettre_a_debarasser);

    } while (verifieLettre(joueur, lettre_a_debarasser) == 0);

    for (int i = 0; i < taille(joueur); ++i) {
        if (obtenir(joueur, i) == lettre_a_debarasser) {
            supprimer(joueur, i);
            break;
        }
    }
}

void mettre_a_jour(const Pioche* p1, Pioche* p2) {
    if (taille(p2) == 0)
        for (int i = 0; i < p1->nbElements; ++i) {
            ajouter(p2, obtenir(p1, i));
        }
    else {
        for (int i = 0; i < taille(p1); ++i) {
            if (i > p2->nbElements - 1)
                ajouter(p2, obtenir(p1, i));
            else
                modifier(p2, i, obtenir(p1, i));
        }
    }
}

void testInput() {
    Input p;
    char mot[NB_LETTRES_RAIL + 3] = "TEST(ER)";// ( = 1 , ) = 1 , \0 = 1 : 1+1+1 = 3
    extraire_entre_parenthese(mot, p.EntreParenthese);
    assert(strcmp(p.EntreParenthese, "ER") == 0);
    Extraire_Hors_Parenthese(mot, p.HorsParenthese);
    assert(strcmp(p.HorsParenthese, "TEST") == 0);
    forme_mot(mot, p.MotForme);
    assert(strcmp(p.MotForme, "TESTER") == 0);

    Pioche joueur1;
    char teste1[NB_CHEVALETS_DEB + 1] = "CEEEENNNRSTU";
    initVecteur(&joueur1, NB_CHEVALETS_DEB);
    for (int i = 0; i < NB_CHEVALETS_DEB ; ++i) {
        ajouter(&joueur1, teste1[i]);
    }
    prelever(&joueur1, "CENE");

    char tmp[NB_CHEVALETS_DEB + 1 - 4 ]; // 4 = strlen("CENE")
    int i;
    for (i = 0; i < joueur1.nbElements; ++i)
        tmp[i] = obtenir(&joueur1, i);
    tmp[i] = '\0';
    assert(strcmp(tmp, "EENNRSTU") == 0);

    Pioche p2;
    initVecteur(&p2, NB_CHEVALETS_DEB);
    mettre_a_jour(&joueur1, &p2);
    for (i = 0; i < p2.nbElements; ++i)
        assert(obtenir(&joueur1, i) == obtenir(&p2, i));


    detruireVecteur(&joueur1);
    detruireVecteur(&p2);
}