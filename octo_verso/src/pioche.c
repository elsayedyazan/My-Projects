#pragma once
#include "pioche.h"

#pragma warning(disable : 4996 6031)

const char LETTRES[NB_LETTRES_DEPART] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M' , 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W' ,'X' ,'Y' ,'Z' };


char lettreAleatoire(int* COMPO_LETTRES) {
    int ind;

    do {
        ind = rand() % NB_LETTRES_DEPART;
    } while (COMPO_LETTRES[ind] == 0);

    --COMPO_LETTRES[ind]; //Je retire le chevalet du stock

    return LETTRES[ind];
}

int inserer(Pioche* f, ItemV it) {
    int sortie = ajouter(f, it);
    for (int i = f->nbElements - 1; i > 0; --i) {
        ItemV a = obtenir(f, i);
        ItemV b = obtenir(f, i - 1);
        if (a < b) {
            modifier(f, i - 1, a);
            modifier(f, i, b);
        }

    }
    return sortie;
}

void initJeu(Pioche* j, int nb_chevalets, int* COMPO_LETTRES_DEPART) {
    initVecteur(j, nb_chevalets);
    for (int i = 0; i < nb_chevalets; ++i) {
        inserer(j, lettreAleatoire(COMPO_LETTRES_DEPART));
    }

}

void affiche(Pioche* p) {
    for (int i = 0; p->nbElements > i; ++i) {
        printf("%c", obtenir(p, i));
    }
    printf("\n");
}

int indexLettre(char c) {
    return c - 'A';  // Se sert du code ASCII
}

int verifMot(char* mot, const Pioche* p) {
int cptPioche[NB_LETTRES_DEPART] = { 0 };  // Tableau pour compter les lettres dans la pioche
    int cptMot[NB_LETTRES_DEPART] = { 0 };     // Tableau pour compter les lettres dans le mot

    // Comptabiliser les lettres dans la pioche
    for (int k = 0; k < p->nbElements; ++k) {
        char lettre = obtenir(p, k);
        cptPioche[indexLettre(lettre)]++;
    }

    // Comptabiliser les lettres dans le mot
    size_t n = strlen(mot);
    for (int i = 0; i < n; ++i) {
        char lettre = mot[i];
        cptMot[indexLettre(lettre)]++;
    }

    // Vérifier si la pioche a assez de lettres pour chaque lettre du mot
    for (int i = 0; i < NB_LETTRES_DEPART; ++i) {
        if (cptMot[i] > cptPioche[i]) {
            return 0;
        }
    }

    return 1;
}

void saisieMot(Pioche* j, Mots* dict, char* mot, int numJoueur, Mots* m) {
    do {
        printf("%d> ", numJoueur);
        scanf("%s", mot);

    } while (strlen(mot) != NB_LETTRES_MOT || MotConnu(dict, mot) == 0 || verifMot(mot, j) == 0 || MotConnu(m, mot) == 1);

}

void ajoute1(char* mot, Pioche* rail) {
    for (int i = 0; i < NB_LETTRES_MOT; ++i) {
        ajouter(rail, mot[i]);
    }
}

void ajoute(char* mot, Pioche* rail) {

    int n = (int)strlen(mot);
    // Décale les lettres existantes vers la gauche pour faire de la place à la fin.
    for (int i = 0; i < NB_LETTRES_RAIL - n; ++i) {
        modifier(rail, i, obtenir(rail, i + n));
    }

    // Place le mot à la fin du rail.
    for (int i = 0; i < n; ++i) {
        modifier(rail, NB_LETTRES_RAIL - n + i, mot[i]);
    }
}

void ajouteDeb(char* mot, Pioche* rail) {
    int n = (int)strlen(mot);
    for (int i = NB_LETTRES_RAIL - 1; i >= n; --i) {
        modifier(rail, i, obtenir(rail, i - n));
    }

    // Place le mot au début du rail en écrasant les premières lettres.
    for (int i = 0; i < n; ++i) {
        modifier(rail, i, mot[i]);
    }
}

void inverseRail(Pioche * rail, Pioche * railInverse) {
    for (int j = rail->nbElements - 1; j >= 0; --j) {
        ajouter(railInverse, obtenir(rail, j));
    }
    
}

void situation(Pioche* j1, Pioche* j2, Pioche* r, Pioche* rI) {
    printf("1 : ");
    affiche(j1);
    printf("2 : ");
    affiche(j2);
    printf("R : ");
    affiche(r);
    printf("V : ");
    affiche(rI);
}



int verifier_lettres_extremite(const Pioche* rail, const char* motExtrait, int codeEntre) {
int len_motExtrait = (int)strlen(motExtrait);
    if (taille(rail) < len_motExtrait) return 0;
    if (codeEntre == 1) {
        for (int i = 0, j = 0; i < len_motExtrait; ++i, ++j) {
            if (motExtrait[i] != obtenir(rail, j))
                return 0;
        }
    }
    else if (codeEntre == 2) {
        for (int i = len_motExtrait - 1, j = taille(rail) - 1; i >= 0; --i, --j) {
            if (motExtrait[i] != obtenir(rail, j))
                return 0;
        }
    }
    return 1;
}

int verifier(const Mots* mot_joue, const char* motExtrait, const Mots* dict){
if (strlen(motExtrait) > 8) return 0;
    if (!MotConnu(dict, motExtrait)) return 0;
    if (MotConnu(mot_joue, motExtrait)) return 0;
    return 1;
}

void transferer(Pioche* rail, Pioche* joueur, int codeEntre, int nb_lettres_a_transferer) {
    if (codeEntre == 1) {
        int tmp = taille(rail);
        for (int i = 0, j = taille(rail) - 1; i < nb_lettres_a_transferer; ++i, --j) {
            inserer(joueur, obtenir(rail, j));
            //supprimer(rail, taille(rail) - 1);
        }
        //rail->nbElements = tmp;
    }
    else if (codeEntre == 2) {
        for (int i = nb_lettres_a_transferer - 1, j = 0; i >= 0; --i, ++j) {
            inserer(joueur, obtenir(rail, j));
            //supprimer(rail, 0);
        }
    }
}

int verifieLettre(Pioche* pioche, char lettre) {
    for (int i = 0; i < pioche->nbElements; ++i) {
        if (pioche->elements[i] == lettre) {
            return 1;
        }
    }
    return 0;
}

void echangeChevalet(Pioche* joueur, ItemV lettre, int* pioche) {
    char nvChevalet = lettreAleatoire(pioche);
    int i;
    for (i = 0; i < taille(joueur); ++i) {
        if (obtenir(joueur, i) == lettre) {
            break;
        }
    }
    supprimer(joueur, i);
    inserer(joueur, nvChevalet);
    int index = indexLettre(lettre);
    pioche[index]++;

}

void testPioche() {
    int COMPO_LETTRES_DEPART[NB_LETTRES_DEPART] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1, 5, 3, 6, 0, 5, 2, 1, 6, 7, 6, 5, 2, 0, 0, 0, 0 };
    Pioche p;
    initJeu(&p, 1, COMPO_LETTRES_DEPART);
    modifier(&p, 0, 'E');
    assert(verifieLettre(&p, 'E') == 1);

    ajoute("AS", &p);
    assert(taille(&p) == 3);
    assert(indexLettre('D') == 4);

    Pioche p2;
    initVecteur(&p2, 8);
    inverseRail(&p, &p2);
    assert(p2.elements[0] == 'S');
    assert(verifMot("SAE", &p2) == 1);

    ajouteDeb("RENDU", &p2);
    assert(verifMot("RENDUSAE", &p2) == 1);
    assert(p.elements[0] == 'R');
    ajoute("RAPPORT", &p);
    assert(verifMot("RAPPORT", &p) == 1);

    transferer(&p2, &p, 1, 5);
    assert(verifMot("RENDU", &p) == 1);
    echangeChevalet(&p, 'R', COMPO_LETTRES_DEPART);
    assert(p.elements[0] != 'R');

    detruireVecteur(&p);
    detruireVecteur(&p2);
}
