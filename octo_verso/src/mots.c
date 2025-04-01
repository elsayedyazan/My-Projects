#pragma warning (disable : 4996)

#pragma once
#include "mots.h"

void initMots(Mots* m, const char* mot, int capacite) {
    assert(capacite > 0);
    m->capacite = capacite;  // Initialiser la capacité
    m->mots = (char**)malloc(sizeof(char*) * capacite);  // Allouer de l'espace pour "capacite" mots
    if (mot != NULL && m->mots != NULL) {  // Si un mot est fourni, on l'ajoute
        m->mots[0] = (char*)malloc(sizeof(char) * (strlen(mot) + 1));
        if(m->mots[0]!= NULL) strcpy(m->mots[0], mot);
        m->nbMots = 1;
    }
    else {
        m->nbMots = 0;  // Aucun mot initial
    }
}

int MotConnu(const Mots* m, const char* mot) {
    int debut = 0;
    int fin = m->nbMots - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2;
        int cmp = strcmp(m->mots[milieu], mot);

        if (cmp == 0) {
            return 1;  // Mot trouvé :)
        }
        else if (cmp < 0) {
            debut = milieu + 1;  // Chercher dans la moitié droite
        }
        else {
            fin = milieu - 1;  // Chercher dans la moitié gauche
        }
    }

    return 0;  // Mot non trouve :(
}

int ajouterMot(Mots* m, const char* mot) {
    if (!MotConnu(m, mot)) {  // Vérifier si le mot est déjà présent
        if (m->nbMots >= m->capacite) {  // Agrandir la capacité si nécessaire
            int nouvelleCapacite = m->capacite * 2;
            char** nouveauTableau = (char**)realloc(m->mots, sizeof(char*) * nouvelleCapacite);
            if (nouveauTableau == NULL) {
                return 0;  // Erreur d'allocation
            }
            m->mots = nouveauTableau;
            m->capacite = nouvelleCapacite;
        }

        // Allocation et copie du nouveau mot
        m->mots[m->nbMots] = (char*)malloc(sizeof(char) * (strlen(mot) + 1));
        if (m->mots[m->nbMots] == NULL) {
            return 0;  // Erreur d'allocation pour le mot
        }

        strcpy(m->mots[m->nbMots], mot);  // Copier le mot
        m->nbMots++;  // Incrémenter le nombre de mots
        return 1;  // Succès
    }
    return 0;  // Mot déjà utilisé
}

void detruireMots(Mots * m) {
    for (int i = 0; i < m->nbMots; ++i) {
        free(m->mots[i]);
    }
    free(m->mots);
    m->mots = NULL;
    m->nbMots = 0;
    m->capacite = 0;
}

void testMots() {
    Mots m;
    initMots(&m, "un", 10);
    assert(MotConnu(&m, "un") == 1);
    assert(MotConnu(&m, "deux") == 0);

    ajouterMot(&m, "deux");
    assert(MotConnu(&m, "deux") == 1);

    detruireMots(&m);
}