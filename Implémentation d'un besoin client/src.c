#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996 6031 6054 6262)
enum { NB_ETUDIANTS_MAX = 100, NOM_MAX = 31, MAX_JUSTIFICATIF = 51, NB_JOUR_SEMESTRE_MAX = 40, NB_SEMESTRE_MIN = 1, MAX_ABSENCES_ETUDIANT = 80, MAX_ABSENCES = MAX_ABSENCES_ETUDIANT * NB_ETUDIANTS_MAX, MAX_COMMANDE = 13 };
// Définition des types enumeré 
typedef enum { am, pm } DemiJourne; // represente les journés
typedef enum { EnCoursDeTraitement, Justifiee, NonJustifiee, EnAttenteJustificatif } Statu; // represente le statu d'un absence 
typedef enum { ok, ko } Validation; // represente le code de validation
// Structure pour stocker les informations d'un justificatif
typedef struct {
	char text_justificatif[MAX_JUSTIFICATIF];
	int jour;
}Justificatif;

// Structure pour stocker les informations d'un absence
typedef struct {
	int identifiant;
	int identifiant_etudiant_concerne;
	int jour;
	DemiJourne journe;
	Justificatif justificatif;
	Statu statu;
	// pour le statue 
} Absence;

// Structure pour stocker les informations des étudiants
typedef struct {
	char nom[NOM_MAX];
	unsigned int identifiant;
	int group;
	int nb;
} Etudiant;


// Fonction pour demander et traiter la commande
void demande_commande(char* input_) {
	scanf("%s", input_);
}

void saisieLigne(char* ligne, int max) {
	int c = getc(stdin);
	while (c == ' ' || c == '\t')
		c = getc(stdin);
	ungetc(c, stdin);
	fgets(ligne, max, stdin);
	ligne[strlen(ligne) - 1] = '\0';
}
DemiJourne string_to_DemiJourne(const char* input) {
	if (strcmp(input, "am") == 0) {
		return am;
	}
	else if (strcmp(input, "pm") == 0) {
		return pm;
	}
	else
		return -1;

}
Validation string_to_validation(const char* input) {
	if (strcmp(input, "ok") == 0) {
		return ok;
	}
	else if (strcmp(input, "ko") == 0) {
		return ko;
	}
	else
		return -1;
}

// Fonction pour inscrire un étudiant
void inscriptionn(Etudiant* e, int* compt, Etudiant etudiants[]) {
	for (int i = 0; i < *compt; ++i) {
		if (strcmp(etudiants[i].nom, e->nom) == 0 && (etudiants[i].group == e->group)) {
			printf("Nom incorrect\n");
			return;
		}
	}
	e->identifiant = *compt + 1;
	e->nb = 0;
	etudiants[*compt] = *e;
	*compt = *compt + 1;
	printf("Inscription enregistree (%d)\n", e->identifiant);
}
// la fonction verifie si les donnes entrés sont just
int verifier_absence(int iden, int jour, DemiJourne demi_journe, int compt) {
	if (iden <= 0 || iden > compt) {
		printf("Identifiant incorrect\n");
		return 0;
	}
	else if (jour > NB_JOUR_SEMESTRE_MAX || jour < NB_SEMESTRE_MIN) {
		printf("Date incorrecte\n");
		return 0;
	}
	else if (demi_journe == -1) {
		printf("Demi-journee incorrecte\n");
		return 0;
	}
	else
		return 1;
}
//fonction pour verifier si l'absence est déja enregistré
int verifier_exsistance_absence(int iden, int jour, DemiJourne demi_journe, Absence absences[], int nb_absence_total) {
	int AbsenceNonConnue = 1;
	for (int i = 0; i < nb_absence_total; ++i) {
		if (absences[i].identifiant_etudiant_concerne == iden && absences[i].jour == jour && absences[i].journe == demi_journe)
			AbsenceNonConnue = 0;
	}
	return AbsenceNonConnue;
}
// fonction qui ajoute un absence dans le tableau d'absence
void enregistrer_absence(int iden, int jour, DemiJourne demi_journe, int* nb_absence_total, Absence* absences) {
	absences[*nb_absence_total].jour = jour;
	absences[*nb_absence_total].journe = demi_journe;
	absences[*nb_absence_total].identifiant_etudiant_concerne = iden;
	absences[*nb_absence_total].statu = EnAttenteJustificatif;
	absences[*nb_absence_total].identifiant = *nb_absence_total + 1;
	printf("Absence enregistree[%d]\n", absences[*nb_absence_total].identifiant);
	absences[*nb_absence_total].justificatif.text_justificatif[0] = '\0';
	*nb_absence_total = *nb_absence_total + 1;
}
// la fonction traite la commande "absence" (verifier les entrés , verifier l'unicité , enregistrer)
void abcense(int iden, int jour, DemiJourne demi_journe, Etudiant etudiants[], int compt, int* nb_absence_total, Absence absences[]) {
	int est_verifie = verifier_absence(iden, jour, demi_journe, compt);
	if (est_verifie) {
		int AbsenceNonConnue = verifier_exsistance_absence(iden, jour, demi_journe, absences, *nb_absence_total);
		if (AbsenceNonConnue) {
			enregistrer_absence(iden, jour, demi_journe, nb_absence_total, absences);
			++etudiants[iden - 1].nb;
		}
		else
			printf("Absence deja connue\n");
	}
}
// pour encapsuler les etudiant 
typedef struct {
	int indice;          // Indice de l'étudiant
	Etudiant* etudiant;  // Pointeur vers l'étudiant
} IndiceEtudiant;

// fonction de comparaison (pour qsort) 
int comparer_indice(const void* a, const void* b) {
	IndiceEtudiant* etuA = (IndiceEtudiant*)a;
	IndiceEtudiant* etuB = (IndiceEtudiant*)b;

	// Comparer par groupe
	if (etuA->etudiant->group != etuB->etudiant->group) {
		return etuA->etudiant->group - etuB->etudiant->group;
	}
	// Sinon, comparer par nom
	return strcmp(etuA->etudiant->nom, etuB->etudiant->nom);
}

// fonction qui affiche l'identifiant de l'étudiant , son nom , son groupe , son nombre d'absence jusqu'à une date  
void afficher_absence(Etudiant* etudiant, int nb_absence_total, int date, Absence absences[]) {
	int nb_absence = 0;
	for (int j = 0; j < nb_absence_total; ++j) { // transformer en fonction pour afficher les absence de l'etudiant . pour partie etudiant(..) aussi  
		if (absences[j].identifiant_etudiant_concerne == etudiant->identifiant && absences[j].jour <= date) {
			nb_absence++;
		}
	}
	printf("(%d) %s\t %d %d\n", etudiant->identifiant, etudiant->nom, etudiant->group, nb_absence);
}
// fonction qui pour tous les étudiants : affiche l'identifiant de l'étudiant, son nom, son groupe, son nombre d'absence jusqu'à une date
void afficher(IndiceEtudiant* indiceEtudiant, int date, int compt, int nb_absence_total, Absence absences[]) {
	for (int i = 0; i < compt; ++i) {
		Etudiant* etu = indiceEtudiant[i].etudiant;
		afficher_absence(etu, nb_absence_total, date, absences);
	}
}
// verifier si la date est juste et si il exsiste des etudiant inscrit
int verifier_date_et_inscrits(int date, int compt) {
	if (date < 1) {
		printf("Date incorrecte\n");
		return 0;
	}
	else if (compt < 1) {
		printf("Aucun inscrit\n");
		return 0;
	}
	else
		return 1;
}
/* la fonction verifie les entrés, trie le etudiants dans par groupe croissant et, au sein d’un même
groupe, par ordre alphabétique croissant de leur nom . puis elle affiche les etudiant ainsi certain de leurs donnes (identifiant,nom,groupe..)*/
void triater_afficher_etudiants(int date, int compt, Etudiant etudiants[], int nb_absence_total, Absence absences[]) {
	int verifier = verifier_date_et_inscrits(date, compt);
	if (verifier) {
		IndiceEtudiant tab_indice[NB_ETUDIANTS_MAX];
		for (int i = 0; i < compt; ++i) {
			tab_indice[i].indice = i;
			tab_indice[i].etudiant = &etudiants[i];  // Liaison avec l'?tudiant
		}
		qsort(tab_indice, compt, sizeof(IndiceEtudiant), comparer_indice); // Trier les etudiants via leurs indices et le tableau encapsulé
		afficher(tab_indice, date, compt, nb_absence_total, absences);
	}
}
// la fonction verifie les entres ainsi la possibilité de les traiter 
int verifier_justificatif(int identifiant, int jour, char* justificatif, const Absence* absences, int nb_absence_total) {
	if (identifiant > nb_absence_total || identifiant > MAX_ABSENCES || identifiant < 1) {
		printf("Identifiant incorrect\n");
		return 0;
	}
	else if (absences[identifiant - 1].jour > jour) {
		printf("Date incorrecte\n");
		return 0;
	}
	else if (absences[identifiant - 1].statu != EnAttenteJustificatif) {
		printf("Justificatif deja connu\n");
		return 0;
	}
	else
		return 1;

}
// la fonction verifie le justificatif ainsi la possibilité de l'enregistrer et le traiter 
void enregistrer_justificatif(int identifiant, int jour, char justificatif[], Absence absences[], int nb_absence_total) {
	int est_verifier = verifier_justificatif(identifiant, jour, justificatif, absences, nb_absence_total);
	if (est_verifier) {
		strcpy(absences[identifiant - 1].justificatif.text_justificatif, justificatif);
		absences[identifiant - 1].justificatif.jour = jour;
		if (jour - absences[identifiant - 1].jour > 3)
			absences[identifiant - 1].statu = NonJustifiee;
		else
			absences[identifiant - 1].statu = EnCoursDeTraitement;

		printf("Justificatif enregistre\n");
	}
}
// la fonction un boolean(1 ou 0) concernant l'exsistance d'un absence en attente de validation 
int verifier_validations(int nb_absence_total, const Absence absences[]) {
	int exsistance_validation = 0;
	for (int i = 0; i < nb_absence_total; ++i) {
		if (absences[i].statu == EnCoursDeTraitement)
			exsistance_validation = 1;
	}
	return exsistance_validation;

}
// affiche identifiant de l'absence  , identifiant de l'étudiant concerne , nom , groupe , jour de l'absence , journe de l'absence 
// et le justificatif 
void afficher_validation(Absence *absence, const Etudiant  etudiants[], int idnetifiant_etudiant) {
	printf("[%d] (%d) %s %d %d/%s (%s)\n",
		absence->identifiant,
		absence->identifiant_etudiant_concerne,
		etudiants[idnetifiant_etudiant].nom,
		etudiants[idnetifiant_etudiant].group,
		absence->jour,
		(absence->journe == am ? "am" : "pm"),
		absence->justificatif.text_justificatif);
}
typedef struct {
	int indice;          // Index de l'étudiant
	Absence* absence;  // Pointeur vers l'?tudiant
}IndiceAbsence;
int comparer_absence(const void* a, const void* b) {
	IndiceAbsence* absenceA = (IndiceAbsence*)a;
	IndiceAbsence* absenceB = (IndiceAbsence*)b;
	if (absenceA->absence->jour != absenceB->absence->jour)
		return absenceA->absence->jour - absenceB->absence->jour;
	else
		return absenceA->absence->journe - absenceB->absence->journe;
}
// liste les absence en attente de validation 
void lister_validations(const Etudiant etudiants[], int nb_absence_total, const Absence absences[],int compt) {
	int exsistance_validation = verifier_validations(nb_absence_total, absences);
	if (exsistance_validation) {
		IndiceAbsence tab_indice_absences[MAX_ABSENCES];
		int idnetifiant_etudiant;
		for (int i = 0; i < nb_absence_total; ++i) {
			tab_indice_absences[i].indice = i;
			tab_indice_absences[i].absence = &absences[i];
		}
		qsort(tab_indice_absences, nb_absence_total, sizeof(IndiceAbsence), comparer_absence);
		for (int j = 0; j < compt; ++j) {
			Etudiant* etudiant = &etudiants[j];
			for (int i = 0; i < nb_absence_total; ++i) {
				if (tab_indice_absences[i].absence->identifiant_etudiant_concerne == etudiant->identifiant && tab_indice_absences[i].absence->statu == EnCoursDeTraitement) {
					idnetifiant_etudiant = tab_indice_absences[i].absence->identifiant_etudiant_concerne - 1;
					afficher_validation(tab_indice_absences[i].absence, etudiants, idnetifiant_etudiant);
				}
			}
		}
	}
	else
		printf("Aucune validation en attente\n");
}
// la fonction verifie la possibilité d'appliquer une validation (identifiant correct , validation unique , code validation correcte ) 
int  verifier_validation_absence(const Absence absences[], int identifiant, int nb_absence_total, Validation code_validation) {
	if (identifiant > nb_absence_total || identifiant < 1 || absences[identifiant - 1].statu == EnAttenteJustificatif || absences[identifiant - 1].justificatif.jour - absences[identifiant - 1].jour > 3 ) {
		printf("Identifiant incorrect\n");
		return 0;
	}
	else if (absences[identifiant - 1].statu == Justifiee || absences[identifiant - 1].statu == NonJustifiee) {
		printf("Validation deja connue\n");
		return 0;
	}
	else if (code_validation == -1) {
		printf("Code incorrect\n");
		return 0;
	}


	return 1;

}
// affiche les absences en attente de validation 
void validation_absence(Absence absences[], int identifiant, int nb_absence_total, Validation code_validation) {
	int verifier_validation = verifier_validation_absence(absences, identifiant, nb_absence_total, code_validation);
	if (verifier_validation) {
		if (code_validation == ok)
			absences[identifiant - 1].statu = Justifiee;
		else
			absences[identifiant - 1].statu = NonJustifiee;
		printf("Validation enregistree\n");
	}
}
//verifier les entres s'ils sont justes pour (situation etudiant)
int verifier_situaton_etudiant(int date, int identifiant, int compt) {
	if (date < 1) {
		printf("Date incorrecte\n");
		return 0;
	}
	else if (identifiant > compt || identifiant > NB_ETUDIANTS_MAX || identifiant <= 0) {
		printf("Identifiant incorrect\n");
		return 0;
	}
	else
		return 1;
}

//fonction comparaison : d'abord le jour puis journe

// pour donner un etat (bool) aux variables donnes si c'est les condition sont valables
void compter_statu(int* existe_EnAttentValidation, int* existe_Justifiee, int* existe_EnAttentJustificatif, int* existe_NonJustifiee, const Absence* absence, int date) {
	if (absence->statu == EnCoursDeTraitement && absence->justificatif.jour <= date && *existe_EnAttentValidation == 0)
		*existe_EnAttentValidation = 1;
	else if (absence->statu == Justifiee && absence->justificatif.jour <= date && *existe_Justifiee == 0)
		*existe_Justifiee = 1;
	else if ((absence->statu == EnAttenteJustificatif && ((date - absence->jour) <= 3)) || absence->justificatif.jour > date && ((date - absence->jour) <= 3)  &&  *existe_EnAttentJustificatif == 0)
		*existe_EnAttentJustificatif = 1;
	else if (*existe_NonJustifiee == 0 && (absence->statu == NonJustifiee || ((absence->statu == EnAttenteJustificatif) && (date - absence->jour) > 3)))
		*existe_NonJustifiee = 1;
}
//void afficher_section(int nb_absences, IndiceAbsence  tab_indice_absences_[80], int date, char motif[120], int expression, Absence* absence);
// pour afficher la situation des absence d'un etudaint 
void situation_etudiant(int date, int identifiant, int compt, Etudiant etudiants[], int nb_absence_total, Absence absences[]) {
	char motif[120];
	int expression;
	int verifier = verifier_situaton_etudiant(date, identifiant, compt);
	if (verifier) {
		IndiceAbsence tab_indice_absences[MAX_ABSENCES_ETUDIANT];
		int existe_EnAttentValidation = 0; int existe_NonJustifiee = 0; int existe_Justifiee = 0; int existe_EnAttentJustificatif = 0;
		int nb_absences = 0;
		for (int i = 0; i < nb_absence_total; ++i) {
			if (absences[i].identifiant_etudiant_concerne == identifiant && absences[i].jour <= date) {
				tab_indice_absences[nb_absences].indice = i;
				tab_indice_absences[nb_absences].absence = &absences[i];
				compter_statu(&existe_EnAttentValidation, &existe_Justifiee, &existe_EnAttentJustificatif, &existe_NonJustifiee, &absences[i], date);
				++nb_absences;
			}
		}
		Etudiant* etudiant = &etudiants[identifiant - 1];
		afficher_absence(etudiant, nb_absence_total, date, absences);
		qsort(tab_indice_absences, nb_absences, sizeof(IndiceAbsence), comparer_absence); // Trier les absences via leurs indices et le tableau encapsul?

		if (existe_EnAttentJustificatif) {
			printf("- En attente justificatif\n");
			for (int i = 0; i < nb_absences; ++i) {
				Absence* absence = tab_indice_absences[i].absence;
				if ((absence->statu == EnAttenteJustificatif && ((date - absence->jour) <= 3)) || absence->justificatif.jour > date && ((date - absence->jour) <= 3)) {
					printf(" [%d] %d/%s\n", absence->identifiant, absence->jour, absence->journe == am ? "am" : "pm");
				}
			}
		}
		if (existe_EnAttentValidation) {
			// 2. Afficher "En attente validation"
			printf("- En attente validation\n");
			for (int i = 0; i < nb_absences; ++i) {
				Absence* absence_ = tab_indice_absences[i].absence;
				if ((absence_->statu == EnCoursDeTraitement && absence_->justificatif.jour <= date)) {
					printf(" [%d] %d/%s (%s)\n", absence_->identifiant, absence_->jour, absence_->journe == am ? "am" : "pm", absence_->justificatif.text_justificatif);
				}
			}
		}
		if (existe_Justifiee) {
			// 3. Afficher "Justifiees"
			printf("- Justifiees\n");
			for (int i = 0; i < nb_absences; ++i) {
				Absence* absence = tab_indice_absences[i].absence;
				if (absence->statu == Justifiee && absence->justificatif.jour <= date) {
					printf(" [%d] %d/%s (%s)\n", absence->identifiant, absence->jour, absence->journe == am ? "am" : "pm", absence->justificatif.text_justificatif);
				}
			}
		}
		// 4. Afficher "Non-justifiees"
		if (existe_NonJustifiee) {
			printf("- Non-justifiees\n");
			for (int i = 0; i < nb_absences; ++i) {
				Absence* absence = tab_indice_absences[i].absence;
				if (absence->statu == NonJustifiee || ((absence->statu == EnAttenteJustificatif) && (date - absence->jour > 3))) {
					printf(" [%d] %d/%s ", absence->identifiant, absence->jour, absence->journe == am ? "am" : "pm");
					printf(absence->justificatif.text_justificatif[0] == '\0' || absence->justificatif.jour > date? "\n" : "(%s)\n", absence->justificatif.text_justificatif);

				}
			}
		}
	}
}
//affiche les etudiant défaillants
void defaillants(int date, const Absence absences[], int nb_absence_total, const Etudiant etudiants[], int compt) {
	if (date < 1) {
		printf("Date incorrecte\n");
		return;
	}
	int exist_defaillants = 0;
	IndiceEtudiant tab_indice[NB_ETUDIANTS_MAX];
	for (int i = 0; i < compt; ++i) {
		tab_indice[i].indice = i;
		tab_indice[i].etudiant = &etudiants[i];  // Liaison avec l'étudiant
	}
	qsort(tab_indice, compt, sizeof(IndiceEtudiant), comparer_indice);
	for (int i = 0; i < compt; ++i) {
		int nb_absences = 0;
		Etudiant* etudiant = tab_indice[i].etudiant;
		for (int j = 0; j < nb_absence_total; ++j) {
			if ((absences[j].jour < date) &&
				((absences[j].identifiant_etudiant_concerne == etudiant->identifiant && absences[j].statu == NonJustifiee) ||
				(absences[j].identifiant_etudiant_concerne == etudiant->identifiant && absences[j].statu == EnAttenteJustificatif && date - absences[j].jour > 3) ||
				(absences[j].identifiant_etudiant_concerne == etudiant->identifiant && absences[j].statu == EnCoursDeTraitement && (absences[j].justificatif.jour > date) && (date - absences[j].jour > 3)))
				)
				++nb_absences;
		}
		if (nb_absences >= 5) {
			afficher_absence(etudiant, nb_absence_total, date, absences);
			exist_defaillants = 1;
		}
	}
	if (!exist_defaillants) {
		printf("Aucun defaillant\n");
		return;
	}
}

int main() {
	Etudiant etudiants[NB_ETUDIANTS_MAX];// Tableau pour stocker les ?tudiants inscrits
	Absence absences[MAX_ABSENCES]; // tableau pour stocker les absences
	unsigned int compt = 0;  // Compteur pour le nombre d'?tudiants inscrits actuellemrnt
	int nb_absence_total = 0; // Compteur pour le nombre d'absence
	char com[MAX_COMMANDE]; //	Pour stocker la commande entrée
	int iden, jour;  // stocker tous ce qui concerne jour et date
	char journe[3]; // stocker code de la  journé ( am ,pm ) 
	char validation_str[3]; // stocker code validation 
	char justificatif[MAX_JUSTIFICATIF]; // stocker les justificatifs
	while (1) {
		Etudiant etudiant;
		demande_commande(com);
		if (strcmp(com, "exit") == 0) {  // Si la commande est 'ex'
			printf("bl\n");
			break;
		}
		else if (strcmp(com, "inscription") == 0) {
			scanf(" %s %d", etudiant.nom, &etudiant.group); // Si la commande est 'inscription'
			inscriptionn(&etudiant, &compt, etudiants);  // Appel de la fonction d'inscription
		}
		else if (strcmp(com, "absence") == 0) {
			scanf(" %d %d %s", &iden, &jour, journe);
			DemiJourne demi_journe = string_to_DemiJourne(journe);
			abcense(iden, jour, demi_journe, etudiants, compt, &nb_absence_total, absences);

		}
		else if (strcmp(com, "etudiants") == 0) {
			scanf(" %d", &jour);
			triater_afficher_etudiants(jour, compt, etudiants, nb_absence_total, absences);
		}
		else if (strcmp(com, "justificatif") == 0) {
			scanf(" %d %d", &iden, &jour);
			saisieLigne(justificatif, MAX_JUSTIFICATIF);
			enregistrer_justificatif(iden, jour, justificatif, absences, nb_absence_total);

		}
		else if (strcmp(com, "validations") == 0) {
			lister_validations(etudiants, nb_absence_total, absences, compt);
		}
		else if (strcmp(com, "validation") == 0) {
			scanf("%d %s", &iden, validation_str);
			Validation code_validation = string_to_validation(validation_str);
			validation_absence(absences, iden, nb_absence_total, code_validation);
		}
		else if (strcmp(com, "etudiant") == 0) {
			scanf("%d %d", &iden, &jour);
			situation_etudiant(jour, iden, compt, etudiants, nb_absence_total, absences);
		}
		else if (strcmp(com, "defaillants") == 0) {
			scanf(" %d", &jour);
			defaillants(jour, absences, nb_absence_total, etudiants, compt);
		}

	}

	return 0;
}